/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:52:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/20 22:55:43 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_dat	*open_win(char **map, char *title)
{
	t_dat	*win;

	win = ft_calloc(1, sizeof (t_dat));
	win->cid = mlx_init();
	load(win, map);
	win->w = win->map.w * 32;
	win->h = win->map.h * 32;
	win->wid = mlx_new_window(win->cid, win->w, win->h, title);
	win->tit = ft_strdup(title);
	return (win);
}

int	close_and_exit(t_dat *win)
{
	mlx_clear_window(win->cid, win->wid);
	free_player(win);
	free_map(win);
	mlx_destroy_window(win->cid, win->wid);
	free(win->tit);
	free(win);
	exit(EXIT_SUCCESS);
	return (0);
}
