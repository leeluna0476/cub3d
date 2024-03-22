/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 17:08:28 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_3D_H
# define DRAW_3D_H

# include "structs_bonus.h"
# include <stdlib.h>

void	pixel_put(int x, int y, int color, t_info *info);
t_cal	*init_cal(t_cal *cal, int x, t_info *info);
void	exec_dda(t_cal *cal, t_info *info);
void	draw_raycast(t_cal *cal, t_info *info);
void	draw_mini_map(t_info *info);

#endif
