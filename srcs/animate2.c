/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:25:12 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/23 18:25:42 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	clean_corpse(t_dat *win)
{
	static int	next;
	static int	sync;

	if (!sync)
		next = 16;
	else if	(sync == 8)
		next = 17;
	else if (sync == 16)
		next = 18;
	else if (sync == 24)
		next = 17;
	sync = (sync + 1) % 32;
	mpitw(win, win->hum.spr[next].iid, win->hum.pos.x, win->hum.pos.y);
}
