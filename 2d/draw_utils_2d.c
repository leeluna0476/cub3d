/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:24 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 12:44:35 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils_2d.h"

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


void	align_dot_start(int flag_y, t_line *line)
{
	t_dot	*tmp;

	if (flag_y == 0)
	{
		if (line->dot_start->x > line->dot_end->x)
		{
			tmp = line->dot_start;
			line->dot_start = line->dot_end;
			line->dot_end = tmp;
		}
	}
	else
	{
		if (line->dot_start->y > line->dot_end->y)
		{
			tmp = line->dot_start;
			line->dot_start = line->dot_end;
			line->dot_end = tmp;
		}
	}
}
