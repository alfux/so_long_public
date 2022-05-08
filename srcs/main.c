/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/08 16:29:50 by afuchs           ###   ########.fr       */
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
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error\n", 2);
		if (err == 1)
			ft_putstr_fd("Unknown file type.\n", 2);
		else if (err == 2)
			ft_putstr_fd("Couldn't open file.\n", 2);
		else if (err == 3)
			ft_putstr_fd("File is not a proper map.\n", 2);
		else if (err == 4)
			ft_putstr_fd("Couldn't close file descriptor.\n", 2);
		ft_putstr_fd(WHITE, 2);
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_dat	*win;
	char	**map;

	if (argc != 2)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error\nIncorrect parameters\n", 2);
		ft_putstr_fd(WHITE, 2);
		return (1);
	}
	if (get_err_map(get_map(*(argv + 1), &map), &map))
		return (2);
	win = open_win(map, "so_long");
	putenemy(win);
	draw_map(win);
	mlx_loop_hook(win->cid, &animate, win);
	mlx_hook(win->wid, 2, 0, &kd_event, win);
	mlx_hook(win->wid, 3, 0, &ku_event, win);
	mlx_hook(win->wid, 17, 0, &close_and_exit, win);
	mlx_loop(win->cid);
	return (0);
}
