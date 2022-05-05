/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:25:35 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/05 16:33:00 by afuchs           ###   ########.fr       */
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
	static clock_t	prev;
	clock_t			curr;
	char			*sqr;

	sqr = *(win->map.imap + 1 + (win->hum.pos.y / 32))
		+ ((win->hum.pos.x + 16) / 32);
	curr = clock();
	while (curr - prev < CLOCKS_PER_SEC / SPEED)
		curr = clock();
	prev = curr;
	if (win->hum.i != -1)
		move_player(win, win->hum.pos, 0);
	else if (!win->bodyc && *sqr == 22)
		game_over(win);
	else if (*sqr == 18 || *sqr == 19 || *sqr == 20 || *sqr == 21)
		clean_corpse(win, sqr, 0);
	else
		move_player(win, win->hum.pos, 1);
	if (win->nbad)
		move_enemy(win);
	drawchars(win);
	if (loser(win))
		game_over(win);
	mpitw(win, win->scr.iid, 0, 0);
	return (show_moves(win));
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
	else if (next[reset] == 8 * !reset && sync[reset] == 8)
		next[reset] = 1;
	else if (next[reset] == 1 && sync[reset] == 16)
		next[reset] = 1 + 8 * !reset;
	else if (sync[reset] == 24)
		next[reset] = 0;
	sync[reset] = (sync[reset] + 1) % 32;
	win->hum.aff = step + next[reset];
}
