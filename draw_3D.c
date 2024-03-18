/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:33:38 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_3d.h"

void	init_side_dist_and_step(t_cal *cal, t_info *info)
{
	if (cal->ray_dir_x < 0)
	{
		cal->step_x = -1;
		cal->side_dist_x = (info->pos_x - cal->map_x) * cal->delta_dist_x;
	}
	else
	{
		cal->step_x = 1;
		cal->side_dist_x
			= (double)(cal->map_x + 1.0 - info->pos_x) * cal->delta_dist_x;
	}
	if (cal->ray_dir_y < 0)
	{
		cal->step_y = -1;
		cal->side_dist_y = (info->pos_y - cal->map_y) * cal->delta_dist_y;
	}
	else
	{
		cal->step_y = 1;
		cal->side_dist_y
			= (double)(cal->map_y + 1.0 - info->pos_y) * cal->delta_dist_y;
	}
}

t_cal	*init_cal(t_cal *cal, int x, t_info *info)
{
	cal = (t_cal *)null_guard(malloc(sizeof(t_cal)));
	cal->x = x;
	cal->ray_dir_x = info->dir_x
		+ info->plane_x * (2 * (double)cal->x / (double)(WIN_WID) - 1);
	cal->ray_dir_y = info->dir_y
		+ info->plane_y * (2 * (double)cal->x / (double)(WIN_WID) - 1);
	cal->map_x = (int)info->pos_x;
	cal->map_y = (int)info->pos_y;
	cal->delta_dist_x = fabs(1 / cal->ray_dir_x);
	cal->delta_dist_y = fabs(1 / cal->ray_dir_y);
	init_side_dist_and_step(cal, info);
	return (cal);
}

void	get_ray_dist_and_line_hei(t_cal *cal, t_info *info)
{
	if (cal->side == 0)
	{
		cal->ray_dist = (cal->map_x - info->pos_x + (1 - cal->step_x) / 2)
			/ cal->ray_dir_x;
	}
	else
	{
		cal->ray_dist = (cal->map_y - info->pos_y + (1 - cal->step_y) / 2)
			/ cal->ray_dir_y;
	}
	if (cal->ray_dist == 0)
		cal->line_hei = WIN_HEI;
	else
		cal->line_hei = (int)(WIN_HEI / cal->ray_dist);
}

void	exec_dda(t_cal *cal, t_info *info)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cal->side_dist_x < cal->side_dist_y)
		{
			cal->side_dist_x += cal->delta_dist_x;
			cal->map_x += cal->step_x;
			cal->side = 0;
		}
		else
		{
			cal->side_dist_y += cal->delta_dist_y;
			cal->map_y += cal->step_y;
			cal->side = 1;
		}
		if (info->map->map[cal->map_y][cal->map_x] == 1)
			hit = 1;
	}
	get_ray_dist_and_line_hei(cal, info);
}

void	draw_3d(t_info	*info)
{
	int		x;
	t_cal	*cal;

	x = 0;
	while (x < WIN_WID)
	{
		cal = init_cal(cal, x, info);
		exec_dda(cal, info);
		draw_raycast(cal, info);
		x++;
	}
}
