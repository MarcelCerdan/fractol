/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:13:42 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 14:46:37 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	draw_burning_ship(t_fract *f, t_complex c)
{
	double		i;
	double		tmp;
	t_complex	z;

	i = 0;
	z = c;
	while (i < f->iter && hypot(z.re, z.im) < B)
	{
		tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = 2 * fabs(tmp * z.im) + c.im;
		i += 1;
	}
	if (i < f->iter)
	{
		if (f->smooth == 1)
			i = i - log(log(hypot(z.re, z.im)) / log(B)) / log(2.0);
		put_color(i, f);
	}
	else
		put_color(0, f);
}

void	draw_mandelbrot(t_fract *f, t_complex c)
{
	double		i;
	double		tmp;
	t_complex	z;

	i = 0;
	z = c;
	while (i < f->iter && hypot(z.re, z.im) < B)
	{
		tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = 2 * tmp * z.im + c.im;
		i += 1;
	}
	if (i < f->iter)
	{
		if (f->smooth == 1)
			i = i - log(log(hypot(z.re, z.im)) / log(B)) / log(2.0);
		put_color(i, f);
	}
	else
		put_color(0, f);
}

int	mandelbrot(t_fract *f)
{
	t_complex	c;

	f->y = 0;
	while (f->y < IMGY)
	{
		f->x = 0;
		c.im = f->y / (IMGY / f->size.im) + f->pos.im;
		while (f->x < IMGX)
		{
			c.re = f->x / (IMGX / f->size.re) + f->pos.re;
			if (ft_strncmp(f->fractal, "mandelbrot", 10) == 0)
				draw_mandelbrot(f, c);
			else
				draw_burning_ship(f, c);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->img.mlx, f->img.win, f->img.img, 0, 0);
	return (0);
}
