/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:36:00 by wrhett            #+#    #+#             */
/*   Updated: 2020/02/07 19:32:31 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_exit(void)
{
	ft_putendl("Usage: ./fractol <name fractol> \nfractals :\n--> Julia\
	\n--> Mandelbrota\n--> Rectangle widht(100-1000) hight(100-1000)");
	exit(1);
}

int			close_endian(void *param)
{
	(void)param;
	exit(0);
}

void		ft_operation(t_fractol *p)
{
	mlx_hook(p->win_ptr, 2, 0, key_press, p);
	mlx_hook(p->win_ptr, 17, 0, close_endian, p);
	mlx_hook(p->win_ptr, 4, 0, mouse_press, p);
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

int			main(int argc, char **argv)
{
	t_fractol	paint;

	if (argc == 2)
		ft_paint_fractal(&paint, *(argv + 1));
	// if (argc == 3)
	// {
	// 	ft_mlx_fractal(&paint[0], *(argv + 1));
	// 	ft_mlx_fractal(&paint[1], *(argv + 2));
	// 	ft_paint_fractal(&paint[0], *(argv + 1));
	// 	ft_paint_fractal(&paint[1], *(argv + 2));
	// 	ft_operation(&paint[0]);
	// 	// mlx_loop(paint[0].mlx_ptr);
	// 	ft_operation(&paint[1]);
	// 	mlx_loop(paint[1].mlx_ptr);
		
	// }
	if (argc == 4 && (ft_strcmp(argv[1], "Rectangle") == 0) && \
		ft_atoi(argv[2]) > 99 && ft_atoi(argv[2]) < 1001 && \
		ft_atoi(argv[3]) > 99 && ft_atoi(argv[3]) < 1001)
	{
		ft_parametr_rectangle(&paint, argv[2], argv[3]);
		ft_mlx_rectangle(&paint, *(argv + 1));
	}
	else
		ft_exit();
	return (0);
}
