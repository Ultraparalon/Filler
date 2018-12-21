/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:30:32 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 15:30:34 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	ft_img_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= img->height)
		return ;
	img->addr[x + (y << 11)] = color;
}

void		vs_draw_line(t_img *img, t_vector v1, t_vector v2)
{
	t_draw dr;

	dr.delta_x = ABS(((int)v2.x - (int)v1.x));
	dr.delta_y = ABS(((int)v2.y - (int)v1.y));
	dr.sign_x = (int)v1.x < (int)v2.x ? 1 : -1;
	dr.sign_y = (int)v1.y < (int)v2.y ? 1 : -1;
	dr.border1 = dr.delta_x - dr.delta_y;
	while ((int)v1.x != (int)v2.x || (int)v1.y != (int)v2.y)
	{
		ft_img_set_pixel(img, (int)v1.x, (int)v1.y, v1.clr);
		dr.border2 = dr.border1 << 1;
		if (dr.border2 > -dr.delta_y)
		{
			dr.border1 -= dr.delta_y;
			v1.x += dr.sign_x;
		}
		if (dr.border2 < dr.delta_x)
		{
			dr.border1 += dr.delta_x;
			v1.y += dr.sign_y;
		}
	}
}

static void	vs_draw_square(t_map *map, int x, int y, int colour)
{
	map->square = map->in.size;
	while (map->square--)
	{
		vs_draw_line(map->pole,
			vs_vector(colour, x, y, map),
			vs_vector(colour, x + 1, y, map));
	}
}

void		vs_draw_cell(t_map *map, int x, int y, char c)
{
	int colour;

	if (c == 'X')
		colour = 0xBB0000;
	else if (c == 'x')
		colour = 0xFF0000;
	else if (c == 'O')
		colour = 0x00BB00;
	else
		colour = 0x00FF00;
	vs_draw_square(map, x, y, colour);
}
