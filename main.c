#include "minilibx/mlx.h"
#include <stdio.h>
#define ESC 53

typedef struct s_data
{
	void	*img;
	char	*add;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;	
}			t_ptr;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_length + x * (data->bits_per_pix / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(int keycode, t_ptr *ptr)
{
	if (keycode == ESC)
		mlx_destroy_window(ptr->mlx, ptr->win);
	return (0);
}

int main()
{
	int		color;
	t_data	img;
	t_ptr	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 1920, 1080, "Test");
	color = create_trgb(0, 250, 250, 250);
	img.img = mlx_new_image(ptr.mlx, 1920, 1080);
	img.add = mlx_get_data_addr(img.img, &img.bits_per_pix, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 250, 250, color);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	mlx_key_hook(ptr.win, close_win, &ptr);
	mlx_loop(ptr.mlx);
}
