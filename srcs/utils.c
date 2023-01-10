/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:59:39 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/09 20:28:29 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	chose_param(int x)
{
	t_complex	params[8];

	params[0] = (t_complex){0.285, 0.01};
	params[1] = (t_complex){0.13, 0.745};
	params[2] = (t_complex){0.4, 0.2};
	params[3] = (t_complex){-1.0, 0.0};
	params[4] = (t_complex){0.5, 0.5};
	params[5] = (t_complex){0.3, 0.5};
	params[6] = (t_complex){-0.72, 0.11};
	params[7] = (t_complex){0.185, 0.013};
	return (params[x - 1]);
}

void	my_mlx_pixel_put(t_fract *f, int x, int y, float color)
{
	char	*dst;

	dst = f->img.add + (y * f->img.line_len + x * (f->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_win(t_fract *f)
{
	if (f->img.mlx && f->img.win)
		mlx_destroy_image(f->img.mlx, f->img.win);
	if (f->img.mlx && f->img.img)
		mlx_destroy_window(f->img.mlx, f->img.img);
	exit(0);
}

void	zoom_in(t_fract *f, t_complex pos)
{
	f->pos.re += f->size.re / f->zoom * (pos.re / IMGX);
	f->pos.im += f->size.im / f->zoom * (pos.im / IMGY);
	f->size.re -= f->size.re / f->zoom;
	f->size.im -= f->size.im / f->zoom;
}

void	zoom_out(t_fract *f, t_complex pos)
{
	f->pos.re -= f->size.re / f->zoom * (pos.re / IMGX);
	f->pos.im -= f->size.im / f->zoom * (pos.im / IMGY);
	f->size.re += f->size.re / f->zoom;
	f->size.im += f->size.im / f->zoom;
}
