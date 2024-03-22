/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:02:21 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/16 13:28:54 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_print_char(va_list ap);
int	ft_print_str(va_list ap);
int	ft_print_int(va_list ap);
int	ft_print_unint(va_list ap);
int	ft_print_hexsm(va_list ap);
int	ft_print_hexlg(va_list ap);
int	ft_print_ptr(va_list ap);
int	ft_print_per(void);
int	ft_print_conversion(char chr, va_list ap);
int	ft_printf(const char *format, ...);

#endif
