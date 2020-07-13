#include "../includes/fractol.h"

void	ft_paint_rectangle(t_fractol *p)
{
	char *str;

	str = "ZOOM: - or +";
	ft_bzero(p->draw, p->width * p->hight * 4);
	ft_point_coordinates(p);
	ft_fractal_rectangle(p, p->rectangle);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, str);
}

void	ft_paint_julia(t_fractol *p)
{
	
	ft_multi_thread_julia(p);
	expose_hook(p);
	ft_operation(p);
}

void	ft_paint_mandelbrota(t_fractol *p)
{
	ft_multi_thread_mandelbrota(p);
	expose_hook(p);
	ft_operation(p);
}

void		ft_paint_fractal(void *mlx_ptr, t_fractol *p, char *str)
{
	p->mlx_ptr = mlx_ptr;
	
	if ((ft_strcmp(str, "Mandelbrota") == 0))
	{
		ft_mlx_fractal(p, str);
		ft_parametr_mandelbrota(p);
		ft_paint_mandelbrota(p);
	}
	else if ((ft_strcmp(str, "Julia") == 0))
	{
		ft_mlx_fractal(p, str);
		ft_parametr_julia(p);
		ft_paint_julia(p);
	}
	else
		ft_exit();
}

// void	ft_mlx_fractal(t_fractol *p, char *str)
// {
// 	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDHT, HIGHT, str);
// 	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDHT, HIGHT);
// 	p->draw = (int *)mlx_get_data_addr(p->img_ptr, &p->bpp, \
// 				&p->size_line, &p->endian);
// }
