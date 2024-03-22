/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 17:18:50 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_info.h"

void	load_image(t_info *info, char *path, int tex_num)
{
	t_tex_img	*img;
	int			y;
	int			x;

	img = (t_tex_img *)null_guard(malloc(sizeof(t_tex_img)));
	img->img_ptr = mlx_xpm_file_to_image(info->mlx, path, &img->wid, &img->hei);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	info->texture[tex_num] = (int *)malloc(sizeof(int) * img->hei * img->wid);
	y = 0;
	while (y < img->hei)
	{
		x = 0;
		while (x < img->wid)
		{
			info->texture[tex_num][img->wid * y + x]
				= img->addr[img->wid * y + x];
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

void	apply_start_dir(t_user *user, t_info *info)
{
	int	user_dir;

	user_dir = info->map->user_dir;
	if (user_dir == 'E')
	{
		user->dir_x = 1;
		user->plane_y = 0.66;
	}
	else if (user_dir == 'W')
	{
		user->dir_x = -1;
		user->plane_y = -0.66;
	}
	else if (user_dir == 'N')
	{
		user->dir_y = -1;
		user->plane_x = 0.66;
	}
	else if (user_dir == 'S')
	{
		user->dir_y = 1;
		user->plane_x = -0.66;
	}
}

void	get_user(t_info *info)
{
	t_user	*user;

	user = (t_user *)malloc(sizeof(t_user));
	user->pos_x = info->map->user[1] + 0.5;
	user->pos_y = info->map->user[0] + 0.5;
	user->dir_x = 0;
	user->dir_y = 0;
	user->plane_x = 0;
	user->plane_y = 0;
	user->mouse_x = WIN_WID >> 1;
	user->mouse_y = WIN_HEI >> 1;
	user->move_sp = 0.1;
	user->rot_sp = 0.1;
	apply_start_dir(user, info);
	info->user = user;
}

t_info	*init_info(char **av)
{
	t_info	*info;
	int		map_fd;

	map_fd = open(av[1], O_RDONLY);
	if_error_exit(map_fd == -1);
	info = (t_info *)null_guard(malloc(sizeof(t_info)));
	info->map = parser(map_fd);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIN_WID, WIN_HEI, "cub3D");
	info->mflag = 0;
	get_user(info);
	get_texture(info);
	return (info);
}
