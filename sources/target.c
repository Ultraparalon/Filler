/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:24:22 by vkaidans          #+#    #+#             */
/*   Updated: 2018/07/17 13:24:23 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_crd(t_crd *crd, int y, int x)
{
	crd->y = y;
	crd->x = x;
}

void	ft_find_target(t_fill *info)
{
	char c;

	if (info->map[info->mapy >> 1][info->mapx >> 1] == '.')
		ft_put_crd(&info->enemy, info->mapy >> 1, info->mapx >> 1);
	else if (info->map[0][info->mapx >> 1] == '.')
		ft_put_crd(&info->enemy, 0, info->mapx >> 1);
	else
	{
		c = (info->sym == 'X') ? 'O' : 'X';
		info->enemy.y = -1;
		while (info->map[++(info->enemy.y)])
		{
			info->enemy.x = -1;
			while (info->map[info->enemy.y][++(info->enemy.x)])
				if (info->map[info->enemy.y][info->enemy.x] == c)
					return ;
		}
	}
}
