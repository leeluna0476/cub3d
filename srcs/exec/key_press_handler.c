/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 16:38:00 by seojilee         ###   ########.fr       */
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
	else if (key == K_A || key == K_D)
		go_left_right(key, info);
	else if (!info->mflag && key == K_AR_L)
	{
		info->user->rot_sp = 0.1;
		change_dir_left(info);
	}
	else if (!info->mflag && key == K_AR_R)
	{
		info->user->rot_sp = 0.1;
		change_dir_right(info);
	}
	else if (key == K_M)
	{
		info->mflag = !info->mflag;
		if (info->mflag == 0)
			mlx_mouse_show();
		else
			mlx_mouse_hide();
	}
	else if (key == K_ESC)
		exit(0);
	mlx_destroy_image(info->mlx, info->img);
	make_image_put_window(info, draw_3d);
	return (0);
}
