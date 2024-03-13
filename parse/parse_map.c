/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:54:22 by seojilee          #+#    #+#             */
/*   Updated: 2024/03/13 15:47:10 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_map(t_map *env, int map_fd)
{
	char	**cmap;

	cmap = get_map_char(env, map_fd);
	if_error_exit(!cmap);
	env->map = get_map_int(cmap, env->height, env->width);
	free_char_pp(cmap);
}

t_map	*parser(int map_fd)
{
	t_map	*env;

	env = ft_calloc(1, sizeof(t_map));
	if_error_exit(!env);
	env->floor = -1;
	env->ceiling = -1;
	parse_texture(env, map_fd);
	parse_map(env, map_fd);
	check_map_effect(env);
	return (env);
}

void	leaks(void)
{
	system("leaks a.out");
}

// int	main(int ac, char **av)
// {
// 	int		map_fd;
// 	t_map	env;

// 	// if no arg or too many args
// 	if_error_exit(ac != 2);

// 	atexit(leaks);
// 	map_fd = open(av[1], O_RDONLY);
// 	// if no such map
// 	if_error_exit(map_fd == -1);
// 	env = parser(map_fd);
// 	printf("north: %s\n", env.north);
// 	printf("south: %s\n", env.south);
// 	printf("west: %s\n", env.west);
// 	printf("east: %s\n", env.east);
// 	printf("floor: %d\n", env.floor);
// 	printf("ceiling: %d\n", env.ceiling);
// 	free_env(&env);
// 	close(map_fd);
// }
