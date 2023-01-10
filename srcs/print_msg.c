/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:23:16 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 14:47:57 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	err_msg(char *msg)
{
	ft_printf("\nError : %s", msg);
	ft_printf("------------------------------------------\n");
	ft_printf("To select a set, type mandelbrot, julia or burning ship.\n");
	ft_printf("For the julia set, type a number between 1 and 8 to ");
	ft_printf("display different intersting fractals\n");
	ft_printf("------------------------------------------\n\n");
	exit(0);
}

void	print_params(t_fract *f)
{
	ft_printf("---------------------------------------");
	ft_printf("\n	%s\n\n", f->fractal);
	ft_printf("Iteration max : %d\n", f->iter);
	ft_printf("Zoom : %d\n", f->zoom);
	ft_printf("Press 'H' for help.\n");
	ft_printf("---------------------------------------\n");
}

void	print_help(void)
{
	ft_printf("\n-----------------HELP------------------\n");
	ft_printf("* Use the mouse wheel to zoom in or out on the mouse cursor.\n");
	ft_printf("* To change the level of detail of the fractal, ");
	ft_printf("press '+' or '-' on the numpad.\n");
	ft_printf("* To change the value of the zoom, press '+' or '-' ");
	ft_printf("on the keypad.\n");
	ft_printf("* To activate or desactivate the smooth iteration, ");
	ft_printf("press 'S'\n");
	ft_printf("* To move in the fractal, use the arrow keys.\n");
	ft_printf("* To change the color set, press '1' to '5' on the numpad.\n");
	ft_printf("* To leave the window, press 'ESC'.\n");
	ft_printf("* To change the julia fractal, press 'M' and then move ");
	ft_printf("the mouse cursor while left clicking.\n");
}
