/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:51:03 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/21 16:52:37 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	insert_value_flag(char **ptr, char *value, int *flag)
{
	*ptr = value;
	*flag = 1;
}

void	insert_color_flag(int *ptr, int color[3], int *flag)
{
	*ptr = color[0] << 16 | color[1] << 8 | color[2];
	*flag = 1;
}

void	insert_texture(t_map *env, char *line, int flag[6])
{
	char	type;
	char	*value;
	char	**split;
	int		fd;

	split = ft_split(line, ' ');
	if_error_exit(!split);
	type = split[0][0];
	if_error_exit(split[2] \
		|| (type == 'N' && flag[0]) || (type == 'S' && flag[1]) \
		|| (type == 'W' && flag[2]) || (type == 'E' && flag[3]));
	value = ft_strdup(split[1]);
	value[ft_strlen(value) - 1] = '\0';
	fd = open(value, O_RDONLY);
	if_error_exit(!value || fd == -1);
	close(fd);
	if (type == 'N')
		insert_value_flag(&(env->north), value, &(flag[0]));
	else if (type == 'S')
		insert_value_flag(&(env->south), value, &(flag[1]));
	else if (type == 'W')
		insert_value_flag(&(env->west), value, &(flag[2]));
	else
		insert_value_flag(&(env->east), value, &(flag[3]));
	free_cpptr(split);
}

int	check_comma(char *line)
{
	char	*find;
	int		count;

	count = 0;
	find = ft_strchr(line, ',');
	while (find != NULL)
	{
		if (count > 2)
			break ;
		count++;
		find++;
		find = ft_strchr(find, ',');
	}
	if (count != 2)
		return (-1);
	return (0);
}

void	insert_color(t_map *env, char *line, int flag[6])
{
	char	type;
	char	**rgb;
	int		color[3];
	int		i;

	type = line[0];
	line[ft_strlen(line) - 1] = '\0';
	rgb = ft_split(line + 2, ',');
	if_error_exit(!rgb \
			|| (type == 'F' && flag[4]) || (type == 'C' && flag[5]) \
			|| check_comma(line) == -1);
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
	free_cpptr(rgb);
}

// no, so, we, ea, f, c
void	parse_texture(t_map *env, int map_fd)
{
	char	*line;
	int		texture_flag[6];
	int		flag;

	ft_memset(texture_flag, 0, sizeof(int) * 6);
	line = get_next_line(map_fd);
	flag = (line && \
			(is_direction(line) || is_color(line) || is_empty(line)));
	while (flag)
	{
		if (is_direction(line))
			insert_texture(env, line, texture_flag);
		else if (is_color(line))
			insert_color(env, line, texture_flag);
		free(line);
		if (is_raised(texture_flag))
			break ;
		line = get_next_line(map_fd);
		flag = (line && \
				(is_direction(line) || is_color(line) || is_empty(line)));
	}
	if_error_exit(!is_raised(texture_flag));
}
