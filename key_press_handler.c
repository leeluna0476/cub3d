/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/19 11:52:49 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_press_handler.h"

int	go_front_back(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_W)
	{
		move_x = info->user->pos_x + info->user->dir_x * info->user->move_speed;
		if (0.1 <= move_x && move_x < (double)info->map->width - 0.1 && info->map->map[(int)(info->user->pos_y)][(int)(move_x)] != 1)
			info->user->pos_x = move_x;
		move_y = info->user->pos_y + info->user->dir_y * info->user->move_speed;
		if (0.1 <= move_y && move_y < (double)info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->user->pos_x)] != 1)
			info->user->pos_y = move_y;
	}
	if (key == K_S)
	{
		move_x = info->user->pos_x - info->user->dir_x * info->user->move_speed;
		if (0.1 <= move_x && (double)move_x <= info->map->width - 0.1 && info->map->map[(int)(info->user->pos_y)][(int)(move_x)] != 1)
			info->user->pos_x = move_x;
		move_y = info->user->pos_y - info->user->dir_y * info->user->move_speed;
		if (0.1 <= move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->user->pos_x)] != 1)
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
		move_x = info->user->pos_x + info->user->dir_y * info->user->move_speed;
		if (0.1 <= (int)move_x && (double)move_x < info->map->width - 0.1 && info->map->map[(int)(info->user->pos_y)][(int)(move_x)] != 1)
			info->user->pos_x = move_x;
		move_y = info->user->pos_y - info->user->dir_x * info->user->move_speed;
		if (0.1 <= (int)move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->user->pos_x)] != 1)
			info->user->pos_y = move_y;
	}
	if (key == K_D)
	{
		move_x = info->user->pos_x - info->user->dir_y * info->user->move_speed;
		if (0.1 <= move_x && (double)move_x < info->map->width - 0.1 && info->map->map[(int)(info->user->pos_y)][(int)(move_x)] != 1)
			info->user->pos_x = move_x;
		move_y = info->user->pos_y + info->user->dir_x * info->user->move_speed;
		if (0.1 <= (int)move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->user->pos_x)] != 1)
			info->user->pos_y = move_y;
	}
	return (0);
}

void	change_dir_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	t_user	*user;

	user = info->user;
	old_dir_x = user->dir_x;
	user->dir_x
		= user->dir_x * cos(-user->rot_speed) - user->dir_y * sin(-user->rot_speed);
	info->user->dir_y
		= old_dir_x * sin(-user->rot_speed) + user->dir_y * cos(-user->rot_speed);
	old_plane_x = user->plane_x;
	user->plane_x = user->plane_x * cos(-user->rot_speed) \
		- user->plane_y * sin(-user->rot_speed);
	user->plane_y = old_plane_x * sin(-user->rot_speed) \
			+ user->plane_y * cos(-user->rot_speed);
}

void	change_dir_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	t_user	*user;

	user = info->user;
	old_dir_x = user->dir_x;
	user->dir_x
		= user->dir_x * cos(user->rot_speed) - user->dir_y * sin(user->rot_speed);
	info->user->dir_y
		= old_dir_x * sin(user->rot_speed) + user->dir_y * cos(user->rot_speed);
	old_plane_x = user->plane_x;
	user->plane_x = user->plane_x * cos(user->rot_speed) \
			- user->plane_y * sin(user->rot_speed);
	user->plane_y = old_plane_x * sin(user->rot_speed) \
		+ user->plane_y * cos(user->rot_speed);
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
