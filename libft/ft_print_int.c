/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:42:46 by yegkim            #+#    #+#             */
/*   Updated: 2023/11/24 16:23:44 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_int(va_list ap)
{
	int		num;
	char	*numstr;
	int		ret;

	num = va_arg(ap, int);
	numstr = ft_itoa(num);
	if (!numstr)
		return (-1);
	ret = write(1, numstr, ft_strlen(numstr));
	free(numstr);
	return (ret);
}
