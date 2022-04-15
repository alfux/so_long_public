/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:25:35 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/15 22:22:40 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	process_kinputs(t_dat *win)
{
	if (win->hum.i == -1)
		return (0);
	if (win->hum.k[win->hum.i] == MOVE_UP)
		win->hum.pos.y -= 2;
	else if (win->hum.k[win->hum.i] == MOVE_DOWN)
		win->hum.pos.y += 2;
	else if (win->hum.k[win->hum.i] == MOVE_LEFT)
		win->hum.pos.x -= 2;
	else if (win->hum.k[win->hum.i] == MOVE_RIGHT)
		win->hum.pos.x += 2;
	if (win->hum.k[win->hum.i] == MOVE_UP)
		return (6);
	else if (win->hum.k[win->hum.i] == MOVE_DOWN)
		return (0);
	else if (win->hum.k[win->hum.i] == MOVE_LEFT)
		return (4);
	else
		return (2);
}

t_coo	set_coo(int x, int y)
{
	t_coo	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void	animate(t_dat *win)
{
	if (win->hum.i != -1)
		move_player(win, 0);
	else
		move_player(win, 1);
}

void	move_player(t_dat *win, int reset)
{
	static int	next;
	static int	sync;
	static int	step;

	if (!reset)
		step = process_kinputs(win);
	if (!next && !sync)
		next = 8;
	else if (next == 8 && sync == 8)
		next = 1;
	else if (next == 1 && sync == 16)
		next = 9;
	else if (sync == 24)
		next = 0;
	sync = (sync + 1) % 32;
	if (reset)
	{
		next = 0;
		sync = 0;
	}
	MCW(win->cid, win->wid);
	MPITW(win->cid, win->wid, win->hum.spr[step + next].iid, win->hum.pos.x,
		win->hum.pos.y);
	mlx_sync(2, win->wid);
}
