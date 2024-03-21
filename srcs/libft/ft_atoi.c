/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:21:52 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/12 20:30:14 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	check_space_sign(const char *str, int *sign, int *cutlim)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	*sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
		{
			*sign = -1;
			(*cutlim)++;
		}
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned int		ret_num;
	const unsigned int	cutoff = ~((int) 1 << ((sizeof(int) * 8) - 1)) / 10;
	int					cutlim;

	if (!str)
		return (-1);
	cutlim = ~((int) 1 << ((sizeof(int) * 8) - 1)) % 10;
	i = check_space_sign(str, &sign, &cutlim);
	ret_num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ret_num > cutoff || (ret_num == cutoff && (str[i] - '0') > cutlim))
			return (-1);
		ret_num = (ret_num * 10) + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)ret_num * sign);
}

long	ft_atol(const char *str)
{
	int					i;
	int					sign;
	unsigned long		ret_num;
	const unsigned long	cutoff = ~((long) 1 << ((sizeof(long) * 8) - 1)) / 10;
	int					cutlim;

	if (!str)
		return (-1);
	cutlim = ~((long) 1 << ((sizeof(long) * 8) - 1)) % 10;
	i = check_space_sign(str, &sign, &cutlim);
	ret_num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ret_num > cutoff || (ret_num == cutoff && (str[i] - '0') > cutlim))
			return (-1);
		ret_num = (ret_num * 10) + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (-1);
	return ((long)ret_num * sign);
}
