/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:29:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/30 20:19:40 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	redraw_wall(t_dat *win)
{
	size_t	i;
	size_t	j;

	i = win->hum.pos.y / 32;
	j = win->hum.pos.x / 32;
	if (isobstacle(win, ++i, j))
		mpitw(win, win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
			j * 32, i * 32);
	if (isobstacle(win, i, ++j))
		mpitw(win, win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
			j * 32, i * 32);
}

void	redraw_zone(t_dat *win)
{
	int	i;
	int	j;

	mpitw(win, win->map.pix[(unsigned int)*(*win->map.imap + 0)].iid, 0, 0);
	mpitw(win, win->map.pix[(unsigned int)*(*win->map.imap + 1)].iid, 32, 0);
	mpitw(win, win->map.pix[(unsigned int)*(*win->map.imap + 2)].iid, 64, 0);
	i = win->hum.pos.y / 32;
	j = win->hum.pos.x / 32;
	mpitw(win, win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
		j * 32, i * 32);
	i++;
	mpitw(win, win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
		j * 32, i * 32);
	j++;
	mpitw(win, win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
		j * 32, i * 32);
	i--;
	mpitw(win, win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
		j * 32, i * 32);
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
			mpitw(win,
				win->map.pix[(unsigned int)*(*(win->map.imap + i) + j)].iid,
				j * 32, i * 32);
				j++;
		}
		i++;
		j = 0;
	}
}
