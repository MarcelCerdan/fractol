/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:11:09 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 17:53:51 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fract *f, t_complex z)
{
	double	i;
	double	tmp;

	i = 0;
	while (i < f->iter && hypot(z.re, z.im) < B)
	{
		tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + f->mouse.re;
		z.im = 2 * tmp * z.im + f->mouse.im;
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

int	julia(t_fract *f)
{
	t_complex	z;

	f->y = 0;
	while (f->y < IMGY)
	{
		f->x = 0;
		z.im = f->y / (IMGY / f->size.im) + f->pos.im;
		while (f->x < IMGX)
		{
			z.re = f->x / (IMGX / f->size.re) + f->pos.re;
			draw_julia(f, z);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->img.mlx, f->img.win, f->img.img, 0, 0);
	return (0);
}
