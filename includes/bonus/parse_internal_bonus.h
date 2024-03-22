/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_internal_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojilee <seojilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:59 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 17:27:33 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INTERNAL_BONUS_H
# define PARSE_INTERNAL_BONUS_H

# include "structs_bonus.h"
# include "../../srcs/libft/libft.h"
# include <fcntl.h>

int		is_direction(char *line);
int		is_color(char *line);
int		is_raised(int flag[6]);
void	free_cpptr(char **ptr);
void	free_ipptr(int **ptr, int size);
void	free_env(t_map *env);
int		check_comma(char *line);
void	insert_value_flag(char **ptr, char *value, int *flag);
void	insert_color_flag(int *ptr, int color[3], int *flag);
void	insert_texture(t_map *env, char *line, int flag[6]);
void	insert_color(t_map *env, char *line, int flag[6]);
void	parse_texture(t_map *env, int map_fd);
char	**merge_string(char **str, char *add);
char	**get_map_char(t_map *env, int map_fd);
int		**get_map_int(char **cmap, int height, int width);
int		is_empty(char *line);
int		is_user(int c);

int		check_position(int **map, int col, int row, t_map *env);
void	if_user(int	**map, int col, int row, t_map *env);
void	search(int **map, int col, int row, t_map *env);
void	recur(int **map, int col, int row, t_map *env);
void	check_map_validity(t_map *env);

#endif
