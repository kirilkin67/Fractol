#include "../includes/fractol.h"

int		close_endian(void *param)
{
	(void)param;
	exit(0);
}

int		expose_hook(t_fractol *p)
{
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	ft_print_instructions(p);
	return (1);
}

void	ft_print_instructions(t_fractol *p)
{
	char *s1;
	char *str;

	s1 = "Iteration + or - :";
	str = ft_itoa(p->num_iter);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, s1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 210, 20, 0xFFFFFF, str);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR2);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 80, 0xFFFFFF, STR12);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 100, 0xFFFFFF, STR13);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 120, 0xFFFFFF, STR14);
	free(str);
}

void	ft_mlx_fractal(t_fractol *p, char *str)
{
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDHT, HIGHT, str);
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDHT, HIGHT);
	p->draw = (int *)mlx_get_data_addr(p->img_ptr, &p->bpp, \
				&p->size_line, &p->endian);
}
