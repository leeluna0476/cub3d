/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 12:49:12 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

# include <mlx.h>
# include <stdlib.h>
# include "../structs.h"

void	align_dot_start(int flag_y, t_line *line);
t_dot	*get_dot(int x, int y);
void	pixel_put(int x, int y, int color, t_info *info);

#endif