/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:54:20 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/13 15:36:11 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**merge_string(char **str, char *add)
{
	char	**new;
	int		i;

	if (!add)
		return (str);
	i = 0;
	while (str && str[i])
		i++;
	new = ft_calloc(i + 2, sizeof(char *));
	if (!new)
		exit(1);
	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = add;
	free(str);
	return (new);
}

char	**get_map_char(t_map *env, int map_fd)
{
	char	*line;
	char	**map;
	int		line_len;
	int		i;

	line = get_next_line(map_fd);
	map = NULL;
	i = 0;
	while (line)
	{
		line_len = ft_strlen(line) - 1;
		line[line_len] = '\0';
		if (line_len > env->width)
			env->width = line_len;
		map = merge_string(map, line);
		line = get_next_line(map_fd);
		(env->height)++;
	}
	return (map);
}

int	**get_map_int(char **cmap, int height, int width)
{
	int	**map;
	int		i;
	int		j;

	map = ft_calloc(height, sizeof(int *));
	if_error_exit(!map);
	j = 0;
	while (cmap[j])
	{
		i = 0;
		map[j] = ft_calloc(width, sizeof(int));
		if_error_exit(!(map[j]));
		while (cmap[j][i] && i < width)
		{
			map[j][i] = cmap[j][i];
			if (cmap[j][i] != ' ' && is_user(cmap[j][i]) == 0)
				map[j][i] -= '0';
			i++;
		}
		while (i < width)
		{
			map[j][i] = ' ';
			i++;
		}
		j++;
	}
	return (map);
}
