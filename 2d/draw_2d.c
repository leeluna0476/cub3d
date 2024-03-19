/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/19 11:57:43 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../structs.h"

void	pixel_put(int x, int y, int color, t_info *info);
t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
int		key_press_handler(int key, t_info *info);
void	draw_2D_ray(t_info	*info);

void	draw_box(t_dot *dot_start, t_dot *dot_end, int color, t_info *info)
{
	int	y;
	int	x;

	y = dot_start->y;
	while (y < dot_end->y)
	{
		x = dot_start->x;
		while (x < dot_end->x)
		{
			if (x == dot_start->x || y == dot_start->y)
				pixel_put(x, y, COLOR_GRAY, info);
			else
				pixel_put(x, y, color, info);
			x++;
		}
		y++;
	}
	free(dot_start);
	free(dot_end);
}

void	draw_2D_user(t_info *info, double gap_x, double gap_y)
{
	int	mid_x;
	int	mid_y;

	mid_x = info->user->pos_x * gap_x;
	mid_y = info->user->pos_y * gap_y;
	draw_box(get_dot(mid_x - 4, mid_y -4), get_dot(mid_x + 4, mid_y + 4), COLOR_BLUE, info);
	draw_line(get_line(get_dot(mid_x, mid_y), get_dot(mid_x + info->user->dir_x * 30, mid_y + info->user->dir_y * 30)), info, COLOR_RED);
}
void	draw_cam(t_info *info)
{
	double	gap_x;
	double	gap_y;

	gap_x = (double)WIN_WID / (double)info->map->width;
	gap_y = (double)WIN_HEI / (double)info->map->height;
	draw_line(get_line(get_dot((info->user->pos_x + info->user->dir_x - info->user->plane_x) * gap_x, (info->user->pos_y + info->user->dir_y - info->user->plane_y) * gap_y)
	, get_dot((info->user->pos_x + info->user->dir_x + info->user->plane_x) * gap_x, (info->user->pos_y + info->user->dir_y + info->user->plane_y) * gap_y)), info, COLOR_GREEN);
}

void	draw_2d(t_info *info)
{
	double	gap_x;
	double	gap_y;
	int		x;
	int		y;
	int		color;

	gap_x = (double)WIN_WID / info->map->width;
	gap_y = (double)WIN_HEI / info->map->height;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if ((info->map->map)[y][x] == 0 || (info->map->map)[y][x] == 'N')
				color = COLOR_BLACK;
			else if ((info->map->map)[y][x] == 1)
				color = COLOR_WHITE;
			else
				color = COLOR_GRAY;
			draw_box(get_dot(x * gap_x, y * gap_y),
				get_dot((x + 1) * gap_x, (y + 1) * gap_y), color, info);
			x++;
		}
		y++;
	}
	draw_2D_user(info, gap_x, gap_y);
	draw_2D_ray(info);
	draw_cam(info);
}
