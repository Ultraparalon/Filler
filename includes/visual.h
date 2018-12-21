/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:07:10 by vkaidans          #+#    #+#             */
/*   Updated: 2018/06/09 18:07:12 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include "mlx.h"

# define W_WIDTH 2048
# define W_HEIGHT 1300
# define STAT_H 100
# define POLE_H 1200

typedef struct	s_vector
{
	int			clr;
	double		y;
	double		x;
	double		z;
}				t_vector;

typedef struct	s_draw
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int			border1;
	int			border2;
}				t_draw;

typedef struct	s_input
{
	int			isdown;
	int			size;
	int			sidex;
	int			sidey;
	int			pause;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
	double		y_axis;
	double		x_axis;
	double		z_axis;
}				t_input;

typedef	struct	s_img
{
	int			height;
	int			bit_per_pix;
	int			size_line;
	int			endian;
	int			*addr;
	void		*img;
}				t_img;

typedef struct	s_map
{
	int			y;
	int			x;
	int			square;
	int			tab;
	int			*bg_pole;
	char		*score1;
	char		*score2;
	char		*winner;
	char		*p1;
	char		*p2;
	char		**map;
	void		*mlx;
	void		*window;
	t_img		*pole;
	t_img		*stat;
	t_input		in;
}				t_map;

int				vs_rainbow(int morph, int base_clr);
int				vs_contrast(int power, int colour);
void			vs_texture_stat(int *back);
int				*vs_texture_pole(void);
void			vs_get_basic(t_map *map);
void			vs_draw_map(t_map *map);
void			vs_draw_status(t_map *m);
void			vs_render(t_map *map);
int				vs_red_button(t_map *map);
int				vs_rep_key(int key, t_map *map);
int				vs_deal_key(int key, t_map *map);
int				hook_mousedown(int button, int x, int y, t_map *map);
int				hook_mouseup(int button, int x, int y, t_map *map);
int				hook_mousemove(int x, int y, t_map *map);
int				vs_loop(t_map *map);
void			vs_draw_line(t_img *img, t_vector v1, t_vector v2);
void			vs_draw_cell(t_map *map, int x, int y, char c);
t_vector		vs_vector(int z, int x, int y, t_map *map);

#endif
