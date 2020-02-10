/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:33:14 by wrhett            #+#    #+#             */
/*   Updated: 2020/02/07 19:30:29 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_paint_julia(t_fractol *p)
{
	char *s1;
	char *str;

	s1 = "Iteration:  ";
	str = ft_itoa(p->num);
	ft_multi_thread_julia(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, s1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 130, 20, 0xFFFFFF, str);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR2);
	free(str);
	ft_operation(p);
}

void		ft_paint_mandelbrota(t_fractol *p)
{
	char *s1;
	char *str;

	s1 = "Iteration:  ";
	str = ft_itoa(p->num);
	ft_multi_thread_mandelbrota(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, s1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 130, 20, 0xFFFFFF, str);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR2);
	free(str);
	ft_operation(p);
}

void		ft_paint_rectangle(t_fractol *p)
{
	char *str;

	str = "ZOOM: - or +";
	ft_bzero(p->draw, p->width * p->hight * 4);
	ft_point_coordinates(p);
	ft_fractal_rectangle(p, p->rectangle);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, str);
}

void		ft_mlx_fractal(t_fractol *p, char *str)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDHT, HIGHT, str);
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDHT, HIGHT);
	p->draw = (int *)mlx_get_data_addr(p->img_ptr, &p->bpp, \
				&p->size_line, &p->endian);
}

void		ft_paint_fractal(t_fractol *p, char *str)
{
	if ((ft_strcmp(str, "Mandelbrota") == 0))
	{
		ft_mlx_fractal(p, str);
		ft_parametr_mandelbrota(p);
		ft_paint_mandelbrota(p);
	}
	if ((ft_strcmp(str, "Julia") == 0))
	{
		ft_mlx_fractal(p, str);
		ft_parametr_julia(p);
		ft_paint_julia(p);
	}
	else
		ft_exit();
}
