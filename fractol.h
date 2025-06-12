/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:59:44 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/12 22:25:40 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx-linux/mlx.h"

#define WIDTH 1080
#define HEIGHT 1080
#define MAX_ITER 100
#define KEY_ESC 65307
#define ON_DESTROY 17
#define MLX_ERROR 1

typedef struct	s_data {
	void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int close_win(void *param);
int key_hook(int key_code, void *param);
