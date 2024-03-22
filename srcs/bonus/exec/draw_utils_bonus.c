/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:24 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 16:53:05 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils_bonus.h"

void	pixel_put(int x, int y, int color, t_info *info)
{
	char		*dst;
	t_image		*image;

	image = info->img;
	if (x < 0 || y < 0 || x >= WIN_WID || y >= WIN_HEI)
		return ;
	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
