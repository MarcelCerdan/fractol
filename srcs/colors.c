/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:45:41 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 12:27:21 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color_coef	blue(void)
{
	t_color_coef	coef;

	coef.a = (t_rgb){0.5, 0.5, 0.5};
	coef.b = (t_rgb){0.5, 0.5, 0.5};
	coef.c = (t_rgb){0.15, 0.15, 0.15};
	coef.d = (t_rgb){0.00, 0.60, 1.00};
	return (coef);
}

t_color_coef	black(void)
{
	t_color_coef	coef;

	coef.a = (t_rgb){0.5, 0.5, 0.5};
	coef.b = (t_rgb){0.5, 0.5, 0.5};
	coef.c = (t_rgb){0.65, 0.65, 0.65};
	coef.d = (t_rgb){0.0, 0.2, 0.3};
	return (coef);
}

t_color_coef	red_white(void)
{
	t_color_coef	coef;

	coef.a = (t_rgb){0.8, 0.5, 0.4};
	coef.b = (t_rgb){0.2, 0.4, 0.2};
	coef.c = (t_rgb){2.0, 1.0, 1.0};
	coef.d = (t_rgb){0.0, 0.25, 0.25};
	return (coef);
}

t_color_coef	purple(void)
{
	t_color_coef	coef;

	coef.a = (t_rgb){0.4, 0.1, 0.3};
	coef.b = (t_rgb){0.4, 0.1, 0.2};
	coef.c = (t_rgb){0.15, 0.0, 0.15};
	coef.d = (t_rgb){0.5, 0.1, 0.7};
	return (coef);
}

t_color_coef	green(void)
{
	t_color_coef	coef;

	coef.a = (t_rgb){0.1, 0.5, 0.3};
	coef.b = (t_rgb){0.1, 0.5, 0.2};
	coef.c = (t_rgb){0.0, 0.15, 0.25};
	coef.d = (t_rgb){0.1, 0.5, 0.6};
	return (coef);
}
