/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:29 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 14:58:18 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_INFO_H
# define INIT_INFO_H

# include <mlx.h>
# include <stdlib.h>
# include "structs.h"
# include "parse/parse.h"

t_map	*parser(int map_fd);
void	*null_guard(void *ptr);

#endif