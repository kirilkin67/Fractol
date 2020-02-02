#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
// # include <OpenCL/opencl.h>
# include "../../libft/libft.h"
# include "error.h"
# define ABS(Value) (Value > 0 ? Value : -Value)
# define WIDHT	1800
# define HIGHT	1200
# define KZ	10
# define KZ_MAX	20
# define K_ZOOM	1.2
# define K_LOOK 0.087266462599716
# define COLOR	600000
# define COLOR1	0xFF00
# define COLOR2	0x800080
# define COLOR_FON	0x0
# define DEPTH	80
# define ALFA	0.05
# define NUM	100
# define NUM_THREAD	8
# define STR1	"zoom + or - "
# define STR2	"shift -> or <- UP or DOWN"
# define STR3	"heigt + or -"
# define STR4	"Isometric view - key I"
# define STR5	"Oblique isometric view - key O"

typedef struct	s_dot
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_dot;

typedef struct	s_data
{
	int			x;
	int			y_start;
	int			y_end;
	int			color;
	double		zoom;
	double		delta_x_re;
	double		x_re_min;
	double		y_im_max;
	void		*mlx_ptr;
	int			**draw_t;
}				t_data;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_draw
{
	int			tmp[2];
	int			deltax;
	int			deltay;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
	int			step;
	int			color;
	int			n;
}				t_draw;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*draw;
	int			bpp;
	int			size_line;
	int			endian;
	int			rectangle[4][2];
	int			width;
	int			hight;
	int			side_w;
	int			side_h;
	int			side_z;
	int			mouse_key;
	int			mouse_x;
	int			mouse_y;
	double		c_re;
	double		c_im;
	double		x_re_min;
	double		x_re_max;
	double		y_im_max;
	double		delta_x_re;
	double		zoom;
	double		angle;
	double		k_look;
	double		k_zoom;
	int			color;
	int			shift;
	double		hgt;
	int			x0;
	int			y0;
	int			depth;
	double		alfa;
	double		alfa_x;
	double		alfa_y;
	int			flag;
	int			n;
	int			m;

}				t_fractol;

void			ft_drawing_line(t_fractol *p, int *dot1, int *dot2);
void			ft_draw_line(t_fractol *p, int x1, int y1, int x2, int y2);
void			ft_drawing_line_dot(t_fractol *p, t_dot *dot1, t_dot *dot2);
void			ft_drawing_fon(t_fractol *p);
int				close_endian(void *param);
int				key_press(int key, t_fractol *p);
int				mouse_press(int button, int x, int y, t_fractol *p);
// int				mouse_release(int button, int x, int y, void *param);
// int				mouse_movement(int x, int y, void *param);
// void			zoom_key(int key, t_fractol *p);
// void			zoom_mouse(int key, t_fractol *p);
// void			look(int key, t_fractol *p);
void			ft_exit(char *str);
int				ft_pixel_color(int color1, int color2, int step, int n);
int				ft_pixel_color_alfa(double speed);
int				ft_pixel_color_betta(int dwell);
void			ft_operation_key(t_fractol *p);
void			ft_point_coordinates(t_fractol *p);
void			ft_parametr_rectangle(t_fractol *p, char *s1, char *s2);
void			ft_paint_rectangle(t_fractol *p);
void			ft_fractal_rectangle(t_fractol *p, int rectangle[][2]);
int				ft_complex_number_check(double c_re, double c_im);
void			ft_parametr_mandelbrota(t_fractol *p);
void			ft_fractal_mandelbrota(t_fractol *p);
void			ft_paint_mandelbrota(t_fractol *p);
void			ft_parametr_julia(t_fractol *p);
void			ft_fractal_julia(t_fractol *p);
void			ft_paint_julia(t_fractol *p);
void			ft_multi_thread_mandelbrota(t_fractol *p);

#endif