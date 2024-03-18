/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:35:45 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_press_handler.h"

int	go_front_back(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_W)
	{
		move_x = info->pos_x + info->dir_x * info->move_speed;
		if (0.1 <= move_x && move_x < (double)info->map->width - 0.1 && info->map->map[(int)(info->pos_y)][(int)(move_x)] != 1)
			info->pos_x = move_x;
		move_y = info->pos_y + info->dir_y * info->move_speed;
		if (0.1 <= move_y && move_y < (double)info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->pos_x)] != 1)
			info->pos_y = move_y;
	}
	if (key == K_S)
	{
		move_x = info->pos_x - info->dir_x * info->move_speed;
		if (0.1 <= move_x && (double)move_x <= info->map->width - 0.1 && info->map->map[(int)(info->pos_y)][(int)(move_x)] != 1)
			info->pos_x = move_x;
		move_y = info->pos_y - info->dir_y * info->move_speed;
		if (0.1 <= move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->pos_x)] != 1)
			info->pos_y = move_y;
	}
	return (0);
}

int	go_left_right(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_A)
	{
		move_x = info->pos_x + info->dir_y * info->move_speed;
		if (0.1 <= (int)move_x && (double)move_x < info->map->width - 0.1 && info->map->map[(int)(info->pos_y)][(int)(move_x)] != 1)
			info->pos_x = move_x;
		move_y = info->pos_y - info->dir_x * info->move_speed;
		if (0.1 <= (int)move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->pos_x)] != 1)
			info->pos_y = move_y;
	}
	if (key == K_D)
	{
		move_x = info->pos_x - info->dir_y * info->move_speed;
		if (0.1 <= move_x && (double)move_x < info->map->width - 0.1 && info->map->map[(int)(info->pos_y)][(int)(move_x)] != 1)
			info->pos_x = move_x;
		move_y = info->pos_y + info->dir_x * info->move_speed;
		if (0.1 <= (int)move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->pos_x)] != 1)
			info->pos_y = move_y;
	}
	return (0);
}

void	change_dir_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x
		= info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
	info->dir_y
		= old_dir_x * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-info->rot_speed) \
		- info->plane_y * sin(-info->rot_speed);
	info->plane_y = old_plane_x * sin(-info->rot_speed) \
			+ info->plane_y * cos(-info->rot_speed);
}

void	change_dir_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	info->dir_x
		= info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
	info->dir_y
		= old_dir_x * sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(info->rot_speed) \
			- info->plane_y * sin(info->rot_speed);
	info->plane_y = old_plane_x * sin(info->rot_speed) \
		+ info->plane_y * cos(info->rot_speed);
}

int	key_press_handler(int key, t_info *info)
{
	if (key == K_W || key == K_S)
		go_front_back(key, info);
	if (key == K_A || key == K_D)
		go_left_right(key, info);
	if (key == K_AR_L)
		change_dir_left(info);
	if (key == K_AR_R)
		change_dir_right(info);
	if (key == K_ESC)
		exit(0);
	mlx_destroy_image(info->mlx, info->img);
	make_image_put_window(info, draw_3d);
	return (0);
}
