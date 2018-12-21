/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:25:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/12 17:25:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	vs_draw_status(t_map *m)
{
	mlx_put_image_to_window(m->mlx, m->window, m->stat->img, 0, 0);
	mlx_string_put(m->mlx, m->window, 1024, 10, 0xFFFFFF, "VS");
	mlx_string_put(m->mlx, m->window,
		974 - ((ft_strlen(m->p1)) << 3), 10, 0x00FF00, m->p1);
	mlx_string_put(m->mlx, m->window, 1074, 10, 0xFF0000, m->p2);
	mlx_string_put(m->mlx, m->window,
		1800, 10, 0xFFFFFF, "start/pause - space");
	mlx_string_put(m->mlx, m->window,
		1800, 30, 0xFFFFFF, "        'S' - step");
	mlx_string_put(m->mlx, m->window,
		1790, 50, 0xFFFFFF, "arrows/mouse - move");
	if (!m->in.pause)
		mlx_string_put(m->mlx, m->window, 5, 10, 0xFFFFFF, "[PAUSED]");
	if (m->winner)
	{
		mlx_string_put(m->mlx, m->window,
			974 - ((ft_strlen(m->p1) << 3) >> 1), 30, 0x00FF00, m->score1);
		mlx_string_put(m->mlx, m->window,
			1074 + ((ft_strlen(m->p2) << 3) >> 1), 30, 0xFF0000, m->score2);
		mlx_string_put(m->mlx, m->window,
			1024 - ((ft_strlen(m->winner) << 3) >> 1), 60, 0xFFFFFF, m->winner);
	}
}
