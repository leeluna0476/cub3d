/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:39:40 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/15 14:45:01 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <math.h>
#include <mlx.h>

t_dot	*get_dot(int x, int y);
int		draw_line(t_line *line, t_info *info, int color);
t_line	*get_line(t_dot *d1, t_dot *d2);
void	pixel_put(t_dot *dot, int color, t_info *info);

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

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if (side == 0) wallX = info->posY + perpWallDist * rayDirY;
      else           wallX = info->posX + perpWallDist * rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)(TEX_WID));
      if(side == 0 && rayDirX > 0) texX = TEX_WID - texX - 1;
      if(side == 1 && rayDirY < 0) texX = TEX_WID - texX - 1;

		// How much to increase the texture coordinate per screen pixel
      double step = 1.0 * TEX_HEI / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - WIN_HEI / 2 + lineHeight / 2) * step;
      for(int y = drawStart; y<drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (TEX_HEI - 1);
        texPos += step;
		int	wall_dir;
		if (side == 0)
		{
			if (rayDirX < 0)
				wall_dir = 0;
			else
				wall_dir = 1;
		}
		else
		{
			if (rayDirY < 0)
				wall_dir = 2;
			else
				wall_dir = 3;
		}
        int color = info->texture[wall_dir][TEX_HEI * texY + texX];
        pixel_put(get_dot(x, y), color, info);
      }
		x++;
	}
}
