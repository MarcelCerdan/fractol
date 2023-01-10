/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:29:31 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 12:27:34 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors(int k, t_fract *f)
{
	if (k == ONE)
		f->col = blue();
	else if (k == TWO)
		f->col = black();
	else if (k == THREE)
		f->col = red_white();
	else if (k == FOUR)
		f->col = purple();
	else if (k == FIVE)
		f->col = green();
}

int	create_trgb(t_rgb col, int t)
{
	int	r;
	int	g;
	int	b;

	r = col.r * 255;
	g = col.g * 255;
	b = col.b * 255;
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_color(double si, t_fract *f)
{
	t_rgb			col;

	col.r = f->col.a.r + f->col.b.r * cos(3.0 + f->col.c.r * si + f->col.d.r);
	col.g = f->col.a.g + f->col.b.g * cos(3.0 + f->col.c.g * si + f->col.d.g);
	col.b = f->col.a.b + f->col.b.b * cos(3.0 + f->col.c.b * si + f->col.d.b);
	my_mlx_pixel_put(f, f->x, f->y, create_trgb(col, 0));
}
