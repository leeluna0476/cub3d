/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:29:20 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_RAYCAST_H
# define DRAW_RAYCAST_H

# include "structs.h"
# include <math.h>
# include <mlx.h>

void	pixel_put(int x, int y, int color, t_info *info);

#endif