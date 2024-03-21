/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/21 17:39:53 by seojilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>
#include <mlx.h>

t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
void	pixel_put(t_dot *dot, int color, t_info *info);

void	draw_ray(double ray_dir_x, double ray_dir_y, t_info *info, double perWallDist)
{
	t_dot	*user;
	double	gap_x;
	double	gap_y;

	gap_x = (double)WIN_WID / (double)info->map->width;
	gap_y = (double)WIN_HEI / (double)info->map->height;
	user = get_dot(info->user->pos_x * gap_x, info->user->pos_y * gap_y);
	draw_line(get_line(user, get_dot(info->user->pos_x * gap_x + ray_dir_x * gap_x * perWallDist, info->user->pos_y * gap_y + ray_dir_y * gap_y * perWallDist)), info, COLOR_RED);
	// pixel_put(get_dot(info->plane_x * gap_x, info->plane_y * gap_y), COLOR_GREEN, info);
}

void	draw_2D_ray(t_info	*info)
{
	int	x;

	x = 0;
	while (x < WIN_WID)
	{
		double cameraX = (2 * (double)x / (double)(WIN_WID)) - 1;
		double ray_dir_x = info->user->dir_x + info->user->plane_x * cameraX;
		double ray_dir_y = info->user->dir_y + info->user->plane_y * cameraX;
		// printf("raydir x : %f, raydir y : %f\n", ray_dir_x, ray_dir_y);
		int mapX = (int)info->user->pos_x;
		int mapY = (int)info->user->pos_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / ray_dir_x);
		double deltaDistY = fabs(1 / ray_dir_y);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		if (ray_dir_x < 0)
		{
			stepX = -1;
			sideDistX = (info->user->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (double)(mapX + 1.0 - info->user->pos_x) * deltaDistX;
		}
		if (ray_dir_y < 0)
		{
			stepY = -1;
			sideDistY = (info->user->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (double)(mapY + 1.0 - info->user->pos_y) * deltaDistY;
		}
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (info->map->map[mapY][mapX] == 1)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->user->pos_x + (1 - stepX) / 2) / ray_dir_x;
		else
			perpWallDist = (mapY - info->user->pos_y + (1 - stepY) / 2) / ray_dir_y;
		draw_ray(ray_dir_x, ray_dir_y, info, perpWallDist);
		x++;
	}
}
