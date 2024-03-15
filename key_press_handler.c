/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/15 11:53:03 by yegkim           ###   ########.fr       */
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
		if (info->map->map[(int)(info->posY)][(int)(move_x - 0.01)] != 1)
			info->posX += info->dirX * info->moveSpeed;
		move_y = info->posY + info->dirY * info->moveSpeed;
		if (info->map->map[(int)(move_y - 0.01)][(int)(info->posX)] != 1)
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == K_S)
	{
		move_x = info->posX - info->dirX * info->moveSpeed;
		if (info->map->map[(int)(info->posY)][(int)(move_x + 0.01)] != 1)
			info->posX -= info->dirX * info->moveSpeed;
		move_y = info->posY - info->dirY * info->moveSpeed;
		if (info->map->map[(int)(move_y + 0.01)][(int)(info->posX)] != 1)
			info->posY -= info->dirY * info->moveSpeed;
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
	// printf("move x : %f\n", move_x);
    if (info->map->map[(int)(info->posY)][(int)(move_x - 0.01)] != 1)
        info->posX += info->dirY * info->moveSpeed;
    move_y = info->posY - info->dirX * info->moveSpeed;
	// printf("move y : %f\n", move_y);
    if (info->map->map[(int)(move_y + 0.01)][(int)(info->posX)] != 1)
        info->posY -= info->dirX * info->moveSpeed;
}
if (key == K_D)
{
    move_x = info->posX + info->dirY * info->moveSpeed;
	// printf("move x : %f\n", info->posX - info->dirY * info->moveSpeed);
    if (info->map->map[(int)(info->posY)][(int)(move_x + 0.1)] != 1)
        info->posX -= info->dirY * info->moveSpeed;
    move_y = info->posY + info->dirX * info->moveSpeed;
	// printf("move y : %f\n", move_y);
    if (info->map->map[(int)(move_y - 0.1)][(int)(info->posX)] != 1)
        info->posY += info->dirX * info->moveSpeed;
}

	return (0);
}

int	change_dir(int key, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == K_AR_L)
	{
		old_dir_x = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = old_dir_x * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		old_plane_x = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = old_plane_x * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	if (key == K_AR_R)
	{
		old_dir_x = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = old_dir_x * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		old_plane_x = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = old_plane_x * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	return (0);
}

int	key_press_handler(int key, t_info *info)
{
	if (key == K_W || key == K_S)
		go_front_back(key, info);
	if (key == K_A || key == K_D)
		go_left_right(key, info);
	if (key == K_AR_L || key == K_AR_R)
		change_dir(key, info);
	if (key == K_ESC)
		exit(0);
	mlx_destroy_image(info->mlx, info->img);
	make_image_put_window(info, draw_3D);
	return (0);
}
