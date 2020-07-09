#include "../includes/fractol.h"

int			close_endian(void *param)
{
	(void)param;
	exit(0);
}

void	ft_print_instruction(t_fractol *p)
{
	char *s1;
	char *str;

	s1 = "Iteration:  ";
	str = ft_itoa(p->num);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, s1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 130, 20, 0xFFFFFF, str);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR2);
	free(str);
}
