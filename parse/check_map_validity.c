/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:58 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/15 13:43:36 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_position(int **map, int col, int row, t_map *env)
{
	if (col < 0 || row < 0 \
			|| col > env->width - 1 || row > env->height - 1)
	{
		return (1);
	}
	else if (((row == 0 || row == env->height - 1) \
			|| (col == 0 || col == env->width - 1)) \
			&& (col < env->width && map[row][col] != 1))
	{
		return (1);
	}
	return (0);
}

void	if_user(int	**map, int col, int row, t_map *env)
{
	if (env->user[0] == -1)
	{
		env->user[0] = row;
		env->user[1] = col;
		recur(map, col, row, env);
	}
	else if (row != env->user[0] || col != env->user[1])
		env->flag = 1;
}

void	search(int **map, int col, int row, t_map *env)
{
	if (env->flag)
		return ;
	if (check_position(map, col, row, env))
		env->flag = 1;
	else if (map[row][col] == 0)
	{
		map[row][col] = 1;
		recur(map, col, row, env);
	}
	else if (is_user(map[row][col]))
		if_user(map, col, row, env);
	else if (map[row][col] != 1)
		env->flag = 1;
}

void	recur(int **map, int col, int row, t_map *env)
{
	search(map, col, row - 1, env);
	search(map, col + 1, row, env);
	search(map, col, row + 1, env);
	search(map, col - 1, row, env);
}

void	dfs(int **map, t_map *env)
{
	for (int j = 0; j < env->height; j++)
	{
		for (int i = 0; i < env->width; i++)
		{
			while (map[j][i] == ' ')
				i++;
			if (i >= env->width || map[j][i] == 1)
				continue ;
			search(map, i, j, env);
			if_error_exit(env->flag);
		}
	}
}

void	check_map_validity(t_map *env)
{
	int	**map;
	int	**temp_map;
	int	i;
	int	j;

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
			temp_map[j][i] = map[j][i];
			i++;
		}
		j++;
	}
	dfs(temp_map, env);
	free_ipptr(temp_map, env->height);
	if_error_exit(env->user[0] == -1);
}
