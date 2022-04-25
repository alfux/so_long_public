/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:25:12 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/25 15:13:31 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	clean_corpse(t_dat *win, char *sqr)
{
	static int	next;
	static int	sync;
	static int	finish;

	if (finish >= 3)
	{
		finish = 0;
		sync = 0;
		next = 0;
		win->bodyc--;
		*sqr = 13;
		move_player(win, 1);
		return (1);
	}
	if (!sync && finish++ < 3)
		next = 16;
	else if (sync == 8)
		next = 17;
	else if (sync == 16)
		next = 18;
	else if (sync == 24)
		next = 17;
	sync = (sync + 1) % 32;
	mpitw(win, win->hum.spr[next].iid, win->hum.pos.x, win->hum.pos.y);
	return (0);
}

void	open_exit(t_dat *win)
{
	static int	next;
	static int	sync;
	static int	op;

	if (op)
	{
		if (sync == 8)
			next = 27;
		else if (sync == 24)
			next = 26;
	}
	else if (!sync)
		next = 23;
	else if (sync == 8)
		next = 24;
	else if (sync == 16)
		next = 25;
	else if (sync == 24)
	{
		next = 26;
		op = 1;
	}
	sync = (sync + 1) % 32;
	mpitw(win, win->map.pix[next].iid, win->expos.x, win->expos.y);
}
