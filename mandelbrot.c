/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:52:19 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/11 21:50:53 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx-linux/mlx.h"

# define WIDTH 1080
# define HEIGHT 1080
# define MLX_ERROR 1

typedef struct	s_data {
	void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// Función para poner un pixel en la imagen
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Función para calcular si un punto pertenece al conjunto mandelbrot
int calc_mandelbrot(double cr, double ci, int max_iter)
{
    double  zr;
    double  zi;
    double  tmp;
    int     i;

    zr = 0;
    zi = 0;
    i = 0;
    while (zr * zr + zi * zi <= 4.0 && i < max_iter)
    {
        tmp = zr * zr - zi * zi + cr;
        zi = 2 * zr * zi + ci;
        zr = tmp;
        i++;
    }
    return i;
}

// Función para dibujar Mandelbrot
void    draw_mandelbrot(t_data *img)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < WIDTH)
    {
        while (y < HEIGHT)
        {
            printf("%d ", calc_mandelbrot(x, y, 100));
            x++;
        }
        printf("\n");
        x = 0;
        y++;
    }
}

int main(void)
{
    t_data  img;

    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Mandelbrot");
    img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw_mandelbrot(&img);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
    mlx_destroy_window(img.mlx, img.win);
    mlx_destroy_display(img.mlx);
    free(img.mlx);
}
