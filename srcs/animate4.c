/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:13:45 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/06 17:50:19 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	bodytab(t_dat *win, t_coo add)
{
	size_t	i;
	t_coo	*tmp;

	win->bodyc++;
	tmp = ft_calloc(win->bodyc, sizeof (t_coo));
	i = -1;
	while (++i < win->bodyc - 1)
		*(tmp + i) = *(win->bodies + i);
	*(tmp + win->bodyc - 1) = add;
	free(win->bodies);
	win->bodies = tmp;
}

void	remove_body(t_dat *win, char *sqr)
{
	size_t	i;
	size_t	j;
	t_coo	*tmp;

	win->bodyc--;
	tmp = ft_calloc(win->bodyc, sizeof (t_coo));
	i = -1;
	j = 0;
	while (++i < win->bodyc + 1)
	{
		if (*(win->map.imap
			+ (win->bodies[i].y / 32))
			+ (win->bodies[i].x / 32) != sqr)
			*(tmp + i - j) = *(win->bodies + i);
		else
			j++;
	}
	free(win->bodies);
	win->bodies = tmp;
}

void	blood_drop(t_dat *win)
{
	static char 	sync;
	static size_t	which;
	static size_t	bchange;

	if((sync || rng(16) == 0) && win->bodyc)
	{
		sync = (sync + 1) % 32;
		if (sync == 1)
		{
			which = rng(win->bodyc);
			bchange = win->bodyc;
		}
		if (bchange != win->bodyc)
		{
			if(which)
				which--;
			sync = 0;
		}
		putscr(win->scr, win->map.pix[18 + (sync / 8)], win->bodies[which].x,
			win->bodies[which].y);
	}
}

char	near_corpse(t_dat *win)
{
	size_t	i;

	i = -1;
	while (++i < win->bodyc)
		if (sqrdd(syncp(win->hum.pos), *(win->bodies + i)) < 64)
			return (1);
	return (0);
}
