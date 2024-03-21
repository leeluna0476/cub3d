/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:15:28 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/19 14:27:38 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define WIN_WID 820
# define WIN_HEI 640
# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_GRAY 0xA9A9A9
# define COLOR_BLUE 0x0000FF
# define COLOR_GREEN 0x00FF00
# define COLOR_RED 0xFF0000

# include "parse/parse.h"

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_tex_img
{
	void	*img_ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		wid;
	int		hei;
}			t_tex_img;


typedef struct s_line
{
	int				height;
	int				width;
	struct s_dot	*dot_start;
	struct s_dot	*dot_end;
}		t_line;

typedef struct s_dot
{
	int	x;
	int	y;
}		t_dot;

typedef struct s_cal
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	ray_dist;
	int		line_hei;
	int		x;
}	t_cal;

typedef struct s_user
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_sp;
	double	rot_sp;
}	t_user;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_user		*user;
	t_image		*img;
	int			**texture;
	t_tex_img	*tex_imgs[4];
}				t_info;

#endif