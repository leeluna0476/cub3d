/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_effect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:58 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/13 18:02:34 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_char_effect(int data, int flag)
{
	int	c;
	int	u;

	c = is_effective_char(data);
	if_error_exit(c == -1);
	c = is_user(c);
	if_error_exit(c && flag);
	return (c);
}

int	is_filled(int *line, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (line[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	dfs(int	**map, int col, int row, int w_h[2])
{
	if (col < 0 || row < 0 \
			|| col >= w_h[0] || row >= w_h[1])
		return (0);
	if (!col)
	{
		while (map[row][col] == ' ')
			col++;
	}
	if (map[row][col] == 0)
	{
		printf("%d", map[row][col]);
		map[row][col] = 1;
		dfs(map, col, row - 1, w_h);
		dfs(map, col + 1, row, w_h);
		dfs(map, col, row + 1, w_h);
		dfs(map, col - 1, row, w_h);
		return (1);
	}
	if (map[row][col] == 1)
	{
	}
//	else if (map[row][col] != 1)
//		return (0);
	return (0);
}

void	check_map_effect(t_map *env)
{
	int	**map;
	int	**temp_map;
	int	w_h[2];
	int	i;
	int	j;

//	flag = 0;
	map = env->map;
	temp_map = ft_calloc(env->height, sizeof(int *));
	if_error_exit(!temp_map);
	j = 0;
	while (j < env->height)
	{
		temp_map[j] = ft_calloc(env->width, sizeof(int));
		if_error_exit(!(temp_map[j]));
		i = 0;
		while (i < env->width)
		{
//			flag = check_char_effect(map[j][i], flag);
			temp_map[j][i] = map[j][i];
			i++;
		}
		j++;
	}
	w_h[0] = env->width;
	w_h[1] = env->height;
	if_error_exit(!is_filled(temp_map[0], env->width) || !is_filled(temp_map[env->height - 1], env->width));
	if_error_exit(!dfs(temp_map, 0, 1, w_h));
}
