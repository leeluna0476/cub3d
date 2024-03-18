/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:24 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:32:09 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils.h"

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

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
