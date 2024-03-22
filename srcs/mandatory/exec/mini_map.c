/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 17:21:24 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_map.h"

int	get_mini_color(int map_num)
{
	if (map_num == 1)
		return (COLOR_WHITE);
	if (map_num == ' ')
		return (COLOR_GRAY);
	return (COLOR_BLACK);
}

void	draw_mini_box(t_dot *dot_start, t_dot *dot_end, int color, t_info *info)
{
	int	y;
	int	x;

	y = dot_start->y;
	while (y < dot_end->y)
	{
		x = dot_start->x;
		while (x < dot_end->x)
		{
			pixel_put(WIN_WID / 5 * 4 + x - 10, y + 10, color, info);
			x++;
		}
		y++;
	}
	free(dot_start);
	free(dot_end);
}

void	draw_mini_user(t_info *info, double gap_x, double gap_y)
{
	int	mid_x;
	int	mid_y;

	mid_x = info->user->pos_x * gap_x;
	mid_y = info->user->pos_y * gap_y;
	draw_mini_box(get_dot(mid_x - 4, mid_y -4),
		get_dot(mid_x + 4, mid_y + 4), COLOR_GREEN, info);
}

void	draw_mini_map(t_info *info)
{
	double	gap_x;
	double	gap_y;
	int		x;
	int		y;

	gap_x = (double)WIN_WID / info->map->width / 5;
	gap_y = (double)WIN_HEI / info->map->height / 5;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			draw_mini_box(get_dot(x * gap_x, y * gap_y),
				get_dot((x + 1) * gap_x, (y + 1) * gap_y),
				get_mini_color(info->map->map[y][x]), info);
			x++;
		}
		y++;
	}
	draw_mini_user(info, gap_x, gap_y);
}
