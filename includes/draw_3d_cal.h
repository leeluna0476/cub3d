/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_cal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 16:08:09 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_3D_CAL_H
# define DRAW_3D_CAL_H

# include "structs.h"
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

void	*null_guard(void *ptr);
void	pixel_put(int x, int y, int color, t_info *info);

#endif
