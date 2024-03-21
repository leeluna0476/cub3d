/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/19 14:05:28 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_press_handler.h"

void	change_dir_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	t_user	*user;

	user = info->user;
	old_dir_x = user->dir_x;
	user->dir_x
		= user->dir_x * cos(-user->rot_sp) - user->dir_y * sin(-user->rot_sp);
	info->user->dir_y
		= old_dir_x * sin(-user->rot_sp) + user->dir_y * cos(-user->rot_sp);
	old_plane_x = user->plane_x;
	user->plane_x = user->plane_x * cos(-user->rot_sp) \
		- user->plane_y * sin(-user->rot_sp);
	user->plane_y = old_plane_x * sin(-user->rot_sp) \
			+ user->plane_y * cos(-user->rot_sp);
}

void	change_dir_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;
	t_user	*user;

	user = info->user;
	old_dir_x = user->dir_x;
	user->dir_x
		= user->dir_x * cos(user->rot_sp) - user->dir_y * sin(user->rot_sp);
	info->user->dir_y
		= old_dir_x * sin(user->rot_sp) + user->dir_y * cos(user->rot_sp);
	old_plane_x = user->plane_x;
	user->plane_x = user->plane_x * cos(user->rot_sp) \
			- user->plane_y * sin(user->rot_sp);
	user->plane_y = old_plane_x * sin(user->rot_sp) \
		+ user->plane_y * cos(user->rot_sp);
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
