/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:53:28 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/08 12:14:27 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_space_cnt(unsigned int n)
{
	int			cnt;
	long long	num;

	cnt = 0;
	num = (long long)n;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_unitoa(unsigned int n)
{
	char	*result;
	int		space_cnt;

	space_cnt = get_space_cnt(n);
	result = malloc(sizeof(char) * (space_cnt + 1));
	if (!result)
		return (0);
	result[space_cnt] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		space_cnt--;
		result[space_cnt] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
