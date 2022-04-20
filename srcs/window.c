/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:52:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/19 13:58:44 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_dat	*open_win(int w, int h, char *title)
{
	t_dat	*win;

	win = ft_calloc(1, sizeof (t_dat));
	win->cid = mlx_init();
	win->wid = mlx_new_window(win->cid, w, h, title);
	win->w = w;
	win->h = h;
	win->tit = ft_strdup(title);
	return (win);
}

int	close_and_exit(t_dat *win)
{
	mlx_clear_window(win->cid, win->wid);
	free_player(win);
	mlx_destroy_window(win->cid, win->wid);
	free(win->tit);
	free(win);
	exit(EXIT_SUCCESS);
	return (0);
}
