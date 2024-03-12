/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:53:28 by yegkim            #+#    #+#             */
/*   Updated: 2023/10/18 13:15:58 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_space_cnt(int n)
{
	int			cnt;
	long long	num;

	cnt = 0;
	num = (long long)n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= (-1);
		cnt++;
	}
	while (num > 0)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		space_cnt;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	space_cnt = get_space_cnt(n);
	result = malloc(sizeof(char) * (space_cnt + 1));
	if (!result)
		return (0);
	result[space_cnt] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		n *= (-1);
	}
	while (n > 0)
	{
		space_cnt--;
		result[space_cnt] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
