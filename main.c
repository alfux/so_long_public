/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 17:43:07 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(void)
{
	t_dat	*scr;

	scr = open_win(598, 650, "so_long");
	scr->col = 0;
	scr->iid = mlx_new_image(scr->cid, 50, 50);
	scr->fpx = mlx_get_data_addr(scr->iid, &scr->bpp, &scr->sil, &scr->end);
	*(int *)(scr->fpx) = 0x00ff0000;
	mlx_put_image_to_window(scr->cid, scr->wid, scr->iid, 50, 50);
	mlx_hook(scr->wid, AF_KEYDOWN, 0, (int (*)())(&k_event), scr);
	mlx_hook(scr->wid, AF_DESTROY, 0, (int (*)())(&close_and_exit), scr);
	mlx_loop(scr->cid);
	return (0);
}
