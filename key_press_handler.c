/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 12:09:58 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <math.h>

void	draw_2D(t_info *info);
void	draw_3D(t_info	*info);
void	make_image_put_window(t_info *info, void (*draw_map)(t_info *info));

int	go_front_back(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_W)
	{
		move_x = info->posX + info->dirX * info->moveSpeed;
		if (0.1 <= move_x && move_x < (double)info->map->width - 0.1 && info->map->map[(int)(info->posY)][(int)(move_x)] != 1)
			info->posX = move_x;
		move_y = info->posY + info->dirY * info->moveSpeed;
		if (0.1 <= move_y && move_y < (double)info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->posX)] != 1)
			info->posY = move_y;
	}
	if (key == K_S)
	{
		move_x = info->posX - info->dirX * info->moveSpeed;
		if (0.1 <= move_x && (double)move_x <= info->map->width - 0.1 && info->map->map[(int)(info->posY)][(int)(move_x)] != 1)
			info->posX = move_x;
		move_y = info->posY - info->dirY * info->moveSpeed;
		if (0.1 <= move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->posX)] != 1)
			info->posY = move_y;
	}
	return (0);
}

int	go_left_right(int key, t_info *info)
{
	double	move_x;
	double	move_y;

	if (key == K_A)
	{
		move_x = info->posX + info->dirY * info->moveSpeed;
		if (0.1 <= (int)move_x && (double)move_x < info->map->width - 0.1 && info->map->map[(int)(info->posY)][(int)(move_x)] != 1)
			info->posX = move_x;
		move_y = info->posY - info->dirX * info->moveSpeed;
		if (0.1 <= (int)move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->posX)] != 1)
			info->posY = move_y;
	}
	if (key == K_D)
	{
		move_x = info->posX - info->dirY * info->moveSpeed;
		if (0.1 <= move_x && (double)move_x < info->map->width - 0.1 && info->map->map[(int)(info->posY)][(int)(move_x)] != 1)
			info->posX = move_x;
		move_y = info->posY + info->dirX * info->moveSpeed;
		if (0.1 <= (int)move_y && (double)move_y < info->map->height - 0.1 && info->map->map[(int)(move_y)][(int)(info->posX)] != 1)
			info->posY = move_y;
	}
	return (0);
}

void	change_dir_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirX;
	info->dirX
		= info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
	info->dirY
		= old_dir_x * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
	old_plane_x = info->planeX;
	info->planeX = info->planeX * cos(-info->rotSpeed) \
		- info->planeY * sin(-info->rotSpeed);
	info->planeY = old_plane_x * sin(-info->rotSpeed) \
			+ info->planeY * cos(-info->rotSpeed);
}

void	change_dir_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirX;
	info->dirX
		= info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
	info->dirY
		= old_dir_x * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
	old_plane_x = info->planeX;
	info->planeX = info->planeX * cos(info->rotSpeed) \
			- info->planeY * sin(info->rotSpeed);
	info->planeY = old_plane_x * sin(info->rotSpeed) \
		+ info->planeY * cos(info->rotSpeed);
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
	make_image_put_window(info, draw_3D);
	return (0);
}
