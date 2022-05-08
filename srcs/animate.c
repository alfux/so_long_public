/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:25:35 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/08 16:33:34 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	isobstacle(t_dat *win, size_t i, size_t j)
{
	if (*(*(win->map.imap + i) + j) != 13
		&& *(*(win->map.imap + i) + j) != 14
		&& *(*(win->map.imap + i) + j) != 18
		&& *(*(win->map.imap + i) + j) != 22)
		return (1);
	return (0);
}

int	can_it_move(t_dat *win, t_coo pos, int x, int y)
{
	size_t	i;
	size_t	j;

	i = (pos.y + y + 20) / 32;
	j = (pos.x + x + 8) / 32;
	if (isobstacle(win, i, j))
		return (0);
	i = (pos.y + y + 20) / 32;
	j = (pos.x + x + 24) / 32;
	if (isobstacle(win, i, j))
		return (0);
	i = (pos.y + y + 24) / 32;
	j = (pos.x + x + 24) / 32;
	if (isobstacle(win, i, j))
		return (0);
	i = (pos.y + y + 24) / 32;
	j = (pos.x + x + 8) / 32;
	if (isobstacle(win, i, j))
		return (0);
	if (pos.x == win->hum.pos.x && pos.y == win->hum.pos.y)
		win->moves++;
	return (x + y);
}

static int	process_kinputs(t_dat *win)
{
	if (win->hum.i == -1)
		return (0);
	if (win->hum.k[win->hum.i] == MOVE_UP)
	{
		win->hum.pos.y += can_it_move(win, win->hum.pos, 0, -1);
		return (6);
	}
	else if (win->hum.k[win->hum.i] == MOVE_DOWN)
	{
		win->hum.pos.y += can_it_move(win, win->hum.pos, 0, 1);
		return (0);
	}
	else if (win->hum.k[win->hum.i] == MOVE_LEFT)
	{
		win->hum.pos.x += can_it_move(win, win->hum.pos, -1, 0);
		return (4);
	}
	else
	{
		win->hum.pos.x += can_it_move(win, win->hum.pos, 1, 0);
		return (2);
	}
}

int	animate(t_dat *win)
{
	char			*sqr;

	sqr = *(win->map.imap + 1 + (win->hum.pos.y / 32))
		+ ((win->hum.pos.x + 16) / 32);
	if (win->hum.i != -1)
		move_player(win, win->hum.pos, 0);
	else if (!win->bodyc && sqrdd(syncp(win->hum.pos), win->expos) < 64)
		game_over(win);
	else if (*sqr == 18 && near_corpse(win))
		clean_corpse(win, sqr, 0);
	else
		move_player(win, win->hum.pos, 1);
	if (win->nbad)
		move_enemy(win);
	drawscr(win);
	if (loser(win))
		game_over(win);
	mpitw(win, win->scr.iid, 0, 0);
	show_moves(win);
	mlx_sync(2, win->wid);
	return (0);
}

void	move_player(t_dat *win, t_coo start, int reset)
{
	static int	next[2];
	static int	sync[2];
	static int	step;

	if (!reset)
	{
		clean_corpse(win, (void *)0, 1);
		step = process_kinputs(win);
	}
	if (start.x == win->hum.pos.x && start.y == win->hum.pos.y)
		reset = 1;
	next[!reset] = 0;
	sync[!reset] = 0;
	if (!next[reset] && !sync[reset])
		next[reset] = 8 * !reset;
	else if (next[reset] == 8 * !reset && sync[reset] == 6)
		next[reset] = 1;
	else if (next[reset] == 1 && sync[reset] == 12)
		next[reset] = 1 + 8 * !reset;
	else if (sync[reset] == 18)
		next[reset] = 0;
	sync[reset] = (sync[reset] + 1) % 24;
	win->hum.aff = step + next[reset];
}
