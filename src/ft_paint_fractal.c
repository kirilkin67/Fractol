#include "../includes/fractol.h"

int		close_endian(void *param)
{
	(void) param;
	exit(0);
}

void		ft_paint_julia(t_fractol *p)
{
	char	*s1 = "Iteration:  ";
	char	*str;

	str = ft_itoa(p->num);
	// ft_fractal_julia(p);
	ft_multi_thread_julia(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, s1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 130, 20, 0xFFFFFF, str);
	free(str);
	ft_operation(p);
}

void		ft_paint_mandelbrota(t_fractol *p)
{
	char	*s1 = "Iteration:  ";
	char	*str;

	str = ft_itoa(p->num);
	// ft_fractal_mandelbrota(p);
	ft_multi_thread_mandelbrota(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, s1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 130, 20, 0xFFFFFF, str);
	ft_operation(p);
}

void		ft_paint_rectangle(t_fractol *p)
{
	ft_bzero(p->draw, p->width * p->hight * 4);
	ft_point_coordinates(p);
	ft_fractal_rectangle(p, p->rectangle);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
}

