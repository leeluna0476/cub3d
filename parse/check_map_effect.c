/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_effect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:58 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/13 15:37:26 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_effective_char(int c)
{
	if (c == 1 || c == 0 || c == ' ' \
			|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (-1);
}

int	is_user(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (0);
}

void	check_map_effect(t_map *env)
{
	int	flag;
	int	**map;
	int	i;
	int	j;
	int	c;

	flag = 0;
	map = env->map;
	j = 0;
	while (j < env->height)
	{
		i = 0;
		while (i < env->width)
		{
			c = is_effective_char(map[j][i]);
			if_error_exit(c == -1);
			c = is_user(c);
			if_error_exit(c && flag);
			flag = c;
			i++;
		}
		j++;
	}
}
