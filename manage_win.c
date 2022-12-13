/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:01:18 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/07 23:14:05 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom(int keycode, t_img *img)
{
	t_dot		pos;
	static int	i;
	float		zoom;

	i = 1;
	zoom = 1;
	mlx_mouse_get_pos(img->win, (int *)&pos.x, (int *)&pos.y);
	if (keycode == SCR_UP)
	{
		i++;
		zoom = 0.62 + 0.38 * cos(0.07 * i);
	}
	else if (keycode == SCR_DWN)
	{
		i--;
		zoom = 0.62 + 0.38 * cos(0.07 * i);
	}
	fractol(img, zoom);
	return (zoom);
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
		mlx_destroy_window(img->mlx, img->win);
	return (0);
}

t_img	create_empty_img(void)
{
	t_img	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, IMGX, IMGY, "Fract'ol");
	img.img = mlx_new_image(img.mlx, IMGX, IMGY);
	mlx_mouse_hook(img.win, ft_zoom, &img);
	img.add = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
