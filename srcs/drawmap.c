/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:29:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/05 17:58:36 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	redraw_wall(t_dat *win, t_coo pos)
{
	size_t	i;
	size_t	j;

	i = pos.y / 32;
	j = pos.x / 32;
	if (isobstacle(win, ++i, j))
		putscr(win->scr, win->map.pix[(size_t)(*(*(win->map.imap + i) + j))],
			j * 32, i * 32);
	if (isobstacle(win, i, ++j))
		putscr(win->scr, win->map.pix[(size_t)(*(*(win->map.imap + i) + j))],
			j * 32, i * 32);
}

void	redraw_zone(t_dat *win, t_coo pos)
{
	size_t	i;
	size_t	j;
	int		k;

	i = (pos.y / 32) - 1;
	j = (pos.x / 32) - 1;
	k = 0;
	while (k < 9)
	{
		if (i + 1 != 0 && j + 1 != 0 && i < win->map.h && j < win->map.w)
		{
			putscr(win->scr,
				win->map.pix[(size_t)(*(*(win->map.imap + i) + j))],
				j * 32, i * 32);
		}
		if (++k % 3)
			j++;
		else
		{
			i++;
			j -= 2;
		}
	}
}

void	draw_map(t_dat *win)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < win->map.h)
	{
		while (j < win->map.w)
		{
			putscr(win->scr,
				win->map.pix[(size_t)(*(*(win->map.imap + i) + j))],
				j * 32, i * 32);
				j++;
		}
		i++;
		j = 0;
	}
}
