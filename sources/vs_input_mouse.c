/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_input_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:21:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/18 13:21:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	vs_img_clear(int *dest, int *src)
{
	int len;

	len = W_WIDTH * POLE_H;
	while (len--)
		*dest++ = *src++;
}

int			hook_mousedown(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	map->in.isdown |= 1 << button;
	return (0);
}

int			hook_mouseup(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	map->in.isdown &= ~(1 << button);
	return (0);
}

int			hook_mousemove(int x, int y, t_map *map)
{
	vs_img_clear(map->pole->addr, map->bg_pole);
	map->in.lastx = map->in.x;
	map->in.lasty = map->in.y;
	map->in.x = x;
	map->in.y = y;
	if (map->in.isdown & (1 << 1))
	{
		map->in.x_axis += (map->in.lasty - y) / 100.0f;
		map->in.y_axis -= (map->in.lastx - x) / 100.0f;
	}
	if (map->in.isdown)
		vs_draw_map(map);
	return (0);
}
