/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:25:35 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/20 22:56:33 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	process_kinputs(t_dat *win)
{
	if (win->hum.i == -1)
		return (0);
	if (win->hum.k[win->hum.i] == MOVE_UP)
		win->hum.pos.y -= 1;
	else if (win->hum.k[win->hum.i] == MOVE_DOWN)
		win->hum.pos.y += 1;
	else if (win->hum.k[win->hum.i] == MOVE_LEFT)
		win->hum.pos.x -= 1;
	else if (win->hum.k[win->hum.i] == MOVE_RIGHT)
		win->hum.pos.x += 1;
	if (win->hum.k[win->hum.i] == MOVE_UP)
		return (6);
	else if (win->hum.k[win->hum.i] == MOVE_DOWN)
		return (0);
	else if (win->hum.k[win->hum.i] == MOVE_LEFT)
		return (4);
	else
		return (2);
}

int	animate(t_dat *win)
{
	static clock_t	prev;
	clock_t			curr;

	//ft_printf("posx: %i | posy: %i\n", win->hum.pos.x, win->hum.pos.y);
	//ft_printf("k0: %x | k1: %x | k2: %x | k3: %x | ki: %i\n", win->hum.k[0], win->hum.k[1], win->hum.k[2], win->hum.k[3], win->hum.i);
	curr = clock();
	while (curr - prev < CLOCKS_PER_SEC / 60)
		curr = clock();
	prev = curr;
	if (win->hum.i != -1)
		move_player(win, 0);
	else
		move_player(win, 1);
	draw_map(win);
	mlx_do_sync(win->cid);
	return (0);
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
	mlx_clear_window(win->cid, win->wid);
	mpitw(win, win->hum.spr[step + next].iid, win->hum.pos.x, win->hum.pos.y);
}
