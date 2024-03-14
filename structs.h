/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:15:28 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/14 14:41:41 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define WIN_WID 640
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

typedef struct s_info
{
	double	posX; //현재 x의 위치
	double	posY; //현재 y의 위치
	double	dirX; //방향까지 포함하여 앞으로 갈 때의 X변화량(방향벡터)
	double	dirY; //방향까지 포함하여, 앞으로 갈 때의 y변화량(방향벡터)
	double	planeX; //카메라평면의 X값
	double	planeY; //카메라평면의 Y값
	void	*mlx;
	void	*win;
	t_map	*map;
	// int		**map; // 임시 맵데이터, 이후에 구조체 포인터로 변경할 것.
	t_image	*img;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

#endif