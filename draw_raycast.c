/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 15:29:31 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_raycast.h"

int	get_wall_num(t_cal *cal)
{
	if (cal->side == 0)
	{
		if (cal->ray_dir_x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (cal->ray_dir_y > 0)
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
		wall_x = info->pos_y + cal->ray_dist * cal->ray_dir_y;
	else
		wall_x = info->pos_x + cal->ray_dist * cal->ray_dir_x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(info->tex_imgs[0]->wid));
	if (cal->side == 0 && cal->ray_dir_x < 0)
		tex_x = info->tex_imgs[0]->wid - tex_x - 1;
	if (cal->side == 1 && cal->ray_dir_y > 0)
		tex_x = info->tex_imgs[0]->wid - tex_x - 1;
	return (tex_x);
}

void	draw_wall_texture(int draw_start, int draw_end,
								t_cal *cal, t_info *info)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		w_num;

	tex_x = get_tex_x(cal, info);
	step = 1.0 * info->tex_imgs[0]->hei / cal->line_hei;
	tex_pos = (draw_start - WIN_HEI / 2 + cal->line_hei / 2) * step;
	w_num = get_wall_num(cal);
	while (draw_start < draw_end)
	{
		tex_y = (int)tex_pos & (info->tex_imgs[w_num]->hei - 1);
		tex_pos += step;
		pixel_put(cal->x, draw_start,
			info->texture[w_num][info->tex_imgs[w_num]->hei * tex_y + tex_x],
			info);
		draw_start++;
	}
}

void	draw_raycast(t_cal *cal, t_info *info)
{
	int	draw_start;
	int	draw_end;

	draw_start = -cal->line_hei / 2 + WIN_HEI / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = cal->line_hei / 2 + WIN_HEI / 2;
	if (draw_end >= WIN_HEI)
		draw_end = WIN_HEI - 1;
	draw_wall_texture(draw_start, draw_end, cal, info);
}
