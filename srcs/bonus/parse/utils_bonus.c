/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:51:10 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 16:53:20 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal_bonus.h"

void	free_cpptr(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_ipptr(int **ptr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_env(t_map *env)
{
	free(env->north);
	free(env->south);
	free(env->west);
	free(env->east);
	free_ipptr(env->map, env->height);
	free(env);
}

void	if_error_exit(int exp)
{
	if (exp)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
