/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:23:49 by yegkim            #+#    #+#             */
/*   Updated: 2023/12/06 15:54:23 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atol(const char *str)
{
	long long	minus;
	long long	answer;

	minus = 1;
	answer = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		answer *= 10;
		answer += (*str - '0');
		str++;
	}
	return (answer * minus);
}
