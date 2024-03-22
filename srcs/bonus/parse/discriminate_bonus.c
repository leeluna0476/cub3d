/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:49 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 16:53:30 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

int	is_direction(char *line)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	if_error_exit(!split);
	ret = (!ft_strncmp(split[0], "NO", ft_strlen(split[0])) \
			|| !ft_strncmp(split[0], "SO", ft_strlen(split[0])) \
			|| !ft_strncmp(split[0], "WE", ft_strlen(split[0])) \
			|| !ft_strncmp(split[0], "EA", ft_strlen(split[0])));
	free_cpptr(split);
	return (ret);
}

int	is_color(char *line)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	ret = (!ft_strncmp(split[0], "F", ft_strlen(split[0])) \
				|| !ft_strncmp(split[0], "C", ft_strlen(split[0])));
	free_cpptr(split);
	return (ret);
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

int	is_user(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (c);
	return (0);
}

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
