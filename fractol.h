/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:07:28 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/13 15:09:13 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
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
# define IMGY 	950

/*--------FRACTAL---------*/

# define MAX_IT 512
# define B 		256.0
# define YA 	-1.5
# define YB 	1.5
# define XA 	-2.0
# define XB 	1.0

/*--------KEYCODE---------*/

# define SCR_UP 	5
# define SCR_DWN 	4
# define ESC 		53

/*--------STRUCTURES---------*/

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}		t_vec3;

typedef struct s_dot
{
	float	x;
	float	y;
}		t_dot;

typedef struct s_fract
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		x;
	int		y;
}		t_fract;

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

/*--------PROTOTYPES---------*/

t_img	create_empty_img(void);
void	my_mlx_pixel_put(t_img *img, int x, int y, float color);
int		create_trgb(t_vec3 col, int t);
int		fractol(t_img *img, t_fract *mand);
void	put_color(double si, t_img *img, t_fract *mand);
int		ft_zoom(int keycode,t_dot z, t_fract *f, t_img *img);
int		close_win(int keycode, t_img *img);

#endif
