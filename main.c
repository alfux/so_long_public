/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 19:58:24 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(void)
{
	t_dat	*win;
	t_img	img;
	int		width;
	int		height;

	win = open_win(598, 650, "so_long");
	img.iid = mlx_xpm_file_to_image(win->cid, "test.xpm", &width, &height);
	if (!img.iid)
		return (1);
	win->img = &img;
	img.fpx = mlx_get_data_addr(img.iid, &img.bpp, &img.sil, &img.end);
	*(int *)(img.fpx + 12 * (img.bpp / 8) + 10 * img.sil) = 0x000000ff;
	mlx_put_image_to_window(win->cid, win->wid, win->img->iid, 50, 50);
	mlx_hook(win->wid, AF_KEYDOWN, 0, (int (*)())(&k_event), win);
	mlx_hook(win->wid, AF_DESTROY, 0, (int (*)())(&close_and_exit), win);
	mlx_loop(win->cid);
	return (0);
}
