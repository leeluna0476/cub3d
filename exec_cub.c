/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:18:20 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cub.h"

void	make_image_put_window(t_info *info, void (*draw_map)(t_info *info))
{
	t_image		*image;

	image = (t_image *)null_guard(malloc(sizeof(t_image)));
	image->img_ptr = mlx_new_image(info->mlx, WIN_WID, WIN_HEI);
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	info->img = image;
	draw_map(info);
	mlx_put_image_to_window(info->mlx,
		info->win, image->img_ptr, 0, 0);
}

int	exit_hook(void)
{
	exit(0);
}

int	exec_cub(char **av)
{
	t_info	*info;
	char	*file_exp;

	info = init_info(av);
	make_image_put_window(info, draw_3d);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press_handler, info);
	mlx_hook(info->win, 17, 0, exit_hook, 0);
	mlx_loop(info->mlx);
	return (0);
}
