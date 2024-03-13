/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 17:00:07 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void	draw_2D(t_info *info);
void	make_image_put_window(t_info *info, void (*draw_map)(t_info *info));

int	go_front_back(int key, t_info *info)
{
	if (key == K_W)
	{
		info->posX += info->dirX * info->moveSpeed;
		info->posY += info->dirY * info->moveSpeed;
	}
	if (key == K_S)
	{
		info->posX -= info->dirX * info->moveSpeed;
		info->posY -= info->dirY * info->moveSpeed;
	}
	return (0);
}

int	change_dir(int key, t_info *info)
{
	double	oldDirX;

	if (key == K_A)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
	}
	if (key == K_D)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
	}
	return (0);
}

int	key_press_handler(int key, t_info *info)
{
	if (key == K_W || key == K_S)
		go_front_back(key, info);
	if (key == K_D || key == K_A)
		change_dir(key, info);
	if (key == K_ESC)
		exit(0);
	make_image_put_window(info, draw_2D);
	return (0);
}
