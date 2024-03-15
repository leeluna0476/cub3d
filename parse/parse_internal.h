/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:59 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/13 15:17:06 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_H
# define PARSE_INTERNAL_H

# include "struct.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

int		is_direction(char *line);
int		is_color(char *line);
int		is_raised(int flag[6]);
void	free_char_pp(char **ptr);
void	free_env(t_map *env);
void	insert_value_flag(char **ptr, char *value, int *flag);
void	insert_color_flag(int *ptr, int color[3], int *flag);
void	insert_texture(t_map *env, char *line, int flag[6]);
void	insert_color(t_map *env, char *line, int flag[6]);
void	parse_texture(t_map *env, int map_fd);
char	**merge_string(char **str, char *add);
char	**get_map_char(t_map *env, int map_fd);
int		**get_map_int(char **cmap, int height, int width);
int		is_user(int c);
void	check_map_effect(t_map *env);

#endif
