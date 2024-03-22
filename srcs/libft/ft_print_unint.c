/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:26 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/24 16:23:57 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_unint(va_list ap)
{
	unsigned int	num;
	char			*numstr;
	int				ret;

	num = va_arg(ap, unsigned int);
	numstr = ft_unitoa(num);
	if (!numstr)
		return (-1);
	ret = write(1, numstr, ft_strlen(numstr));
	free(numstr);
	return (ret);
}
