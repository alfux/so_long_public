/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:34 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/04 13:55:06 by afuchs           ###   ########.fr       */
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

static void	get_corpse_and_pod(t_dat *win)
{
	t_img	*pl;

	pl = win->map.pix;
	pl[18].iid = mxfti(win->cid, "pix/Corpse1.xpm", &pl[18].w, &pl[18].h);
	pl[19].iid = mxfti(win->cid, "pix/Corpse2.xpm", &pl[19].w, &pl[19].h);
	pl[20].iid = mxfti(win->cid, "pix/Corpse3.xpm", &pl[20].w, &pl[20].h);
	pl[21].iid = mxfti(win->cid, "pix/Corpse4.xpm", &pl[21].w, &pl[21].h);
	pl[22].iid = mxfti(win->cid, "pix/Pod1.xpm", &pl[22].w, &pl[22].h);
	pl[23].iid = mxfti(win->cid, "pix/Pod2.xpm", &pl[23].w, &pl[23].h);
	pl[24].iid = mxfti(win->cid, "pix/Pod3.xpm", &pl[24].w, &pl[24].h);
	pl[25].iid = mxfti(win->cid, "pix/Pod4.xpm", &pl[25].w, &pl[25].h);
	pl[26].iid = mxfti(win->cid, "pix/Pod5.xpm", &pl[26].w, &pl[26].h);
	pl[27].iid = mxfti(win->cid, "pix/Pod6.xpm", &pl[27].w, &pl[27].h);
}

static void	get_mapix(t_dat *win)
{
	t_img	*pl;

	pl = win->map.pix;
	pl[0].iid = mxfti(win->cid, "pix/WallD.xpm", &pl[0].w, &pl[0].h);
	pl[1].iid = mxfti(win->cid, "pix/WallR.xpm", &pl[1].w, &pl[1].h);
	pl[2].iid = mxfti(win->cid, "pix/WallU.xpm", &pl[2].w, &pl[2].h);
	pl[3].iid = mxfti(win->cid, "pix/WallL.xpm", &pl[3].w, &pl[3].h);
	pl[4].iid = mxfti(win->cid, "pix/WallDL.xpm", &pl[4].w, &pl[4].h);
	pl[5].iid = mxfti(win->cid, "pix/WallDR.xpm", &pl[5].w, &pl[5].h);
	pl[6].iid = mxfti(win->cid, "pix/WallUR.xpm", &pl[6].w, &pl[6].h);
	pl[7].iid = mxfti(win->cid, "pix/WallUL.xpm", &pl[7].w, &pl[7].h);
	pl[8].iid = mxfti(win->cid, "pix/WallLUR.xpm", &pl[8].w, &pl[8].h);
	pl[9].iid = mxfti(win->cid, "pix/WallDLU.xpm", &pl[9].w, &pl[9].h);
	pl[10].iid = mxfti(win->cid, "pix/WallLDR.xpm", &pl[10].w, &pl[10].h);
	pl[11].iid = mxfti(win->cid, "pix/WallURD.xpm", &pl[11].w, &pl[11].h);
	pl[12].iid = mxfti(win->cid, "pix/Pillar.xpm", &pl[12].w, &pl[12].h);
	pl[13].iid = mxfti(win->cid, "pix/Floor.xpm", &pl[13].w, &pl[13].h);
	pl[14].iid = mxfti(win->cid, "pix/BloodyFloor.xpm", &pl[14].w, &pl[14].h);
	pl[15].iid = mxfti(win->cid, "pix/WallC.xpm", &pl[15].w, &pl[15].h);
	pl[16].iid = mxfti(win->cid, "pix/WallUD.xpm", &pl[16].w, &pl[16].h);
	pl[17].iid = mxfti(win->cid, "pix/WallLR.xpm", &pl[17].w, &pl[17].h);
	get_corpse_and_pod(win);
}

static void	get_sprites(t_dat *win)
{
	t_img	*pl;

	pl = win->hum.spr;
	pl[0].iid = mxfti(win->cid, "pix/Fidle1.xpm", &pl[0].w, &pl[0].h);
	pl[1].iid = mxfti(win->cid, "pix/Fidle2.xpm", &pl[1].w, &pl[1].h);
	pl[2].iid = mxfti(win->cid, "pix/Ridle1.xpm", &pl[2].w, &pl[2].h);
	pl[3].iid = mxfti(win->cid, "pix/Ridle2.xpm", &pl[3].w, &pl[3].h);
	pl[4].iid = mxfti(win->cid, "pix/Lidle1.xpm", &pl[4].w, &pl[4].h);
	pl[5].iid = mxfti(win->cid, "pix/Lidle2.xpm", &pl[5].w, &pl[5].h);
	pl[6].iid = mxfti(win->cid, "pix/Bidle1.xpm", &pl[6].w, &pl[6].h);
	pl[7].iid = mxfti(win->cid, "pix/Bidle2.xpm", &pl[7].w, &pl[7].h);
	pl[8].iid = mxfti(win->cid, "pix/Fmove1.xpm", &pl[8].w, &pl[8].h);
	pl[9].iid = mxfti(win->cid, "pix/Fmove2.xpm", &pl[9].w, &pl[9].h);
	pl[10].iid = mxfti(win->cid, "pix/Rmove1.xpm", &pl[10].w, &pl[10].h);
	pl[11].iid = mxfti(win->cid, "pix/Rmove2.xpm", &pl[11].w, &pl[11].h);
	pl[12].iid = mxfti(win->cid, "pix/Lmove1.xpm", &pl[12].w, &pl[12].h);
	pl[13].iid = mxfti(win->cid, "pix/Lmove2.xpm", &pl[13].w, &pl[13].h);
	pl[14].iid = mxfti(win->cid, "pix/Bmove1.xpm", &pl[14].w, &pl[14].h);
	pl[15].iid = mxfti(win->cid, "pix/Bmove2.xpm", &pl[15].w, &pl[15].h);
	pl[16].iid = mxfti(win->cid, "pix/Clean1.xpm", &pl[16].w, &pl[16].h);
	pl[17].iid = mxfti(win->cid, "pix/Clean2.xpm", &pl[17].w, &pl[17].h);
	pl[18].iid = mxfti(win->cid, "pix/Clean3.xpm", &pl[18].w, &pl[18].h);
}

void	load(t_dat *win, char **map)
{
	int		i;

	get_sprites(win);
	get_mapix(win);
	i = -1;
	while (++i < 16)
	{
		win->hum.spr[i].fpx = mgda(win->hum.spr[i].iid, &win->hum.spr[i].bpp,
				&win->hum.spr[i].sil, &win->hum.spr[i].end);
	}
	i = 0;
	while (i < 4)
		win->hum.k[i++] = -1;
	win->hum.i = -1;
	i = -1;
	while (++i < 18)
	{
		win->map.pix[i].fpx = mgda(win->map.pix[i].iid, &win->map.pix[i].bpp,
				&win->map.pix[i].sil, &win->map.pix[i].end);
	}
	process_map(win, map);
}
