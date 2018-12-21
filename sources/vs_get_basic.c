/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_get_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:40:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/10 16:40:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	vs_cut(char *str)
{
	while (*str)
	{
		if (*str == '.')
			*str = '\0';
		str++;
	}
}

static char	*vs_get_player(t_map *map, int *indent)
{
	char *tmp;
	char *name;

	get_next_line(0, &tmp);
	mlx_string_put(map->mlx, map->window, 5, (*indent += 20), 0xFFFFFF, tmp);
	if (!ft_strcmp(tmp, "error:") || ft_strncmp(tmp, "launched", 8))
	{
		free(tmp);
		ft_error("bad player");
	}
	free(tmp);
	get_next_line(0, &tmp);
	name = ft_strrchr(tmp, '/');
	name = ft_strdup(++name);
	vs_cut(name);
	free(tmp);
	return (name);
}

static void	vs_get_map_size(t_map *map)
{
	char *tmp;
	char **info;

	get_next_line(0, &tmp);
	info = ft_strsplit(tmp, ' ');
	map->y = ft_atoi(info[1]);
	map->x = ft_atoi(info[2]);
	free(tmp);
	get_next_line(0, &tmp);
	map->tab = ft_count_c(tmp, ' ');
	info = (char **)ft_card_destructor((void **)info);
	free(tmp);
}

static char	**vs_get_map(t_map *map)
{
	char	*tmp;
	char	**ret;
	char	**card;
	int		y;

	y = map->y;
	if (!(card = (char **)ft_memalloc(sizeof(char *) * (map->y + 1))))
		ft_error("couldn't allocate memory");
	ret = card;
	while (y--)
	{
		get_next_line(0, &tmp);
		*card++ = ft_strdup(&tmp[map->tab]);
		free(tmp);
	}
	return (ret);
}

void		vs_get_basic(t_map *map)
{
	char	*tmp;
	int		i;
	int		indent;

	i = 5;
	indent = 25;
	while (i--)
	{
		get_next_line(0, &tmp);
		if (!tmp || !ft_strcmp(tmp, "error:") || tmp[0] != '#')
		{
			free(tmp);
			ft_error("wrong input");
		}
		mlx_string_put(map->mlx, map->window, 5, indent, 0xFFFFFF, tmp);
		free(tmp);
		indent += 20;
	}
	map->p1 = vs_get_player(map, &indent);
	map->p2 = vs_get_player(map, &indent);
	vs_get_map_size(map);
	map->map = vs_get_map(map);
}
