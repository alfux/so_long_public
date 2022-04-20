/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/20 14:54:53 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	get_err_map(int err, char ***map)
{
	size_t	i;

	i = 0;
	if (!err)
	{
		while (*(*map + i))
			ft_printf("%s%s%s", GREEN, *(*map + i++), WHITE);
		return (0);
	}
	else
	{
		if (err == 1)
			ft_printf("%sUnknown file type.%s\n", RED, WHITE);
		else if (err == 2)
			ft_printf("%sCouldn't open file.%s\n", RED, WHITE);
		else if (err == 3)
			ft_printf("%sFile is not a proper map.%s\n", RED, WHITE);
		else if (err == 4)
			ft_printf("%sCouldn't close file descriptor.%s\n", RED, WHITE);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_dat	*win;
	char	**map;

	if (argc != 2)
		return (1);
	if (get_err_map(get_map(*(argv + 1), &map), &map))
		return (2);
	win = open_win(598, 650, "so_long");
	load_player(win, 20, 20);
	mpitw(win, win->hum.spr[0].iid, 20, 20);
	mlx_loop_hook(win->cid, &animate, win);
	mlx_hook(win->wid, KeyPress, KeyPressMask, &kd_event, win);
	mlx_hook(win->wid, KeyRelease, KeyReleaseMask, &ku_event, win);
	mlx_hook(win->wid, DestroyNotify, 0L, &close_and_exit, win);
	mlx_loop(win->cid);
	return (0);
}
