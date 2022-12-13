/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:31:04 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/07 23:15:11 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_img *img, t_dot dot, t_dot c)
{
	float	i;
	float	si;
	float	tmp;
	t_dot	z;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i < MAX_IT && hypot(z.x, z.y) < B)
	{
		tmp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * tmp * z.y + c.y;
		i += 1;
	}
	if (i < 200)
	{
		si = i - log(log(hypot(z.x, z.y)) / log(B)) / log(2.0);
		put_color(si, img, dot);
	}
	else
		put_color(0, img, dot);
}

int	fractol(t_img *img, float zoom)
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
			mandelbrot(img, dot, c);
			coord.x++;
		}
		coord.x = 0;
		coord.y++;
	}
	return (0);
}

/*int	fractol(t_img *img, float zoom)
{
	t_dot	c;
	t_dot	p;
	t_dot	dot;

	dot.x = 0.0;
	dot.y = 0.0;
	while (dot.y < IMGY)
	{
		c.y = dot.y * (YB - YA) / IMGY + YA;
		while (dot.x < IMGX)
		{
			c.x = dot.x * (XB - XA) / IMGX + XA;
			if (256.0 * pow(hypot(c.x, c.y), 2) - 96.0
				* hypot(c.x, c.y) + 32.0 * c.x - 3.0 < 0.0)
				put_color(0, img, dot);
			else
				mandelbrot(img, dot, c);
			dot.x++;
		}
		dot.x = 0;
		dot.y++;
	}
	return (0);
}*/

int	main(void)
{
	t_img	img;

	img = create_empty_img();
	fractol(&img, 1.0);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_mouse_hook(img.win, ft_zoom, &img);
	mlx_key_hook(img.win, close_win, &img);
	mlx_loop(img.mlx);
	return (0);
}
