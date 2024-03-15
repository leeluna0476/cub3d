/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/15 11:40:22 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>
#include <mlx.h>

t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
void	pixel_put(t_dot *dot, int color, t_info *info);

int	get_texture_color(int side)
{
	int	color;

	if (side == 0)
		color = COLOR_BLUE;
	else
		color = COLOR_GREEN;
	return (color);
}

void	draw_3D(t_info	*info)
{
	int	x;

	x = 0;
	while (x < WIN_WID)
	{
		double cameraX = (2 * (double)x / (double)(WIN_WID)) - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;

		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
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
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
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
		double perpWallDist;
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		int lineHeight;
		if (fabs(perpWallDist) < 1e-9)
			lineHeight = WIN_HEI;
		else
			lineHeight = (int)(WIN_HEI / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEI / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEI / 2;
		if(drawEnd >= WIN_HEI) drawEnd = WIN_HEI - 1;
		t_dot *dot1 = get_dot(x, drawStart);
		t_dot *dot2 = get_dot(x, drawEnd);
		draw_line(get_line(dot1, dot2), info, get_texture_color(side));
		free(dot1);
		free(dot2);
		x++;
	}
}
