/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:51:08 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/12 20:00:33 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map	t_map;

struct s_map
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		floor;
	int		ceiling;

	int		**map;
};

#endif
