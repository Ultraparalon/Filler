/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:49:26 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/06 18:49:34 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size(const char *str, int *y, int *x)
{
	*y = ft_atoi(str);
	str = ft_skip_char(str, ' ');
	while (*str >= '0' && *str <= '9')
		str++;
	*x = ft_atoi(str);
}

void	get_map(t_fill *info)
{
	char	*tmp;
	int		start;
	char	**map;
	int		count;

	info->map = (char **)ft_memalloc(sizeof(char *) * (info->mapy + 1));
	map = info->map;
	get_next_line(0, &tmp);
	start = 0;
	while (tmp[start] == ' ')
		start++;
	free(tmp);
	count = info->mapy;
	while (count--)
	{
		get_next_line(0, &tmp);
		*map = (char *)ft_memalloc(sizeof(char) * (info->mapx + 1));
		ft_strcpy(*map++, &tmp[start]);
		free(tmp);
	}
}

void	get_token(t_fill *info)
{
	char	*tmp;
	char	**map;
	int		count;

	get_next_line(0, &tmp);
	get_size(&tmp[5], &info->ty, &info->tx);
	free(tmp);
	info->token = (char **)ft_memalloc(sizeof(char *) * (info->ty + 1));
	map = info->token;
	count = info->ty;
	while (count--)
	{
		get_next_line(0, &tmp);
		*map++ = ft_strdup(tmp);
		free(tmp);
	}
}

void	ft_read_input(t_fill *info)
{
	char *tmp;

	if (get_next_line(0, &tmp) > 0)
		if (!ft_strncmp(tmp, "Plateau", 7))
		{
			get_size(&tmp[7], &info->mapy, &info->mapx);
			free(tmp);
			get_map(info);
			get_token(info);
		}
}
