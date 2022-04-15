/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:34 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/15 20:26:59 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	get_sprites(t_dat *win)
{
	t_img	*pl;

	pl = win->hum.spr;
	pl[0].iid = MXFTI(win->cid, "pix/Fidle1.xpm", &pl[0].w, &pl[0].h);
	pl[1].iid = MXFTI(win->cid, "pix/Fidle2.xpm", &pl[1].w, &pl[1].h);
	pl[2].iid = MXFTI(win->cid, "pix/Ridle1.xpm", &pl[2].w, &pl[2].h);
	pl[3].iid = MXFTI(win->cid, "pix/Ridle2.xpm", &pl[3].w, &pl[3].h);
	pl[4].iid = MXFTI(win->cid, "pix/Lidle1.xpm", &pl[4].w, &pl[4].h);
	pl[5].iid = MXFTI(win->cid, "pix/Lidle2.xpm", &pl[5].w, &pl[5].h);
	pl[6].iid = MXFTI(win->cid, "pix/Bidle1.xpm", &pl[6].w, &pl[6].h);
	pl[7].iid = MXFTI(win->cid, "pix/Bidle2.xpm", &pl[7].w, &pl[7].h);
	pl[8].iid = MXFTI(win->cid, "pix/Fmove1.xpm", &pl[8].w, &pl[8].h);
	pl[9].iid = MXFTI(win->cid, "pix/Fmove2.xpm", &pl[9].w, &pl[9].h);
	pl[10].iid = MXFTI(win->cid, "pix/Rmove1.xpm", &pl[10].w, &pl[10].h);
	pl[11].iid = MXFTI(win->cid, "pix/Rmove2.xpm", &pl[11].w, &pl[11].h);
	pl[12].iid = MXFTI(win->cid, "pix/Lmove1.xpm", &pl[12].w, &pl[12].h);
	pl[13].iid = MXFTI(win->cid, "pix/Lmove2.xpm", &pl[13].w, &pl[13].h);
	pl[14].iid = MXFTI(win->cid, "pix/Bmove1.xpm", &pl[14].w, &pl[14].h);
	pl[15].iid = MXFTI(win->cid, "pix/Bmove2.xpm", &pl[15].w, &pl[15].h);
}

void	load_player(t_dat *win, int x, int y)
{
	int		i;

	get_sprites(win);
	i = -1;
	while (++i < 16)
	{
		win->hum.spr[i].fpx = MGDA(win->hum.spr[i].iid, &win->hum.spr[i].bpp,
				&win->hum.spr[i].sil, &win->hum.spr[i].end);
	}
	win->hum.pos = set_coo(x, y);
	i = 0;
	while (i < 4)
		win->hum.k[i++] = 0;
	win->hum.i = -1;
}

void	free_player(t_dat *win)
{
	size_t	i;

	i = 0;
	while (i < 16)
		mlx_destroy_image(win->cid, win->hum.spr[i++].iid);
}
