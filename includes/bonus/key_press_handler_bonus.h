/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 17:12:14 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESS_HANDLER_H
# define KEY_PRESS_HANDLER_H

# include "structs_bonus.h"
# include "key_macos_bonus.h"
# include <stdlib.h>
# include <math.h>
# include "mlx_bonus.h"

void	draw_2d(t_info *info);
void	draw_3d(t_info	*info);
int		go_front_back(int key, t_info *info);
int		go_left_right(int key, t_info *info);
void	make_image_put_window(t_info *info, void (*draw_map)(t_info *info));
void	change_dir_left(t_info *info);
void	change_dir_right(t_info *info);
int		key_press_handler(int key, t_info *info);
int		rotate_mouse(int x, int y, void *param);

#endif
