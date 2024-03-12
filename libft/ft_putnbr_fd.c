/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:41:37 by yegkim            #+#    #+#             */
/*   Updated: 2023/10/16 12:52:40 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_int(int n, int fd)
{
	char	now;

	if (n > 0)
	{
		print_int(n / 10, fd);
		now = n % 10 + '0';
		write(fd, &now, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n <= -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		print_int(-n, fd);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
	}
	else
	{
		print_int(n, fd);
	}
}
