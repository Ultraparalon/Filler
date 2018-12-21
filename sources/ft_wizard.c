/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wizard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:05:31 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/06 19:05:32 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_position_cmp(t_crd *ret, t_crd *tmp, t_crd *target)
{
	int r;
	int t;

	r = ABS(((target->y + target->x) - (ret->y + ret->x)));
	t = ABS(((target->y + target->x) - (tmp->y + tmp->x)));
	if (t < r)
	{
		ret->y = tmp->y;
		ret->x = tmp->x;
	}
}

int		ft_check_token(t_fill *info, t_crd *tmp)
{
	int		count;
	t_crd	tok;

	count = 0;
	tok.y = -1;
	while (++tok.y < info->ty)
	{
		tok.x = -1;
		while (++tok.x < info->tx)
		{
			if (info->token[tok.y][tok.x] == '*')
			{
				if (tmp->y + tok.y < 0 || tmp->y + tok.y >= info->mapy
					|| tmp->x + tok.x < 0 || tmp->x + tok.x >= info->mapx)
					return (0);
				if (info->map[tmp->y + tok.y][tmp->x + tok.x] != '.'
					&& info->map[tmp->y + tok.y][tmp->x + tok.x] != info->sym)
					return (0);
				if (info->map[tmp->y + tok.y][tmp->x + tok.x] == info->sym)
					count++;
			}
		}
	}
	return ((count == 1) ? 1 : 0);
}

int		ft_check_position(t_fill *info, t_crd curr)
{
	t_crd	tok;
	t_crd	tmp;

	tok.y = -1;
	while (++tok.y < info->ty)
	{
		tok.x = -1;
		while (++tok.x < info->tx)
		{
			if (info->token[tok.y][tok.x] == '*')
			{
				tmp.y = curr.y - tok.y;
				tmp.x = curr.x - tok.x;
				if (ft_check_token(info, &tmp))
				{
					ft_position_cmp(&info->ret, &tmp, &info->enemy);
				}
			}
		}
	}
	return (0);
}

int		ft_wizard(t_fill *info)
{
	t_crd	curr;

	info->ret.y = -1000000;
	info->ret.x = -1000000;
	curr.y = -1;
	while (++curr.y < info->mapy)
	{
		curr.x = -1;
		while (++curr.x < info->mapx)
		{
			if (info->map[curr.y][curr.x] == info->sym)
			{
				ft_check_position(info, curr);
			}
		}
	}
	return (0);
}
