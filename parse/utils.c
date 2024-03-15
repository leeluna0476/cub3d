/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:51:10 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/12 19:51:13 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

void	free_char_pp(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
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
}

void	if_error_exit(int exp)
{
	if (exp)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
