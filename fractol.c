/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:31:04 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/13 15:05:07 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_img *img, t_fract *mand, t_dot c)
{
	double	i;
	double	si;
	double	tmp;
	t_dot	z;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i < MAX_IT && hypot(z.x, z.y) < B)
	{
		tmp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * tmp * z.y - c.y;
		i += 1;
	}
	if (i < MAX_IT)
	{
		si = i - log(log(hypot(z.x, z.y)) / log(B)) / log(2.0);
		put_color(si, img, mand);
	}
	else
		put_color(0, img, mand);
}

/*int	fractol(t_img *img, float zoom)
{
	t_dot	c;
	t_dot	p;
	t_dot	dot;
	t_dot	a;
	t_dot	coord;

	coord.x = 0.0;
	coord.y = 0.0;
	while (coord.y < IMGY)
	{
		p.y = (-IMGY + 2.0 * coord.y) / IMGY;
		while (coord.x < IMGX)
		{
			p.x = (-IMGX + 2.0 * coord.x) / IMGY;
			a.x = cos(0.15 * (1.0 - zoom));
			a.y = sin(0.15 * (1.0 - zoom));
			zoom = pow(zoom, 8);
			dot.x = p.x * a.x - p.y * a.y;
			dot.y = p.x * a.y + p.y * a.x;
			c.x = -0.745 + dot.x * zoom;
			c.y = 0.186 + dot.y * zoom;
			mandelbrot(img, coord, c);
			coord.x++;
		}
		coord.x = 0;
		coord.y++;
	}
	return (0);
}*/

int	fractol(t_img *img, t_fract *mand)
{
	t_dot	c;

	mand->y = 0;
	while (mand->y < IMGY)
	{
		c.y = mand->ymax - (mand->y * (mand->ymax - mand->ymin) / IMGY);
		while (mand->x < IMGX)
		{
			c.x = mand->xmin + (mand->x * (mand->xmax - mand->xmin) / IMGX);
			mandelbrot(img, mand, c);
			mand->x++;
		}
		mand->x = 0;
		mand->y++;
	}
	return (0);
}

int	main(void)
{
	t_img	img;
	t_fract	mand;

	mand.xmin = XA;
	mand.xmax = XB;
	mand.ymin = YA;
	mand.ymax = YB;
	img = create_empty_img();
	fractol(&img, &mand);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, ft_zoom, &mand);
	mlx_key_hook(img.win, close_win, &img);
	mlx_loop(img.mlx);
	return (0);
}
