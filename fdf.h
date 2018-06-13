/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:11 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/09 14:56:31 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUF_SIZE 10000
# define WIDTH 1000
# define LENGTH 1000

# define OLD 49
# define LESS 37
# define MORE 46
# define INV 34

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>

# define USAGE(x) if (x) proper_exit("usage: ./fdf [path ...] <filename.fdf>");
# define PROTEC(x) if (!x) proper_exit("Error");
# define CHECK_OPEN(x) if (x == -1) proper_exit("Can't open file");
# define CHECK_READ(x) if (x == -1) proper_exit("Can't read file");
# define CHECK_CLOSE(x) if (x == -1)  proper_exit("Can't close file");

typedef struct		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct		s_xy
{
	double			x;
	double			y;
	int				xd;
	int				yd;
	t_rgb			clr;
}					t_xy;

typedef struct		s_pts
{
	t_xy			coord;
}					t_pts;

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef struct		s_dot
{
	int				indice;
	t_xyz			pos;
	int				loc;
}					t_dot;

typedef struct		s_breh
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			xi;
	double			yi;
	double			xf;
	double			yf;
	double			xinc;
	double			yinc;
	double			cumul;
}					t_breh;

typedef struct		s_param
{
	int				zoom;
	int				deca_x;
	int				deca_y;
}					t_param;

typedef struct		s_env
{
	t_dot			*list;
	t_dot			*old;
	t_pts			*lst;
	t_param			display;
	t_breh			seg;
	int				s_l;
	int				s_c;
	char			*image;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_env;

// main.c
void 				proper_exit(char *s);

// parse.c
t_env				*ft_parse_file(char *source, t_env *env);

// convert.c
t_env				*ft_init_list(t_env *env);
t_env				*ft_convert_list(t_env *env);

// key.c
t_env				*ft_reset_high(t_env *env);
t_env				*ft_inverse_high(t_env *env);
t_env				*ft_more_high(t_env *env);
t_env				*ft_less_high(t_env *env);

// display.c
t_env				*ft_init_display(t_env *env);
t_env				*ft_reload_display(t_env *env, int key);

// bresenham.c
t_env				*ft_reload_image(t_env *env);

// draw.c
t_env				*ft_clear_image(t_env *env);
t_env				*ft_add_pix(t_env *env, t_rgb clri, t_rgb clrf, double rat);

// free.c
void				ft_free_all(t_env *env);

#endif
