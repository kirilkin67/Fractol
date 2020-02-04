#include "../includes/fractol.h"

void		ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void		ft_operation(t_fractol *p)
{
	mlx_hook(p->win_ptr, 2, 0, key_press, p);
	mlx_hook(p->win_ptr, 17, 0, close_endian, p);
	mlx_hook(p->win_ptr, 4, 0, mouse_press, p);
	// mlx_hook(p->win_ptr, 5, 0, mouse_release, p);
	mlx_hook(p->win_ptr, 6, 0, mouse_movement, p);
	mlx_loop(p->mlx_ptr);
}

static void	ft_mlx_rectangle(t_fractol *p, char *str)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, p->width, p->hight, str);
	p->img_ptr = mlx_new_image(p->mlx_ptr, p->width, p->hight);
	p->draw = (int *)mlx_get_data_addr(p->img_ptr, &p->bpp, \
			&p->size_line, &p->endian);
	ft_paint_rectangle(p);
	ft_operation(p);
}

static void	ft_mlx_fractal(t_fractol *p, char *str)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDHT, HIGHT, str);
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDHT, HIGHT);
	p->draw = (int *)mlx_get_data_addr(p->img_ptr, &p->bpp, \
				&p->size_line, &p->endian);
}

int			main(int argc, char **argv)
{
	t_fractol	paint;

	errno = 0;
	if (argc == 2)
	{
		if ((ft_strcmp(argv[1], "Mandelbrota") == 0))
		{
			ft_mlx_fractal(&paint, *(argv + 1));
			ft_parametr_mandelbrota(&paint);
			ft_paint_mandelbrota(&paint);
		}
		if ((ft_strcmp(argv[1], "Julia") == 0))
		{
			ft_mlx_fractal(&paint, *(argv + 1));
			ft_parametr_julia(&paint);
			ft_paint_julia(&paint);
		}
		else
			ft_exit(ERR_USAGE);
	}
	if (argc == 4 && (ft_strcmp(argv[1], "Rectangle") == 0))
	{
		ft_parametr_rectangle(&paint, argv[2], argv[3]);
		ft_mlx_rectangle(&paint, *(argv + 1));
	}
	else
		ft_exit(ERR_USAGE);
	return (0);
}
