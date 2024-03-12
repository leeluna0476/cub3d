/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:34:25 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/24 16:23:49 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	get_space_cnt(unsigned long long num)
{
	int			cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

static char	*ft_itoa_for_ptr(unsigned long long n)
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

int	ft_print_ptr(va_list ap)
{
	unsigned long long	ptr_num;
	char				*numstr;
	int					len;
	int					ret;

	ptr_num = (unsigned long long)va_arg(ap, void *);
	numstr = ft_itoa_for_ptr((ptr_num));
	if (!numstr)
		return (-1);
	len = write(1, "0x", 2);
	if (len == -1)
	{
		free(numstr);
		return (-1);
	}
	ret = write(1, numstr, ft_strlen(numstr));
	len += ret;
	free(numstr);
	if (ret == -1)
		return (-1);
	return (len);
}
