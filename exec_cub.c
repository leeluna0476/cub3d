/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/15 14:45:22 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "parse/parse.h"

void	pixel_put(t_dot *dot, int color, t_info *info);
t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
int	key_press_handler(int key, t_info *info);
void	draw_2D(t_info *info);
void	draw_3D(t_info	*info);
t_map	*parser(int map_fd);

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

void	find_start_point(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if (info->map->map[y][x] == 'N')
			{
				info->posX = x + 0.5;
				info->posY = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_texture(t_info *info)
{
	for (int x = 0; x < TEX_WID; x++)
	{
		for (int y = 0; y < TEX_HEI; y++)
		{
			int xorcolor = (x * 256 / TEX_WID) ^ (y * 256 / TEX_HEI);
			// int ycolor = y * 256 / TEX_WID;
			int xycolor = y * 128 / TEX_HEI + x * 128 / TEX_HEI;
			info->texture[0][TEX_WID * y + x] = 65536 * 254 * (x != y && x != TEX_WID - y); //flat red texture with black cross
			info->texture[1][TEX_WID * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			info->texture[2][TEX_WID * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			info->texture[3][TEX_WID * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
		}
	}
}

t_info	*get_info_start(char **av)
{
	t_info	*info;
	int		map_fd;

	info = (t_info *)malloc(sizeof(t_info));
	map_fd = open(av[1], O_RDONLY);
	if_error_exit(map_fd == -1);
	info->map = parser(map_fd);
	find_start_point(info);
	info->mlx = mlx_init();
	get_texture(info);
	info->dirX = -1;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = -0.66;
	info->moveSpeed = 0.1;
	info->rotSpeed = 0.1;
	info->win = mlx_new_window(info->mlx, WIN_WID, WIN_HEI, "cub3D");
	return (info);
}

int	exec_cub(char **av)
{
	t_info	*info;

	info = get_info_start(av);
	make_image_put_window(info, draw_3D);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press_handler, info);
	mlx_loop(info->mlx);
	return (0);
}
