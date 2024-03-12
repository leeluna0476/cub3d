/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:59 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/12 19:52:32 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

# include "struct.h"
# include "../libft/libft.h"

int		is_direction(char *line);
int		is_color(char *line);
int		is_raised(int flag[6]);
void	free_char_pp(char **ptr);
void	free_env(t_map *env);
void	if_error_exit(int exp);

#endif
