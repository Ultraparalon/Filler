/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:03:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/09 20:03:20 by vkaidans         ###   ########.fr       */
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

int			vs_loop(t_map *map)
{
	vs_img_clear(map->pole->addr, map->bg_pole);
	vs_render(map);
	return (0);
}

int			vs_rep_key(int key, t_map *map)
{
	vs_img_clear(map->pole->addr, map->bg_pole);
	if (key == 1)
	{
		map->in.pause = 1;
		vs_render(map);
		map->in.pause = 0;
	}
	else if (key == 88 || key == 124)
		map->in.y_axis += 0.1;
	else if (key == 86 || key == 123)
		map->in.y_axis -= 0.1;
	else if (key == 84 || key == 125)
		map->in.x_axis += 0.1;
	else if (key == 91 || key == 126)
		map->in.x_axis -= 0.1;
	vs_draw_map(map);
	return (0);
}
