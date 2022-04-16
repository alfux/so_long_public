/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/16 23:29:58 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_dat	*win;
	int		err;
	int		i;

	if (argc != 2)
		return (1);
	i = 0;
	win = open_win(598, 650, "so_long");
	(void) argv;
	err = get_map(*(argv + 1), &win->map);
	if (!err)
		while (*(win->map + i))
			ft_putstr_fd(*(win->map + i++), 1);
	if (err == 1)
		ft_putstr_fd("Unknown file type.\n", 1);
	if (err == 2)
		ft_putstr_fd("Couldn't open file.\n", 1);
	if (err == 3)
		ft_putstr_fd("File is not a proper map.\n", 1);
	if (err == 4)
		ft_putstr_fd("Warning ! Couldn't close file descriptor.\n", 1);
	load_player(win, 20, 20);
	mpitw(win, win->hum.spr[0].iid, 20, 20);
	mlx_loop_hook(win->cid, (int (*)())(&animate), win);
	mlx_hook(win->wid, AF_KEYDOWN, 0, (int (*)())(&kd_event), win);
	mlx_hook(win->wid, AF_KEYUP, 0, (int (*)())(&ku_event), win);
	mlx_hook(win->wid, AF_DESTROY, 0, (int (*)())(&close_and_exit), win);
	mlx_do_key_autorepeatoff(win->cid);
	mlx_loop(win->cid);
	return (0);
}
