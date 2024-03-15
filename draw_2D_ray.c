/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/15 17:08:34 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>
#include <mlx.h>

t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
void	pixel_put(t_dot *dot, int color, t_info *info);

void	draw_ray(double rayDirX, double rayDirY, t_info *info, double perWallDist)
{
	t_dot	*user;
	double	gap_x;
	double	gap_y;

	gap_x = (double)WIN_WID / (double)info->map->width;
	gap_y = (double)WIN_HEI / (double)info->map->height;
	user = get_dot(info->posX * gap_x, info->posY * gap_y);
	draw_line(get_line(user, get_dot(info->posX * gap_x + rayDirX * gap_x * perWallDist, info->posY * gap_y + rayDirY * gap_y * perWallDist)), info, COLOR_RED);
}

void	draw_2D_ray(t_info	*info)
{
	int	x;

	x = 0;
	while (x < WIN_WID)
	{
		double cameraX = (2 * (double)x / (double)(WIN_WID)) - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;
		// printf("raydir x : %f, raydir y : %f\n", rayDirX, rayDirY);

		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (double)(mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (double)(mapY + 1.0 - info->posY) * deltaDistY;
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
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		draw_ray(rayDirX, rayDirY, info, perpWallDist);
		x++;
	}
}
