/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:07:28 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 14:25:46 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/*--------COLOR---------*/

# define AX 	0.5
# define AY 	0.5
# define AZ 	0.5
# define BX 	0.5
# define BY 	0.5
# define BZ 	0.5
# define CX 	0.15
# define CY 	0.15
# define CZ 	0.15
# define DX 	0.00
# define DY 	0.60
# define DZ 	1.00

/*--------IMAGE---------*/

# define IMGX 	1200
# define IMGY 	900

/*--------FRACTAL---------*/

# define B 		256.0

/*--------MLX EVENTS------*/

# define ON_DESTROY	17
# define PRESSKEY	2
# define PRESSMOUSE	4
# define MOTION		6

/*--------KEYCODE---------*/

# define SCR_UP 	4
# define SCR_DWN 	5
# define ESC 		53
# define RIGHT		124
# define LEFT 		123
# define UP 		126
# define DOWN 		125
# define PLUS		69
# define KEYPLUS	24
# define MIN 		78
# define KEYMIN 	27
# define S_KEY		1
# define H_KEY		4
# define M_KEY		46
# define ONE		83
# define TWO		84
# define THREE		85
# define FOUR		86
# define FIVE		87

/*--------ERRORS---------*/

# define ARG_NMB	"Invalid number of arguments\n\n"
# define ARG_ERR	"Invalid argument\n\n"

/*--------STRUCTURES---------*/

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}	t_rgb;

typedef struct s_color_coef
{
	t_rgb	a;
	t_rgb	b;
	t_rgb	c;
	t_rgb	d;
}	t_color_coef;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fract
{
	t_img			img;
	t_complex		size;
	t_complex		pos;
	t_complex		mouse;
	t_color_coef	col;
	int				(*draw)(struct s_fract *f);
	int				move;
	int				move_lock;
	char			*fractal;
	int				zoom;
	int				smooth;
	int				iter;
	int				x;
	int				y;
}	t_fract;

/*--------PROTOTYPES---------*/

int				create_trgb(t_rgb col, int t);
int				move(int k, t_fract *f);
int				close_win(t_fract *f);
int				scroll(int k, int x, int y, t_fract *f);
int				mouse(int x, int y, t_fract *f);
void			init_img(t_fract *f);
void			print_help(void);
void			my_mlx_pixel_put(t_fract *f, int x, int y, float color);
void			put_color(double si, t_fract *mand);
void			init_fract(t_fract *f);
void			zoom_in(t_fract *f, t_complex pos);
void			zoom_out(t_fract *f, t_complex pos);
void			err_msg(char *msg);
void			print_params(t_fract *f);
void			init_img(t_fract *f);
void			init_mandelbrot(t_fract *f);
int				mandelbrot(t_fract *mand);
void			init_julia(t_fract *f, int x);
int				julia(t_fract *f);
void			draw_burning_ship(t_fract *f, t_complex c);
void			colors(int k, t_fract *f);
t_complex		chose_param(int x);
t_color_coef	blue(void);
t_color_coef	black(void);
t_color_coef	red_white(void);
t_color_coef	purple(void);
t_color_coef	green(void);

#endif
