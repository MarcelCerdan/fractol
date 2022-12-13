/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:07:28 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/07 17:07:24 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

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

# define ZOOM 	100
# define IMGX 	1500
# define IMGY 	1080

/*--------FRACTAL---------*/

# define MAX_IT 200
# define B 		256.0
# define YB 	1.5
# define YA 	-1.5
# define XB 	1.0
# define XA 	-2.0

/*--------KEYCODE---------*/

# define SCR_UP 	4
# define SCR_DWN 	5
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
int		fractol(t_img *img, float zoom);
void	put_color(double si, t_img *img, t_dot dot);
int		ft_zoom(int keycode, t_img *img);
int		close_win(int keycode, t_img *img);

#endif
