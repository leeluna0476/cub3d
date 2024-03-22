/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:44:33 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 16:53:30 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

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
		env->user_dir = map[row][col];
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
