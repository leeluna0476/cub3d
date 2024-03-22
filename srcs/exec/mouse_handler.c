/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:15:11 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 16:04:55 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_press_handler.h"
#include "mlx.h"
#include <math.h>

int	rotate_mouse(int x, int y, void *param)
{
	t_info	*info;

	(void)y;
	info = (t_info *)param;
	if (info->mflag)
	{
		info->user->rot_sp = 0.001 * abs(x - (WIN_WID >> 1));
		if (x > WIN_WID >> 1)
			change_dir_right(info);
		else
			change_dir_left(info);
		mlx_mouse_move(info->win, WIN_WID >> 1, WIN_HEI >> 1);
	}
	mlx_destroy_image(info->mlx, info->img);
	make_image_put_window(info, draw_3d);
	return (0);
}
