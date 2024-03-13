/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 13:14:47 by yegkim           ###   ########.fr       */
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
void	draw_2D(t_info *info);

void	make_image_put_window(t_info *info, void (*draw_map)(t_info *info))
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->img_ptr = mlx_new_image(info->mlx, WIN_WID, WIN_HEI);
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	info->img = image;
	draw_map(info);
	mlx_put_image_to_window(info->mlx,
		info->win, image->img_ptr, 0, 0);
}

t_info	*get_info_start(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->mlx = mlx_init();
	info->posX = 2;
	info->posY = 2;
	info->dirX = -1;
	info->dirY = 0;
	info->moveSpeed = 0.1;
	info->rotSpeed = 0.1;
	info->win = mlx_new_window(info->mlx, WIN_WID, WIN_HEI, "cub2D");
	return (info);
}

int	exec_cub(void)
{
	t_info	*info;

	info = get_info_start();
	make_image_put_window(info, draw_2D);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press_handler, info);
	mlx_loop(info->mlx);
	return (0);
}