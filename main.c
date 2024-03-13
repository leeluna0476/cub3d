/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:42:59 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 15:04:29 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parse/parse.h"

int	exec_cub(char **av);

void	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("argument number error\n");
	exec_cub(argv);
	return (0);
}
