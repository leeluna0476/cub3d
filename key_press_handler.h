/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/19 14:00:29 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESS_HANDLER_H
# define KEY_PRESS_HANDLER_H

# include "structs.h"
# include "key_macos.h"
# include <mlx.h>
# include <math.h>

void	draw_2d(t_info *info);
void	draw_3d(t_info	*info);
int		go_front_back(int key, t_info *info);
int		go_left_right(int key, t_info *info);
void	make_image_put_window(t_info *info, void (*draw_map)(t_info *info));

#endif