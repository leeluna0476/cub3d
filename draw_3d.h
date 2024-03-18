/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:33:23 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_3D_H
# define DRAW_3D_H

# include "structs.h"
# include <math.h>
# include <mlx.h>

void	*null_guard(void *ptr);
void	draw_raycast(t_cal *cal, t_info *info);

#endif