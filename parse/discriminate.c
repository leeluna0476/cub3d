/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:49 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/12 19:51:45 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

int	is_direction(char *line)
{
	return (ft_strnstr(line, "NO ", 3) \
			|| ft_strnstr(line, "SO ", 3) \
			|| ft_strnstr(line, "WE ", 3) \
			|| ft_strnstr(line, "EA ", 3));
}

int	is_color(char *line)
{
	return (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2));
}

int	is_raised(int flag[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!flag[i])
			return (0);
		i++;
	}
	return (1);
}
