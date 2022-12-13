/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:18 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/13 15:08:24 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom(int keycode, t_dot z, t_fract *f, t_img *img)
{
	double	ax;
	double	ay;

	ax = (f->xmax - f->xmin) / IMGX;
	ay = (f->ymax - f->ymin) / IMGY;
	if (keycode == SCR_UP)
	{
		f->xmin += (ax * z.x) * 0.2;
		f->xmax -= (ax * (IMGX - z.x)) * 0.2;
		f->ymax -= (ay * z.y) * 0.2;
		f->ymin += (ay * (IMGY - z.y)) * 0.2;
	}
	if (keycode == SCR_DWN)
	{
		f->xmin -= 0.2;
		f->xmax += 0.2;
		f->ymin -= 0.2;
		f->ymax += 0.2;
	}
	fractol(img, f);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, float color)
{
	char	*dst;

	dst = img->add + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_win(int keycode, t_img *img)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit (0);
	}
	return (0);
}

t_img	create_empty_img(void)
{
	t_img	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, IMGX, IMGY, "Fract'ol");
	img.img = mlx_new_image(img.mlx, IMGX, IMGY);
	//mlx_mouse_hook(img.win, ft_zoom, &img);
	img.add = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
