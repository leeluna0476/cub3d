/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:58 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/15 14:45:29 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	dfs(int **map, t_map *env)
{
	int	i;
	int	j;

	j = 0;
	while (j < env->height)
	{
		i = 0;
		while (i < env->width)
		{
			while (map[j][i] == ' ')
				i++;
			if (i < env->width && map[j][i] != 1)
			{
				search(map, i, j, env);
				if_error_exit(env->flag);
			}
			i++;
		}
		j++;
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
