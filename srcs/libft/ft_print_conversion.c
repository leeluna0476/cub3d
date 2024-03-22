/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:45:11 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/16 13:27:17 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_string_set(char chr, va_list ap)
{
	int	ret;

	ret = -1;
	if (chr == 'c')
		ret = ft_print_char(ap);
	else if (chr == 's')
		ret = ft_print_str(ap);
	else if (chr == '%')
		ret = ft_print_per();
	return (ret);
}

static int	ft_print_num_set(char chr, va_list ap)
{
	int	ret;

	ret = -1;
	if (chr == 'd' || chr == 'i')
		ret = ft_print_int(ap);
	else if (chr == 'u')
		ret = ft_print_unint(ap);
	return (ret);
}

static int	ft_print_hex_set(char chr, va_list ap)
{
	int	ret;

	ret = -1;
	if (chr == 'p')
		ret = ft_print_ptr(ap);
	else if (chr == 'x')
		ret = ft_print_hexsm(ap);
	else if (chr == 'X')
		ret = ft_print_hexlg(ap);
	return (ret);
}

int	ft_print_conversion(char chr, va_list ap)
{
	int	ret;

	ret = -1;
	if (chr == 'c' || chr == 's' || chr == '%')
	{
		ret = ft_print_string_set(chr, ap);
		if (ret <= 0)
			return (ret);
	}
	else if (chr == 'd' || chr == 'i' || chr == 'u')
	{
		ret = ft_print_num_set(chr, ap);
		if (ret <= 0)
			return (ret);
	}
	else if (chr == 'p' || chr == 'x' || chr == 'X')
	{
		ret = ft_print_hex_set(chr, ap);
		if (ret <= 0)
			return (ret);
	}
	return (ret);
}
