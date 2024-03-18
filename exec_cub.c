/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 12:22:29 by yegkim           ###   ########.fr       */
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
#include "libft/libft.h"

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

void	load_image(t_info *info, char *path, int tex_num)
{
	t_tex_img	*img;
	int			y;
	int			x;

	img = (t_tex_img *)malloc(sizeof(t_tex_img));
	img->img_ptr = mlx_xpm_file_to_image(info->mlx, path, &img->wid, &img->hei);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	info->texture[tex_num] = (int *)malloc(sizeof(int) * img->hei * img->wid);
	y = 0;
	while (y < img->hei)
	{
		x = 0;
		while (x < img->wid)
		{
			info->texture[tex_num][img->wid * y + x] = img->addr[img->wid * y + x];
			x++;
		}
		y++;
	}
	info->tex_imgs[tex_num] = img;
	mlx_destroy_image(info->mlx, img->img_ptr);
}


void	get_texture(t_info *info)
{
	info->texture = (int **)malloc(sizeof(int *) * 4);
	load_image(info, info->map->east, 0);
	load_image(info, info->map->west, 1);
	load_image(info, info->map->south, 2);
	load_image(info, info->map->north, 3);
}


void	find_start_dir(t_info *info)
{
	int	user_dir;

	user_dir = info->map->user_dir;
	if (user_dir == 'E' || user_dir == 'W')
	{
		if (user_dir == 'E')
			info->dirX = 1;
		else
			info->dirX = -1;
		info->planeY = -0.66;
	}
	if (user_dir == 'N' || user_dir == 'S')
	{
		if (user_dir == 'N')
			info->dirY = -1;
		else
			info->dirY = 1;
		info->planeX = 0.66;
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
	info->posX = info->map->user[1] + 0.5;
	info->posY = info->map->user[0] + 0.5;
	info->mlx = mlx_init();
	get_texture(info);
	info->dirX = 0;
	info->dirY = 0;
	info->planeX = 0;
	info->planeY = 0;
	find_start_dir(info);
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
