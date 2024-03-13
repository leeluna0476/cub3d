#include "parse.h"

char	**merge_string(char **str, char *add)
{
	char	**new;
	int		i;

	if (!add)
		return (str);
	i = 0;
	while (str && str[i])
		i++;
	new = ft_calloc(i + 2, sizeof(char *));
	if (!new)
		exit(1);
	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = add;
	free(str);
	return (new);
}

char	**get_map_char(t_map *env, int map_fd)
{
	char	*line;
	char	**map;
	int		line_len;
	int		i;

	line = get_next_line(map_fd);
	map = NULL;
	i = 0;
	while (line)
	{
		line_len = ft_strlen(line) - 1;
		line[line_len] = '\0';
		if (line_len > env->width)
			env->width = line_len;
		map = merge_string(map, line);
		line = get_next_line(map_fd);
		(env->height)++;
	}
	return (map);
}

int	**get_map_int(char **cmap, int height, int width)
{
	int	**map;
	int		i;
	int		j;

	map = ft_calloc(height, sizeof(int *));
	if_error_exit(!map);
	j = 0;
	while (cmap[j])
	{
		i = 0;
		map[j] = ft_calloc(width, sizeof(int));
		if_error_exit(!(map[j]));
		while (cmap[j][i] && i < width)
		{
			map[j][i] = map[j][i];
			if (cmap[j][i] != ' ')
				map[j][i] -= '0';
			i++;
		}
		while (i < width)
		{
			map[j][i] = ' ';
			i++;
		}
		j++;
	}
	return (map);
}

void	parse_map(t_map *env, int map_fd)
{
	char	**cmap;

	cmap = get_map_char(env, map_fd);
	if_error_exit(!cmap);
	env->map = get_map_int(cmap, env->height, env->width);
	free_char_pp(cmap);
	//check_map(env);
}

t_map	parser(int map_fd)
{
	t_map	env;

	ft_memset(&env, 0, sizeof(t_map));
	env.floor = -1;
	env.ceiling = -1;
	parse_texture(&env, map_fd);
	parse_map(&env, map_fd);
	return (env);
}

void	leaks(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	int		map_fd;
	t_map	env;

	// if no arg or too many args
	if_error_exit(ac != 2);

	atexit(leaks);
	map_fd = open(av[1], O_RDONLY);
	// if no such map
	if_error_exit(map_fd == -1);
	env = parser(map_fd);
	printf("north: %s\n", env.north);
	printf("south: %s\n", env.south);
	printf("west: %s\n", env.west);
	printf("east: %s\n", env.east);
	printf("floor: %d\n", env.floor);
	printf("ceiling: %d\n", env.ceiling);
	free_env(&env);
	close(map_fd);
}
