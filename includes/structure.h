#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct	s_dot
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_dot;

typedef struct	s_paint
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*draw;
	int			bpp;
	int			size_line;
	int			endian;
}				t_paint;

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
	int			sign;
	int			mouse_key;
	int			mouse_x;
	int			mouse_y;
	double		c_re;
	double		c_im;
	double		const_re;
	double		const_im;
	double		x_re_min;
	double		y_im_max;
	double		delta_x_re;
	double		zoom;
	int			x;
	int			y_start;
	int			y_end;
	int			num_iter;
	double		angle;
	double		k_look;
	int			color;
	int			x0;
	int			y0;
	int			depth;
	double		alfa;
	double		alfa_x;
	double		alfa_y;
	int			type_fractal;
	int			color_function;
	int			n;
}				t_fractol;

#endif
