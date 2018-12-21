/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:30:20 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 17:30:22 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	vs_draw_map(t_map *map)
{
	int			y;
	int			x;
	t_vector	vec1;
	t_vector	vec2;

	x = -1;
	while (++x <= map->x)
	{
		y = -1;
		while (++y <= map->y)
		{
			if (x < map->x && y < map->y && map->map[y][x] != '.')
				vs_draw_cell(map, x, y, map->map[y][x]);
			vec1 = vs_vector(0x555555, x, y, map);
			if (x + 1 <= map->x)
				vs_draw_line(map->pole, vec1,
					vec2 = vs_vector(0x555555, x + 1, y, map));
			if (y + 1 <= map->y)
				vs_draw_line(map->pole, vec1,
					vec2 = vs_vector(0x555555, x, y + 1, map));
		}
	}
	mlx_put_image_to_window(map->mlx, map->window, map->pole->img, 0, STAT_H);
}

void	vs_get_winner(t_map *map, char *tmp)
{
	int player1;
	int player2;

	player1 = ft_atoi(&tmp[10]);
	get_next_line(0, &tmp);
	player2 = ft_atoi(&tmp[10]);
	free(tmp);
	if (player1 > player2)
		map->winner = ft_strjoin(map->p1, " win!!!");
	else if (player1 < player2)
		map->winner = ft_strjoin(map->p2, " win!!!");
	else
		map->winner = ft_strdup("DRAW!");
	map->score1 = ft_itoa(player1);
	map->score2 = ft_itoa(player2);
}

int		vs_skip_stuff(t_map *map)
{
	char *tmp;

	if (map)
		tmp = NULL;
	while (get_next_line(0, &tmp) > 0)
	{
		if (tmp[0] == '=')
		{
			vs_get_winner(map, tmp);
		}
		else if (tmp[0] == ' ')
		{
			free(tmp);
			return (1);
		}
		free(tmp);
	}
	return (0);
}

void	vs_refresh_map(t_map *map)
{
	char **rat;
	char *tmp;

	rat = map->map;
	while (*rat)
	{
		get_next_line(0, &tmp);
		ft_strcpy(*rat++, &tmp[map->tab]);
		free(tmp);
	}
}

void	vs_render(t_map *map)
{
	if (map->in.pause)
	{
		if (vs_skip_stuff(map))
			vs_refresh_map(map);
	}
	vs_draw_status(map);
	vs_draw_map(map);
}
