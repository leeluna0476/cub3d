/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 13:17:10 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void	pixel_put(t_dot *dot, int color, t_info *info);
t_dot	*get_dot(int x, int y);
int	draw_line(t_line *line, t_info *info);
t_line	*get_line(t_dot *d1, t_dot *d2);
int	key_press_handler(int key, t_info *info);

int	worldMap[7][7] = {
							{1,1,1,1,1,1,1},
							{1,0,0,0,1,0,1},
							{1,0,1,0,1,0,1},
							{1,0,0,0,0,0,1},
							{1,0,0,0,0,1,1},
							{1,0,0,0,0,0,1},
							{1,1,1,1,1,1,1},
						};

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
				pixel_put(get_dot(x, y), COLOR_GRAY, info);
			else
				pixel_put(get_dot(x, y), color, info);
			x++;
		}
		y++;
	}
	free(dot_start);
	free(dot_end);
}

void	draw_2D_user(t_info *info, int gap_x, int gap_y)
{
	int	mid_x;
	int	mid_y;

	mid_x = (info->posX + 1) * gap_x / 2;
	mid_y = (info->posY + 1) * gap_y / 2;
	draw_box(get_dot(mid_x - 4, mid_y -4), get_dot(mid_x + 4, mid_y + 4), COLOR_BLUE, info);
	draw_line(get_line(get_dot(mid_x, mid_y), get_dot(mid_x + info->dirX * 30, mid_y + info->dirY * 30)), info);
}

void	draw_2D(t_info *info)
{
	double	gap_x;
	double	gap_y;
	int		x;
	int		y;

	gap_x = WIN_WID / MAP_WID;
	gap_y = WIN_HEI / MAP_HEI;
	y = 0;
	while (y < MAP_HEI)
	{
		x = 0;
		while (x < MAP_WID)
		{
			if (worldMap[y][x] != 0)
				draw_box(get_dot(x * gap_x, y * gap_y),
					get_dot((x + 1) * gap_x, (y + 1) * gap_y), COLOR_WHITE, info);
			else
				draw_box(get_dot(x * gap_x, y * gap_y),
					get_dot((x + 1) * gap_x, (y + 1) * gap_y), COLOR_BLACK, info);
			x++;
		}
		y++;
	}
	draw_2D_user(info, gap_x, gap_y);
}