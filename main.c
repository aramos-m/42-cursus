/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:52:19 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/08 20:31:54 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx-linux/mlx.h"

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 1080
# define MLX_ERROR 1

typedef struct	s_data {
	void    *img;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    my_mlx_diagonal_put(t_data img)
{
    int xy;

    xy = 0;
    while (xy != WINDOW_WIDTH)
    {
        my_mlx_pixel_put(&img, xy, xy, 0x00FF0000);
        xy++;
    }
}

void    my_mlx_circle_put(t_data img)
{
    int x;
    int y;
    int r;
    int i;

    r = WINDOW_WIDTH/4;
    i = 0;
    while(i != 360)
    {
        x = r * cos(i);
        y = r * sin(i);
        my_mlx_pixel_put(&img, x + 400, y + 400, 0x00FF0000);
        i++; 
    }
}

int main(void)
{
    void	*mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    t_data  img;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (MLX_ERROR);
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (win_ptr == NULL)
        return (MLX_ERROR);
    img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (img.img == NULL)
        return (MLX_ERROR);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //my_mlx_diagonal_put(img);
    my_mlx_circle_put(img);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}