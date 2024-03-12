/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:44:15 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/16 13:27:12 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	print_or_conversion(va_list ap, const char **format_p, int *len_p)
{
	int		ret;

	if (**format_p == '%')
	{
		(*format_p)++;
		ret = ft_print_conversion(**format_p, ap);
		if (ret < 0)
			return (ret);
		*len_p += ret;
	}
	else
	{
		if (write(1, *format_p, 1) < 0)
			return (-1);
		(*len_p)++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (format && *format)
	{
		if (print_or_conversion(ap, &format, &len) == -1)
			return (-1);
		format++;
	}
	va_end(ap);
	return (len);
}
