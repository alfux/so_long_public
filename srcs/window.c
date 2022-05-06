/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:52:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/06 16:05:50 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_player(t_dat *win)
{
	size_t	i;

	i = 0;
	while (i < 19)
		mlx_destroy_image(win->cid, win->hum.spr[i++].iid);
}

void	free_map(t_dat *win)
{
	size_t	i;

	i = 0;
	while (i < win->map.h)
		free(*(win->map.imap + i++));
	free(win->map.imap);
	i = 0;
	while (i < 28)
		mlx_destroy_image(win->cid, win->map.pix[i++].iid);
}

t_dat	*open_win(char **map, char *title)
{
	t_dat	*win;

	win = ft_calloc(1, sizeof (t_dat));
	win->cid = mlx_init();
	win->bodyc = 0;
	win->expos = set_coo(0, 0);
	load(win, map);
	win->w = win->map.w * 32;
	win->h = win->map.h * 32;
	win->wid = mlx_new_window(win->cid, win->w, win->h, title);
	win->tit = ft_strdup(title);
	win->moves = 0;
	win->wl = 1;
	win->scr.iid = mlx_new_image(win->cid, win->w, win->h);
	win->scr.fpx = mgda(win->scr.iid, &win->scr.bpp, &win->scr.sil,
			&win->scr.end);
	return (win);
}

int	close_and_exit(t_dat *win)
{
	mlx_clear_window(win->cid, win->wid);
	free_player(win);
	free_map(win);
	mlx_destroy_image(win->cid, win->scr.iid);
	mlx_destroy_window(win->cid, win->wid);
	free(win->tit);
	free(win->bad);
	free(win->drw);
	free(win->bodies);
	free(win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	game_over(t_dat *win)
{
	char		*moves;
	static int	twice;

	if (twice < 2)
	{
		twice++;
		mlx_clear_window(win->cid, win->wid);
		moves = ft_itoa(win->moves / 32);
		if (win->wl)
		{
			mlx_string_put(win->cid, win->wid, win->w / 2 - 32, win->h / 2,
				0xFFFFFFFF, "YOU WIN");
			mlx_string_put(win->cid, win->wid, win->w / 2 - 32,
				(win->h / 2) + 32, 0xFFFFFFFF, "Moves:");
			mlx_string_put(win->cid, win->wid, (win->w / 2) + 32,
				(win->h / 2) + 32, 0xFFFFFFFF, moves);
		}
		else
			mlx_string_put(win->cid, win->wid, win->w / 2 - 32, win->h / 2,
				0xFFFF0000, "YOU DIED");
		free(moves);
		mlx_loop_hook(win->cid, &game_over, win);
	}
	return (0);
}
