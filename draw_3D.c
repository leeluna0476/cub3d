/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/15 20:02:09 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>
#include <mlx.h>

t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
void	pixel_put(t_dot *dot, int color, t_info *info);

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

void	init_side_dist_and_step(t_cal *cal, t_info *info)
{
	if (cal->ray_dir_x < 0)
	{
		cal->step_x = -1;
		cal->side_dist_x = (info->posX - cal->map_x) * cal->delta_dist_x;
	}
	else
	{
		cal->step_x = 1;
		cal->side_dist_x
			= (double)(cal->map_x + 1.0 - info->posX) * cal->delta_dist_x;
	}
	if (cal->ray_dir_y < 0)
	{
		cal->step_y = -1;
		cal->side_dist_y = (info->posY - cal->map_y) * cal->delta_dist_y;
	}
	else
	{
		cal->step_y = 1;
		cal->side_dist_y
			= (double)(cal->map_y + 1.0 - info->posY) * cal->delta_dist_y;
	}
}

t_cal	*init_cal(t_cal *cal, int x, t_info *info)
{
	cal = (t_cal *)malloc(sizeof(t_cal));
	cal->x = x;
	cal->ray_dir_x = info->dirX
		+ info->planeX * (2 * (double)cal->x / (double)(WIN_WID) - 1);
	cal->ray_dir_y = info->dirY
		+ info->planeY * (2 * (double)cal->x / (double)(WIN_WID) - 1);
	cal->map_x = (int)info->posX;
	cal->map_y = (int)info->posY;
	cal->delta_dist_x = fabs(1 / cal->ray_dir_x);
	cal->delta_dist_y = fabs(1 / cal->ray_dir_y);
	init_side_dist_and_step(cal, info);
	return (cal);
}

void	get_ray_dist_and_line_hei(t_cal *cal, t_info *info)
{
	if (cal->side == 0)
		cal->ray_dist = (cal->map_x - info->posX + (1 - cal->step_x) / 2) / cal->ray_dir_x;
	else
		cal->ray_dist = (cal->map_y - info->posY + (1 - cal->step_y) / 2) / cal->ray_dir_y;
	if (cal->ray_dist == 0)
		cal->line_hei = WIN_HEI;
	else
		cal->line_hei = (int)(WIN_HEI / cal->ray_dist);
}

void	exec_dda(t_cal *cal, t_info *info)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cal->side_dist_x < cal->side_dist_y)
		{
			cal->side_dist_x += cal->delta_dist_x;
			cal->map_x += cal->step_x;
			cal->side = 0;
		}
		else
		{
			cal->side_dist_y += cal->delta_dist_y;
			cal->map_y += cal->step_y;
			cal->side = 1;
		}
		if (info->map->map[cal->map_y][cal->map_x] == 1)
			hit = 1;
			// printf("pos : %f-%f, map : %d-%d, now : %d\n",info->posX, info->posY,  cal->map_x, cal->map_y, info->map->map[cal->map_y][cal->map_x]);
	}
	get_ray_dist_and_line_hei(cal, info);
}

int	get_wall_num(t_cal *cal)
{
	if (cal->side == 0)
	{
		if (cal->ray_dir_x < 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (cal->ray_dir_y < 0)
			return (2);
		else
			return (3);
	}
}

int	get_tex_x(t_cal *cal, t_info *info)
{
	double	wall_x;
	int		tex_x;

	if (cal->side == 0)
		wall_x = info->posY + cal->ray_dist * cal->ray_dir_y;
	else
		wall_x = info->posX + cal->ray_dist * cal->ray_dir_x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(TEX_WID));
	if (cal->side == 0 && cal->ray_dir_x > 0)
		tex_x = TEX_WID - tex_x - 1;
	if (cal->side == 1 && cal->ray_dir_y < 0)
		tex_x = TEX_WID - tex_x - 1;
	return (tex_x);
}

void	draw_wall_texture(int draw_start, int draw_end, t_cal *cal, t_info *info)
{
	int	tex_x;
	int	tex_y;
	int	step;
	int	tex_pos;
	int	y;

	tex_x = get_tex_x(cal, info);
	// How much to increase the texture coordinate per screen pixel
	step = 1.0 * TEX_HEI / cal->line_hei;
	// Starting texture coordinate
	tex_pos = (draw_start - WIN_HEI / 2 + cal->line_hei / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEI - 1);
		tex_pos += step;
		pixel_put(get_dot(cal->x, y), info->texture[get_wall_num(cal)][TEX_HEI * tex_y + tex_x], info);
		y++;
	}
}

void draw_untexture(int draw_start, int draw_end, t_cal *cal, t_info *info)
{
	int	wall_num;
	int	color;
	t_dot	*dot1;
	t_dot	*dot2;

	wall_num = get_wall_num(cal);
	color = 0;
	if (wall_num == 0)
		color = COLOR_RED;
	else if (wall_num == 1)
		color = COLOR_BLUE;
	else if (wall_num == 2)
		color = COLOR_GREEN;
	else if (wall_num == 3)
		color = COLOR_GRAY;
	dot1 = get_dot(cal->x, draw_start);
	dot2 = get_dot(cal->x, draw_end);
	draw_line(get_line(get_dot(cal->x, draw_start), get_dot(cal->x, draw_end)), info, color);
	free(dot1);
	free(dot2);
}

void	draw_raycast(t_cal *cal, t_info *info)
{
	int draw_start;
	int	draw_end;

	draw_start = -cal->line_hei / 2 + WIN_HEI / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = cal->line_hei / 2 + WIN_HEI / 2;
	if (draw_end >= WIN_HEI)
		draw_end = WIN_HEI - 1;
	// draw_wall_texture(draw_start, draw_end, cal, info);
	draw_untexture(draw_start, draw_end, cal, info);
}

void	draw_3D(t_info	*info)
{
	int		x;
	t_cal	*cal;

	x = 0;
	while (x < WIN_WID)
	{
		cal = init_cal(cal, x, info);
		exec_dda(cal, info);
		draw_raycast(cal, info);
		free(cal);
		x++;
	}
}
