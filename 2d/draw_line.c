/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:24 by yegkim            #+#    #+#             */
/*   Updated: 2024/03/18 12:46:43 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

int	bresenham_y_minus(t_line *line, t_info *info, int color)
{
	int	x;
	int	y;
	int	df_now;
	int	df_minus;
	int	df_plus;

	align_dot_start(1, line);
	x = line->dot_start->x;
	y = line->dot_start->y;
	df_now = 2 * line->width - line->height;
	df_minus = 2 * line->width;
	df_plus = 2 * (line->width - line->height);
	while (y <= line->dot_end->y)
	{
		pixel_put(x, y, color, info);
		if (df_now < 0)
			df_now = df_now + df_minus;
		else
		{
			x--;
			df_now = df_now + df_plus;
		}
		y++;
	}
	return (1);
}

int	bresenham_x_minus(t_line *line, t_info *info, int color)
{
	int	x;
	int	y;
	int	df_now;
	int	df_minus;
	int	df_plus;

	align_dot_start(0, line);
	x = line->dot_start->x;
	y = line->dot_start->y;
	df_now = 2 * line->height - line->width;
	df_minus = 2 * line->height;
	df_plus = 2 * (line->height - line->width);
	while (x <= line->dot_end->x)
	{
		pixel_put(x, y, color, info);
		if (df_now < 0)
			df_now = df_now + df_minus;
		else
		{
			y--;
			df_now = df_now + df_plus;
		}
		x++;
	}
	return (1);
}

int	bresenham_x_plus(t_line *line, t_info *info, int color)
{
	int	x;
	int	y;
	int	df_now;
	int	df_minus;
	int	df_plus;

	align_dot_start(0, line);
	x = line->dot_start->x;
	y = line->dot_start->y;
	df_now = 2 * line->height - line->width;
	df_minus = 2 * line->height;
	df_plus = 2 * (line->height - line->width);
	while (x <= line->dot_end->x)
	{
		pixel_put(x, y, color, info);
		if (df_now < 0)
			df_now = df_now + df_minus;
		else
		{
			y++;
			df_now = df_now + df_plus;
		}
		x++;
	}
	return (1);
}

int	bresenham_y_plus(t_line *line, t_info *info, int color)
{
	int	x;
	int	y;
	int	df_now;
	int	df_minus;
	int	df_plus;

	align_dot_start(1, line);
	x = line->dot_start->x;
	y = line->dot_start->y;
	df_now = 2 * line->width - line->height;
	df_minus = 2 * line->width;
	df_plus = 2 * (line->width - line->height);
	while (y <= line->dot_end->y)
	{
		pixel_put(x, y, color, info);
		if (df_now < 0)
			df_now = df_now + df_minus;
		else
		{
			x++;
			df_now = df_now + df_plus;
		}
		y++;
	}
	return (1);
}

int	draw_line(t_line *line, t_info *info, int color)
{
	int	wid;
	int	hei;

	wid = line->dot_end->x - line->dot_start->x;
	hei = line->dot_end->y - line->dot_start->y;
	if (wid == 0)
		bresenham_y_plus(line, info, color);
	else if (hei == 0 || wid == hei)
		bresenham_x_plus(line, info, color);
	else if ((wid < 0 && hei > -1 * wid)
		|| (wid > 0 && hei < -1 * wid))
		bresenham_y_minus(line, info, color);
	else if ((wid * hei < 0)
		&& ((wid < 0 && hei <= -1 * wid) || (wid > 0 && hei >= -1 * wid)))
		bresenham_x_minus(line, info, color);
	else if ((0 < hei * wid)
		&& ((wid > 0 && hei <= wid) || (wid < 0 && hei >= wid)))
		bresenham_x_plus(line, info, color);
	else
		bresenham_y_plus(line, info, color);
	free(line);
	return (1);
}
