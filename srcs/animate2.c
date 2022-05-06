/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:25:12 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/06 15:59:52 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	clean_corpse(t_dat *win, char *sqr, char abort)
{
	static int	nsf[3];

	if (nsf[2] >= 3 || abort)
	{
		ft_bzero(nsf, 3 * sizeof(int));
		if (!abort)
			remove_body(win, sqr);
		if (sqr)
		{
			*sqr = 13;
			move_player(win, win->hum.pos, 1);
		}
		return ;
	}
	if (!nsf[1] && nsf[2]++ < 3)
		nsf[0] = 16;
	else if (nsf[1] == 8)
		nsf[0] = 17;
	else if (nsf[1] == 16)
		nsf[0] = 18;
	else if (nsf[1] == 24)
		nsf[0] = 17;
	nsf[1] = (nsf[1] + 1) % 32;
	win->hum.aff = nsf[0];
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
	putscr(win->scr, win->map.pix[next], win->expos.x, win->expos.y);
}

void	rand_exit(t_dat *win, t_coo add, char end)
{
	size_t			i;
	static size_t	nex;
	static t_coo	*exits;
	t_coo			*tmp;

	if (!end)
	{
		nex++;
		tmp = ft_calloc(nex, sizeof (t_coo));
		i = -1;
		while (++i < nex - 1)
			*(tmp + i) = *(exits + i);
		*(tmp + nex - 1) = add;
		free(exits);
		exits = tmp;
	}
	else
	{
		win->expos = *(exits + rng(nex));
		free(exits);
	}
}

void	rand_hum(t_dat *win, t_coo add, char end)
{
	size_t			i;
	static size_t	nhu;
	static t_coo	*hum;
	t_coo			*tmp;

	if (!end)
	{
		nhu++;
		tmp = ft_calloc(nhu, sizeof (t_coo));
		i = -1;
		while (++i < nhu - 1)
			*(tmp + i) = *(hum + i);
		*(tmp + nhu - 1) = add;
		free(hum);
		hum = tmp;
	}
	else
	{
		win->hum.pos = *(hum + rng(nhu));
		free(hum);
	}
}

int	show_moves(t_dat *win)
{
	char	*moves;

	moves = ft_itoa(win->moves / 32);
	mlx_string_put(win->cid, win->wid, 5, 15, 0xFFFFFFFF, "MOVES: ");
	mlx_string_put(win->cid, win->wid, 69, 15, 0xFFFFFFFF, moves);
	free(moves);
	return (0);
}
