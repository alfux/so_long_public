/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:40:11 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/05 18:00:32 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_bad	*another_dir(t_bad *bad)
{
	int	tried;
	int	*next_try;
	int	i;
	int	j;

	bad->tr[bad->step / 2] = 1;
	tried = bad->tr[0] + bad->tr[1] + bad->tr[2] + bad->tr[3];
	if (tried == 4)
		return (bad);
	next_try = ft_calloc(4 - tried, sizeof (int));
	i = -1;
	j = 0;
	while (++i < 4 - tried)
	{
		while (*(bad->tr + j))
			j++;
		*(next_try + i) = j * 2;
		j++;
	}
	bad->step = *(next_try + rng(4 - tried));
	free(next_try);
	return (bad);
}

void	drwtab(t_dat *win)
{
	size_t	i;

	win->drw = ft_calloc(win->nbad + 1, sizeof (t_drw));
	i = 0;
	while (++i < win->nbad + 1)
	{
		(*(win->drw + i)).pos = &(*(win->bad + i - 1)).pos;
		(*(win->drw + i)).aff = &(*(win->bad + i - 1)).aff;
	}
	(*win->drw).pos = &win->hum.pos;
	(*win->drw).aff = &win->hum.aff;
	i = -1;
}

static void	reorder_chars(t_dat *win, t_drw *drw)
{
	static size_t	i;
	t_drw			buf;

	if (i + 1 >= win->nbad + 1)
		return ;
	if ((*(*(drw + i)).pos).y > (*(*(drw + i + 1)).pos).y)
	{
		buf = *(drw + i);
		*(drw + i) = *(drw + i + 1);
		*(drw + i + 1) = buf;
		i = 0;
		reorder_chars(win, drw);
	}
	else
	{
		i++;
		reorder_chars(win, drw);
	}
	i = 0;
}

void	drawchars(t_dat *win)
{
	size_t	i;

	reorder_chars(win, win->drw);
	i = -1;
	while (++i < win->nbad + 1)
		redraw_zone(win, *(*(win->drw + i)).pos);
	if (!win->bodyc)
		open_exit(win);
	i = -1;
	while (++i < win->nbad + 1)
	{
		putscr(win->scr, win->hum.spr[*(*(win->drw + i)).aff],
			(*(*(win->drw + i)).pos).x, (*(*(win->drw + i)).pos).y);
		redraw_wall(win, *(*(win->drw + i)).pos);
	}
}

int	loser(t_dat *win)
{
	size_t	i;

	i = 0;
	while (i < win->nbad)
	{
		if (((win->hum.pos.x - win->bad[i].pos.x)
				* (win->hum.pos.x - win->bad[i].pos.x))
			+ ((win->hum.pos.y - win->bad[i].pos.y)
				* (win->hum.pos.y - win->bad[i].pos.y)) <= 256)
		{
			win->wl = 0;
			return (1);
		}
		i++;
	}
	return (0);
}
