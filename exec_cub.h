/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:18:24 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CUB_H
# define EXEC_CUB_H

# include <mlx.h>
# include <stdlib.h>
# include "structs.h"

int		key_press_handler(int key, t_info *info);
void	draw_2d(t_info *info);
void	draw_3d(t_info	*info);
t_info	*init_info(char **av);
void	*null_guard(void *ptr);

#endif