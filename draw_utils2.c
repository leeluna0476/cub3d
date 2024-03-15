/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:24 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 11:38:45 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils2.h"

void	pixel_put(t_dot *dot, int color, t_info *info)
{
	char		*dst;
	t_image		*image;

	image = info->img;
	if (dot->x < 0 || dot->y < 0 || dot->x >= WIN_WID || dot->y >= WIN_HEI)
	{
		free(dot);
		return ;
	}
	dst = image->addr + (dot->y * image->line_length
			+ dot->x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	free(dot);
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
