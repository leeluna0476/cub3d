/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:21 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/13 16:56:18 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "key_macos.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void	pixel_put(t_dot *dot, int color, t_info *info);
t_dot	*get_dot(int x, int y);
int	draw_line(t_line *line, t_info *info);
t_line	*get_line(t_dot *d1, t_dot *d2);
int	key_press_handler(int key, t_info *info);

// int	worldMap[7][7] = {
// 							{1,1,1,1,1,1,1},
// 							{1,0,0,0,1,0,1},
// 							{1,0,1,0,1,0,1},
// 							{1,0,0,0,0,0,1},
// 							{1,0,0,0,0,1,1},
// 							{1,0,0,0,0,0,1},
// 							{1,1,1,1,1,1,1},
// 						};

void	draw_box(t_dot *dot_start, t_dot *dot_end, int color, t_info *info)
{
	int	y;
	int	x;

	y = dot_start->y;
	while (y < dot_end->y)
	{
		x = dot_start->x;
		while (x < dot_end->x)
		{
			if (x == dot_start->x || y == dot_start->y)
				pixel_put(get_dot(x, y), COLOR_GRAY, info);
			else
				pixel_put(get_dot(x, y), color, info);
			x++;
		}
		y++;
	}
	free(dot_start);
	free(dot_end);
}

void	draw_2D_user(t_info *info, double gap_x, double gap_y)
{
	int	mid_x;
	int	mid_y;

	mid_x = info->posX * gap_x - gap_x / 2;
	mid_y = info->posY * gap_y - gap_y / 2;
	draw_box(get_dot(mid_x - 4, mid_y -4), get_dot(mid_x + 4, mid_y + 4), COLOR_BLUE, info);
	draw_line(get_line(get_dot(mid_x, mid_y), get_dot(mid_x + info->dirX * 30, mid_y + info->dirY * 30)), info);
}

// void	ray_cast(t_info *info)
// {
// 	int	x;

// 	x = 0;
// 	while (x < WIN_WID)
// 	{
// 		double cameraX = 2 * x / (double)WIN_WID - 1;
// 		double rayDirX = info->dirX + info->planeX * cameraX;
// 		double rayDirY = info->dirY + info->planeY * cameraX;
		
// 		int mapX = (int)info->posX;
// 		int mapY = (int)info->posY;

// 		//length of ray from current position to next x or y-side
// 		double sideDistX;
// 		double sideDistY;
		
// 		 //length of ray from one x or y-side to next x or y-side
// 		double deltaDistX = fabs(1 / rayDirX);
// 		double deltaDistY = fabs(1 / rayDirY);
// 		double perpWallDist;
		
// 		//what direction to step in x or y-direction (either +1 or -1)
// 		int stepX;
// 		int stepY;
		
// 		int hit = 0; //was there a wall hit?
// 		int side; //was a NS or a EW wall hit?
// 		if (rayDirX < 0)
// 		{
// 			stepX = -1;
// 			sideDistX = (info->posX - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
// 		}
// 		if (rayDirY < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (info->posY - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
// 		}
// 		while (hit == 0)
// 		{
// 			//jump to next map square, OR in x-direction, OR in y-direction
// 			if (sideDistX < sideDistY)
// 			{
// 				sideDistX += deltaDistX;
// 				mapX += stepX;
// 				side = 0;
// 			}
// 			else
// 			{
// 				sideDistY += deltaDistY;
// 				mapY += stepY;
// 				side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			if (worldMap[mapX][mapY] > 0) hit = 1;
// 		}
// 		if (side == 0)
// 			draw_line(get_line(get_dot(info->posX, info->posY), get_dot(info->posX + rayDirX * sideDistX)))
// 		if (side == 0)
// 			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
// 		else
// 			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

// 		//Calculate height of line to draw on screen
// 		int lineHeight = (int)(height / perpWallDist);

// 		//calculate lowest and highest pixel to fill in current stripe
// 		int drawStart = -lineHeight / 2 + height / 2;
// 		if(drawStart < 0)
// 			drawStart = 0;
// 		int drawEnd = lineHeight / 2 + height / 2;
// 		if(drawEnd >= height)
// 			drawEnd = height - 1;

// 		int	color;
// 		if (worldMap[mapY][mapX] == 1)
// 			color = 0xFF0000;
// 		else if (worldMap[mapY][mapX] == 2)
// 			color = 0x00FF00;
// 		else if (worldMap[mapY][mapX] == 3)
// 			color = 0x0000FF;
// 		else if (worldMap[mapY][mapX] == 4)
// 			color = 0xFFFFFF;
// 		else
// 			color = 0xFFFF00;
		
// 		if (side == 1)
// 			color = color / 2;

// 		verLine(info, x, drawStart, drawEnd, color);
		
// 		x++;
// 	}

// }

void	draw_2D(t_info *info)
{
	double	gap_x;
	double	gap_y;
	int		x;
	int		y;
	int		color;

	gap_x = (double)WIN_WID / info->map->width;
	gap_y = (double)WIN_HEI / info->map->height;
	y = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (x < info->map->width)
		{
			if ((info->map->map)[y][x] == 0 || (info->map->map)[y][x] == 'N')
				color = COLOR_BLACK;
			else if ((info->map->map)[y][x] == 1)
				color = COLOR_WHITE;
			else
				color = COLOR_GRAY;
			draw_box(get_dot(x * gap_x, y * gap_y),
				get_dot((x + 1) * gap_x, (y + 1) * gap_y), color, info);
			x++;
		}
		y++;
	}
	draw_2D_user(info, gap_x, gap_y);
}
