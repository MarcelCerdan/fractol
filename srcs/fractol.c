/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:31:04 by mthibaul          #+#    #+#             */
/*   Updated: 2023/01/10 14:56:27 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	check_arg(t_fract *f, int ac, char **av)
{
	if ((ft_strncmp(f->fractal, "mandelbrot", 10) == 0
			|| ft_strncmp(f->fractal, "burning ship", 12) == 0) && ac == 2)
	{
		f->draw = &mandelbrot;
		init_img(f);
		init_mandelbrot(f);
		mandelbrot(f);
	}
	else if (ft_strncmp(f->fractal, "julia", 5) == 0 && ac == 3)
	{
		if (ft_strlen(av[2]) == 1 && av[2][0] >= '1' && av[2][0] <= '8')
		{
			f->draw = &julia;
			init_img(f);
			init_julia(f, ft_atoi(av[2]));
			julia(f);
		}
		else if (ac == 3)
			err_msg(ARG_ERR);
	}
	else
		err_msg(ARG_NMB);
	print_params(f);
}

void	chose_fract(char *fract, t_fract *f)
{
	char	**fractals;
	int		i;

	fractals = malloc(3 * sizeof(char *));
	fractals[0] = "mandelbrot";
	fractals[1] = "julia";
	fractals[2] = "burning ship";
	i = 0;
	while (i <= 2)
	{
		if (ft_strncmp(fract, fractals[i], ft_strlen(fractals[i])) == 0
			&& ft_strlen(fract) == ft_strlen(fractals[i]))
		{
			f->fractal = fractals[i];
			free(fractals);
			return ;
		}
		i++;
	}
	free(fractals);
	err_msg(ARG_ERR);
}

static void	add_hooks(t_fract *f)
{
	mlx_hook(f->img.win, PRESSKEY, 0, move, f);
	mlx_hook(f->img.win, PRESSMOUSE, 0, scroll, f);
	mlx_hook(f->img.win, ON_DESTROY, 0, close_win, f);
	mlx_hook(f->img.win, MOTION, 0, mouse, f);
}

int	main(int ac, char **av)
{
	t_fract	f;

	if (ac < 2 || ac > 3)
		err_msg(ARG_NMB);
	chose_fract(av[1], &f);
	check_arg(&f, ac, av);
	add_hooks(&f);
	mlx_loop(f.img.mlx);
	return (0);
}
