/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_go_wasd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 16:53:07 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_press_handler_bonus.h"

int	check_can_go(double x, double y, t_info *info)
{
	if (x <= 0.1 || x > (double)info->map->width - 0.1)
		return (0);
	if (y <= 0.1 || y > (double)info->map->height - 0.1)
		return (0);
	if (info->map->map[(int)(y - 0.1)][(int)(x - 0.1)] == 1)
		return (0);
	if (info->map->map[(int)(y - 0.1)][(int)(x + 0.1)] == 1)
		return (0);
	if (info->map->map[(int)(y + 0.1)][(int)(x - 0.1)] == 1)
		return (0);
	if (info->map->map[(int)(y + 0.1)][(int)(x + 0.1)] == 1)
		return (0);
	return (1);
}

int	go_front_back(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_W)
	{
		move_x = info->user->pos_x + info->user->dir_x * info->user->move_sp;
		if (check_can_go(move_x, info->user->pos_y, info))
			info->user->pos_x = move_x;
		move_y = info->user->pos_y + info->user->dir_y * info->user->move_sp;
		if (check_can_go(info->user->pos_x, move_y, info))
			info->user->pos_y = move_y;
	}
	if (key == K_S)
	{
		move_x = info->user->pos_x - info->user->dir_x * info->user->move_sp;
		if (check_can_go(move_x, info->user->pos_y, info))
			info->user->pos_x = move_x;
		move_y = info->user->pos_y - info->user->dir_y * info->user->move_sp;
		if (check_can_go(info->user->pos_x, move_y, info))
			info->user->pos_y = move_y;
	}
	return (0);
}

int	go_left_right(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_A)
	{
		move_x = info->user->pos_x + info->user->dir_y * info->user->move_sp;
		if (check_can_go(move_x, info->user->pos_y, info))
			info->user->pos_x = move_x;
		move_y = info->user->pos_y - info->user->dir_x * info->user->move_sp;
		if (check_can_go(info->user->pos_x, move_y, info))
			info->user->pos_y = move_y;
	}
	if (key == K_D)
	{
		move_x = info->user->pos_x - info->user->dir_y * info->user->move_sp;
		if (check_can_go(move_x, info->user->pos_y, info))
			info->user->pos_x = move_x;
		move_y = info->user->pos_y + info->user->dir_x * info->user->move_sp;
		if (check_can_go(info->user->pos_x, move_y, info))
			info->user->pos_y = move_y;
	}
	return (0);
}
