/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:59:44 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/25 23:24:12 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "mlx-linux/mlx.h"

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITER 50
# define KEY_ESC 65307
# define ON_DESTROY 17

typedef struct s_image
{
	void	*img_ptr; //pointer to image struct
	char	*pix_ptr; //pointer to pixels
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_julia
{
	double	vr;
	double	vi;
}	t_julia;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_julia	julia;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		flag;
}				t_data;

int		close_win(void *param);
int		key_hook(int key_code, void *param);
int		mouse(int button, int x, int y, t_data *pic);
int		draw_mandelbrot(t_data *fract);
int		get_color(int i, int max_iter);
void	put_pixel(t_data *fractal, int x, int y, int color);
int		draw_julia(t_data *fractal);
double	atod(char *input);

#endif
