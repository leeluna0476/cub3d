/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:00:42 by yegkim            #+#    #+#             */
/*   Updated: 2023/12/05 15:02:14 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# elif BUFFER_SIZE <= 0
#  error "BUFFER_SIZE error"
# endif

typedef struct s_file
{
	int				fd;
	char			*save;
	char			buf[BUFFER_SIZE + 1];
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

#endif
