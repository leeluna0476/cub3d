/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:51:03 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/13 13:32:02 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

void	insert_value_flag(char **ptr, char *value, int *flag)
{
	*ptr = value;
	*flag = 1;
}

void	insert_color_flag(int *ptr, int color[3], int *flag)
{
	*ptr = color[0] | color[1] | color[2];
	*flag = 1;
}

void	insert_texture(t_map *env, char *line, int flag[6])
{
	char	type;
	char	*value;

	type = line[0];
	if_error_exit((type == 'N' && flag[0]) || (type == 'S' && flag[1]) \
		|| (type == 'W' && flag[2]) || (type == 'E' && flag[3]));
	value = ft_strdup(line + 3);
	if (value)
		value[ft_strlen(value) - 1] = '\0';
	if (type == 'N')
		insert_value_flag(&(env->north), value, &(flag[0]));
	else if (type == 'S')
		insert_value_flag(&(env->south), value, &(flag[1]));
	else if (type == 'W')
		insert_value_flag(&(env->west), value, &(flag[2]));
	else
		insert_value_flag(&(env->east), value, &(flag[3]));
}

void	insert_color(t_map *env, char *line, int flag[6])
{
	char	type;
	char	**rgb;
	int		color[3];
	int		i;

	type = line[0];
	line[ft_strlen(line) - 1] = '\0';
	if_error_exit((type == 'F' && flag[4]) || (type == 'C' && flag[5]));
	rgb = ft_split(line + 2, ',');
	if (rgb)
	{
		i = 0;
		while (rgb[i] && i < 3)
		{
			color[i] = ft_atoi(rgb[i]);
			if_error_exit(color[i] < 0 || color[i] > 255);
			i++;
		}
		if_error_exit(rgb[i] || i < 3);
		if (type == 'F')
			insert_color_flag(&(env->floor), color, &(flag[4]));
		else if (type == 'C')
			insert_color_flag(&(env->ceiling), color, &(flag[5]));
	}
	free_char_pp(rgb);
}

// no, so, we, ea, f, c
void	parse_texture(t_map *env, int map_fd)
{
	char	*line;
	int		texture_flag[6];
	int		flag;

	ft_memset(texture_flag, 0, sizeof(int) * 6);
	line = get_next_line(map_fd);
	flag = (is_direction(line) || is_color(line));
	while (line && flag)
	{
		if (is_direction(line))
			insert_texture(env, line, texture_flag);
		else if (is_color(line))
			insert_color(env, line, texture_flag);
		free(line);
		line = get_next_line(map_fd);
		flag = (is_direction(line) || is_color(line));
	}
	free(line);
	if_error_exit(!is_raised(texture_flag));
}
