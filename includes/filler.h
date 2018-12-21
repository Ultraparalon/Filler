/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:23 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 09:38:53 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_crd
{
	int			y;
	int			x;
}				t_crd;

typedef struct	s_fill
{
	int			mapx;
	int			mapy;
	int			ty;
	int			tx;
	char		sym;
	t_crd		enemy;
	t_crd		ret;
	char		**map;
	char		**token;
}				t_fill;

void			ft_read_input(t_fill *info);
void			ft_find_target(t_fill *info);
int				ft_wizard(t_fill *info);
void			ft_position_cmp(t_crd *ret, t_crd *tmp, t_crd *target);

#endif
