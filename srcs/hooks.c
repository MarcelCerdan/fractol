/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:57:16 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 13:50:49 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static double	scale(int win_pos, int win_size, double pos, double size)
{
	return (((double)win_pos / (double)win_size) * size + pos);
}

int	mouse(int x, int y, t_fract *f)
{
	if (f->move == 0 && f->move_lock == -1)
	{
		f->mouse.re = scale(x, IMGX, f->pos.re, f->size.re);
		f->mouse.im = scale(y, IMGY, f->pos.im, f->size.im);
		f->draw(f);
	}
	return (0);
}

void	options(int k, t_fract *f)
{
	if (k == KEYPLUS)
		f->zoom -= (f->zoom > 2);
	else if (k == KEYMIN)
		f->zoom += 1;
	else if (k == PLUS)
		f->iter += 1;
	else if (k == MIN)
		f->iter -= 1;
	else if (k == S_KEY)
	{
		if (f->smooth == 0)
			f->smooth = 1;
		else
			f->smooth = 0;
	}
	else if (k == M_KEY)
	{
		if (f->move_lock == 0)
			f->move_lock = -1;
		else
			f->move_lock = 0;
	}
	else if (k == H_KEY)
		print_help();
	print_params(f);
}

int	move(int k, t_fract *f)
{
	if (k == ESC)
		close_win(f);
	else if (k == RIGHT)
		f->pos.re += f->size.re / 20;
	else if (k == LEFT)
		f->pos.re -= f->size.re / 20;
	else if (k == UP)
		f->pos.im -= f->size.im / 20;
	else if (k == DOWN)
		f->pos.im += f->size.im / 20;
	options(k, f);
	colors(k, f);
	f->draw(f);
	return (0);
}

int	scroll(int k, int x, int y, t_fract *f)
{
	mlx_mouse_get_pos(f->img.win, &x, &y);
	if (k == SCR_UP)
		zoom_in(f, (t_complex){x, y});
	else if (k == SCR_DWN)
		zoom_out(f, (t_complex){x, y});
	f->draw(f);
	return (0);
}
