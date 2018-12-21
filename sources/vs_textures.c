/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:18:02 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/12 20:18:03 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		vs_texture_stat(int *back)
{
	int i;

	i = W_WIDTH * STAT_H;
	while (i--)
		*back++ = 0x555577;
	i = W_WIDTH << 2;
	back--;
	while (i--)
		*back-- = 0x5555FF;
}

static void	vs_fill(int *back)
{
	int	colour;
	int base_clr;
	int y;
	int x;

	base_clr = 0xFF0000;
	y = -1;
	while (++y < POLE_H)
	{
		colour = base_clr;
		x = -1;
		while (++x < W_WIDTH)
		{
			colour = vs_rainbow(1, colour);
			*back++ = vs_contrast(150, colour);
		}
		base_clr = vs_rainbow(1, base_clr);
	}
}

static void	vs_upgrade(int *back)
{
	int y;
	int x;

	y = -1;
	while (++y < POLE_H)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			*back = vs_contrast(-y >> 3, *back);
			back++;
		}
	}
}

int			*vs_texture_pole(void)
{
	int *back;

	if (!(back = (int *)malloc(sizeof(int) * (W_WIDTH * POLE_H))))
		ft_error("couldn't allocate memory");
	vs_fill(back);
	vs_upgrade(back);
	return (back);
}
