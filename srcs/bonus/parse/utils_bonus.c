/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:51:10 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 17:26:39 by seojilee         ###   ########.fr       */
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
