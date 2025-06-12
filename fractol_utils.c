/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:44:11 by aramos-m          #+#    #+#             */
/*   Updated: 2025/06/12 22:24:58 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_win(void *param)
{
    t_data  *img;

    img = (t_data *)param;
    mlx_destroy_window(img->mlx, img->win);
    mlx_destroy_display(img->mlx);
    free(img->mlx); 
    exit (0);
}

int key_hook(int key_code, void *param)
{
    if (key_code == KEY_ESC)
        close_win(param);
    return (0);
}
