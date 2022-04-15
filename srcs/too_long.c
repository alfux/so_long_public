/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:42:17 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/15 23:01:41 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	mpitw(t_dat *win, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(win->cid, win->wid, img_ptr, x, y));
}

void	*mxfti(void *mlx_ptr, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
}

char	*mgda(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
{
	return (mlx_get_data_addr(img_ptr, bits_per_pixel, size_line, endian));
}
