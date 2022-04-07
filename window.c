/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:52:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/07 20:33:09 by afuchs           ###   ########.fr       */
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
	win->title = ft_strdup(title);
	win->img = (t_img *)0;
	return (win);
}

void	close_and_exit(t_dat *win)
{
	mlx_clear_window(win->cid, win->wid);
	mlx_destroy_window(win->cid, win->wid);
	free(win->title);
	free(win);
	exit(EXIT_SUCCESS);
}
