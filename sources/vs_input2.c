/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_input2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:17:23 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/13 15:17:25 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	vs_destroy_trash(void)
{
	char *tmp;

	while (get_next_line(0, &tmp) > 0)
		free(tmp);
}

int			vs_red_button(t_map *map)
{
	if (!map->winner)
		vs_destroy_trash();
	exit(0);
	return (0);
}

int			vs_deal_key(int key, t_map *map)
{
	if (key == 49)
		map->in.pause = (map->in.pause) ? 0 : 1;
	else if (key == 53)
	{
		if (!map->winner)
			vs_destroy_trash();
		exit(0);
	}
	return (0);
}
