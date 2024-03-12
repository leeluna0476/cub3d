#ifndef PARSE_H
# define PARSE_H

typedef struct s_map t_map;

struct s_map
{
	//NO ./path_to_the_north_texture
	//SO ./path_to_the_south_texture
	//WE ./path_to_the_west_texture
	//EA ./path_to_the_east_texture
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		floor;
	int		ceiling;

	int		**map;
};

#endif
