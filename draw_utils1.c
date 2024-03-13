/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:24 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 11:35:18 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils1.h"

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_dot	*get_dot(int x, int y)
{
	t_dot	*dot;

	dot = (t_dot *)malloc(sizeof(t_dot));
	if (!dot)
		return (0);
	dot->x = x;
	dot->y = y;
	return (dot);
}

t_line	*get_line(t_dot *d1, t_dot *d2)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (0);
	line->dot_start = d1;
	line->dot_end = d2;
	line->height = ft_abs(d2->y - d1->y);
	line->width = ft_abs(d2->x - d1->x);
	return (line);
}
