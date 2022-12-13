/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:29:31 by mthibaul          #+#    #+#             */
/*   Updated: 2022/12/13 14:47:10 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(t_vec3 col, int t)
{
	int	r;
	int	g;
	int	b;

	r = col.x * 255;
	g = col.y * 255;
	b = col.z * 255;
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_color(double si, t_img *img, t_fract *mand)
{
	t_vec3	col;

	col.x = AX + BX * cos(3.0 + CX * si + DX);
	col.y = AY + BY * cos(3.0 + CY * si + DY);
	col.z = AZ + BZ * cos(3.0 + CZ * si + DZ);
	my_mlx_pixel_put(img, mand->x, mand->y, create_trgb(col, 0));
}
