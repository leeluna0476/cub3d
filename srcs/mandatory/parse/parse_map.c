/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:54:22 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/22 17:31:13 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_map(t_map *env, int map_fd)
{
	char	**cmap;

	cmap = get_map_char(env, map_fd);
	if_error_exit(!cmap);
	env->map = get_map_int(cmap, env->height, env->width);
	free_cpptr(cmap);
	check_map_validity(env);
}

t_map	*parser(int map_fd)
{
	t_map	*env;

	env = ft_calloc(1, sizeof(t_map));
	if_error_exit(!env);
	env->floor = -1;
	env->ceiling = -1;
	env->user[0] = -1;
	parse_texture(env, map_fd);
	parse_map(env, map_fd);
	return (env);
}
