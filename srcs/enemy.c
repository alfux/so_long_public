/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:48:26 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:47:36 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	rng(size_t range)
{
	static size_t	rng;

	if (range <= 1)
		return (0);
	rng = rng + ((size_t)clock() % 2) * (size_t)clock() + (size_t)(&range);
	return (rng % range);
}

static void	nenemy(t_dat *win, size_t *freespaces)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	win->nbad = 0;
	win->bad = (void *)0;
	while (i < win->map.h)
	{
		while (j < win->map.w)
			if (*(*(win->map.imap + i) + j++) == 13)
				win->nbad++;
		j = 0;
		i++;
	}
	*freespaces = win->nbad - 1;
	win->nbad = rng(win->nbad / 20);
}

static void	do_i_put(t_dat *win, size_t *case_number, size_t *fs, t_coo pos)
{
	size_t	i;

	i = 0;
	pos.x *= 32;
	pos.y *= 32;
	while (i < win->nbad)
	{
		if (*(case_number + i) == *fs)
		{
			if (pos.x != win->hum.pos.x || pos.y != win->hum.pos.y)
			{
				(*(win->bad + i)).pos = pos;
				(*(win->bad + i)).next = 0;
				(*(win->bad + i)).sync = 0;
				(*(win->bad + i)).step = 0;
			}
			else
				*(case_number + i) += 1;
		}
		i++;
	}
	*fs += 1;
}

static void	putenemy(t_dat *win)
{
	size_t	freespace;
	size_t	*case_number;
	size_t	i;
	size_t	j;

	nenemy(win, &freespace);
	if (!freespace || !win->nbad)
		return ;
	case_number = ft_calloc(win->nbad, sizeof (size_t));
	win->bad = ft_calloc(win->nbad, sizeof (t_bad));
	i = 0;
	while (i < win->nbad)
		*(case_number + i++) = rng(freespace);
	i = -1;
	j = -1;
	freespace = 0;
	while (++i < win->map.h)
	{
		while (++j < win->map.w)
			if (*(*(win->map.imap + i) + j) == 13)
				do_i_put(win, case_number, &freespace, set_coo(j, i));
		j = -1;
	}
	free(case_number);
}

//Supprimable
void	show_enemy(t_dat *win)
{
	size_t	i;

	i = 0;
	putenemy(win);
	while (i < win->nbad)
	{
		ft_printf("Ennemy %i: x%i y%i\n",
			i, win->bad[i].pos.x, win->bad[i].pos.y);
		i++;
	}
}

static void	enemy_step(t_dat *win, t_bad *bad)
{
	bad->curr = clock();
	if (bad->curr - bad->prev > CLOCKS_PER_SEC * (1 + (clock_t)rng(3)))
	{
		bad->prev = bad->curr;
		bad->step = rng(4) * 2;
		ft_printf("bad->step: %i\n", bad->step);
	}
	if (bad->prev)
	{
		bad->prev_pos = bad->pos;
		if (bad->step == 6)
			bad->pos.y += can_it_move(win, bad->pos, 0, -1);
		else if (bad->step == 0)
			bad->pos.y += can_it_move(win, bad->pos, 0, 1);
		else if (bad->step == 4)
			bad->pos.x += can_it_move(win, bad->pos, -1, 0);
		else
			bad->pos.x += can_it_move(win, bad->pos, 1, 0);
		if (bad->prev_pos.x == bad->pos.x && bad->prev_pos.y == bad->pos.y
			&& !(bad->tr[0] && bad->tr[1] && bad->tr[2] && bad->tr[3]))
			enemy_step(win, another_dir(bad));
		else
			ft_bzero(bad->tr, 4 * sizeof (int));
	}
}

void	move_enemy(t_dat *win)
{
	size_t	i;

	i = -1;
	while (++i < win->nbad)
	{
		redraw_zone(win, (*(win->bad + i)).pos);
		redraw_wall(win, (*(win->bad + i)).pos);
	}
	i = -1;
	while (++i < win->nbad)
	{
		enemy_step(win, win->bad + i);
		if (!(*(win->bad + i)).next && !(*(win->bad + i)).sync)
			(*(win->bad + i)).next = 8;
		else if ((*(win->bad + i)). next == 8 && (*(win->bad + i)).sync == 8)
			(*(win->bad + i)).next = 1;
		else if ((*(win->bad + i)). next == 1 && (*(win->bad + i)).sync == 16)
			(*(win->bad + i)).next = 9;
		else if ((*(win->bad + i)). next == 9 && (*(win->bad + i)).sync == 24)
			(*(win->bad + i)).next = 0;
		(*(win->bad + i)).sync = ((*(win->bad + i)).sync + 1) % 32;
		mpitw(win,
			win->hum.spr[(*(win->bad + i)).step + (*(win->bad + i)).next].iid,
			(*(win->bad + i)).pos.x, (*(win->bad + i)).pos.y);
	}
}
