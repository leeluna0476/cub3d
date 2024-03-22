/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/21 17:27:44 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_3D_H
# define DRAW_3D_H

# include "structs.h"
# include <stdlib.h>

void	pixel_put(int x, int y, int color, t_info *info);
t_cal	*init_cal(t_cal *cal, int x, t_info *info);
void	exec_dda(t_cal *cal, t_info *info);
void	draw_raycast(t_cal *cal, t_info *info);

#endif
