/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:38:22 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 15:00:37 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	init_img(t_fract *f)
{
	f->img.mlx = mlx_init();
	f->img.win = mlx_new_window(f->img.mlx, IMGX, IMGY, "Fractol");
	f->img.img = mlx_new_image(f->img.mlx, IMGX, IMGY);
	f->img.add = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	f->smooth = 1;
	f->zoom = 5;
	f->iter = 50;
	f->col = blue();
}

void	init_mandelbrot(t_fract *f)
{
	f->move = -1;
	if (ft_strncmp(f->fractal, "mandelbrot", 10) == 0)
	{
		f->size = (t_complex){2.7, 2.4};
		f->pos = (t_complex){-2.1, -1.2};
	}
	else
	{
		f->size = (t_complex){3.0, 3.0};
		f->pos = (t_complex){-2.0, -2.0};
	}
}

void	init_julia(t_fract *f, int x)
{
	f->move = 0;
	f->move_lock = 0;
	f->mouse = chose_param(x);
	f->size = (t_complex){4.0, 4.0};
	f->pos = (t_complex){-2.0, -2.0};
}
