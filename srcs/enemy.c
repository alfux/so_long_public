/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:48:26 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/02 18:51:29 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	rng(size_t range)
{
	static size_t	rng;

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
				(*(win->bad + i)).pos = pos;
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
