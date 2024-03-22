/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_cal_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 17:10:43 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_3D_CAL_H
# define DRAW_3D_CAL_H

# include "structs_bonus.h"
# include <stdlib.h>
# include <math.h>

void	*null_guard(void *ptr);
void	pixel_put(int x, int y, int color, t_info *info);

#endif
