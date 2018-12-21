/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:38:05 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/05 16:38:07 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_check_turn(t_fill *info)
{
	char	*tmp;

	get_next_line(0, &tmp);
	if (tmp[10] == '1')
		info->sym = 'O';
	if (tmp[10] == '2')
		info->sym = 'X';
	free(tmp);
}

int		main(void)
{
	t_fill	info;

	ft_check_turn(&info);
	while (1)
	{
		ft_read_input(&info);
		ft_find_target(&info);
		ft_wizard(&info);
		if (info.ret.y != -1000000)
			ft_printf("%d %d\n", info.ret.y, info.ret.x);
		else
		{
			ft_printf("0 0\n");
			break ;
		}
		info.map = (char **)ft_card_destructor((void **)info.map);
		info.token = (char **)ft_card_destructor((void **)info.token);
	}
	return (0);
}
