/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/22 17:08:11 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_MAP_H
# define MINI_MAP_H

# include "structs_bonus.h"
# include <stdlib.h>

t_dot	*get_dot(int x, int y);
void	pixel_put(int x, int y, int color, t_info *info);

#endif
