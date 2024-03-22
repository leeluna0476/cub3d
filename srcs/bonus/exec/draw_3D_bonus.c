/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 16:53:30 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_3d_bonus.h"

void	draw_floor_ceiling(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEI / 2)
	{
		x = 0;
		while (x < WIN_WID)
		{
			pixel_put(x, y, info->map->ceiling, info);
			x++;
		}
		y++;
	}

	while (y < WIN_HEI)
	{
		x = 0;
		while (x < WIN_WID)
		{
			pixel_put(x, y, info->map->floor, info);
			x++;
		}
		y++;
	}
}

void	draw_3d(t_info	*info)
{
	int		x;
	t_cal	*cal;

	draw_floor_ceiling(info);
	x = 0;
	while (x < WIN_WID)
	{
		cal = init_cal(cal, x, info);
		exec_dda(cal, info);
		draw_raycast(cal, info);
		free(cal);
		x++;
	}
	draw_mini_map(info);
}
