/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexsm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:34:25 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/24 16:23:41 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
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
		num /= 16;
		cnt++;
	}
	return (cnt);
}

static char	*ft_itoa_hexsm(unsigned int n)
{
	char	*result;
	int		space_cnt;
	char	*hex_char;

	space_cnt = get_space_cnt(n);
	result = malloc(sizeof(char) * (space_cnt + 1));
	if (!result)
		return (0);
	result[space_cnt] = '\0';
	if (n == 0)
		result[0] = '0';
	hex_char = "0123456789abcdef";
	while (n > 0)
	{
		space_cnt--;
		result[space_cnt] = hex_char[n % 16];
		n /= 16;
	}
	return (result);
}

int	ft_print_hexsm(va_list ap)
{
	int		num;
	char	*numstr;
	int		ret;

	num = va_arg(ap, unsigned int);
	numstr = ft_itoa_hexsm(num);
	if (!numstr)
		return (-1);
	ret = write(1, numstr, ft_strlen(numstr));
	free(numstr);
	return (ret);
}
