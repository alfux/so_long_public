/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:29:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/20 22:39:51 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	draw_map(t_dat *win)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < win->map.h)
	{
		while (j < win->map.w)
		{
			mpitw(win, win->map.pix[(int)*(*(win->map.imap + i) + j)].iid,
			j * 32, i * 32);
			j++;
		}
		i++;
		j = 0;
	}
}
