#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx_macos/mlx.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "structure.h"
# include "error.h"
# include "menu.h"
# ifdef __linux__
#  include "key_linux.h"
# else
#  include "key_macos.h"
# endif
# define ABS(Value) ((Value) > 0 ? (Value) : -(Value))
# define WIDHT		1800
# define HIGHT	(WIDHT * 2 / 3)
# define MAX_ZOOM	20000
# define KZ_MAX		20
# define K_ZOOM		1.2
# define K_LOOK		0.087266462599716
# define COLOR		100000
# define COLOR1		0xFF00
# define COLOR2		0x800080
# define COLOR_FON	0x0
# define DEPTH		100
# define ALFA		0.05
# define MAX_ITER	100
# define NUM_THREAD	16
# define MANDELBROT	1
# define JULIA		2
# define SYMMETRY	3

void	ft_drawing_line(t_fractol *p, int *dot1, int *dot2);
void	ft_drawing_line_dot(t_fractol *p, t_dot *dot1, t_dot *dot2);
void	ft_drawing_fon(t_fractol *p);
int		close_endian(void *param);
int		expose_hook(t_fractol *p);
int		key_press(int key, t_fractol *p);
int		mouse_press(int button, int x, int y, t_fractol *p);
int		mouse_movement(int x, int y, t_fractol *p);
void	zoom_mouse(int key, t_fractol *p);
void	ft_mlx_fractal(t_fractol *p, char *str);
void	ft_exit(void);
void	ft_operation(t_fractol *p);
void	ft_print_instructions(t_fractol *p);
int		ft_pixel_color(int color1, int color2, int step, int n);
int		function_color(t_fractol *data, int speed);
void	ft_operation_key(t_fractol *p);
void	ft_point_coordinates(t_fractol *p);
void	ft_parametr_rectangle(t_fractol *p, char *s1, char *s2);
void	ft_paint_rectangle(t_fractol *p);
void	ft_fractal_rectangle(t_fractol *p, int rectangle[][2]);
int		ft_mandelbrot_check(int num, double c_re, double c_im);
int		ft_julia_check(t_fractol *data, double new_re, double new_im);
int		ft_symmetry_check(t_fractol *data, double new_re, double new_im);
void	ft_parametr_mandelbrota(t_fractol *p);
void	ft_paint_mandelbrota(t_fractol *p);
void	ft_parametr_julia(t_fractol *p);
void	ft_paint_julia(t_fractol *p);
void	ft_paint_fractal(void *mlx_ptr, t_fractol *p, char *str);
void	ft_paint_symmetry(t_fractol *p);
void	fractal_type_image_selection(t_fractol *p);
void	ft_multi_thread(t_fractol *paint);

#endif