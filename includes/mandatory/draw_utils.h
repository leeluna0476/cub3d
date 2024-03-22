/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 16:44:04 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

# include "structs.h"
# include <stdlib.h>

void	pixel_put(int x, int y, int color, t_info *info);
t_dot	*get_dot(int x, int y);

#endif
