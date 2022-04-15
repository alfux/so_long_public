/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/15 22:30:34 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(void)
{
	t_dat	*win;

	win = open_win(598, 650, "so_long");
	load_player(win, 20, 20);
	MPITW(win->cid, win->wid, win->hum.spr[0].iid, 20, 20);
	mlx_loop_hook(win->cid, (int (*)())(&animate), win);
	mlx_hook(win->wid, AF_KEYDOWN, 0, (int (*)())(&kd_event), win);
	mlx_hook(win->wid, AF_KEYUP, 0, (int (*)())(&ku_event), win);
	mlx_hook(win->wid, AF_DESTROY, 0, (int (*)())(&close_and_exit), win);
	mlx_loop(win->cid);
	return (0);
}
