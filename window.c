/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:52:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 16:11:39 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_dat	*open_win(int x, int y, char *title)
{
	t_dat	*scr;

	scr = ft_calloc(1, sizeof (t_dat));
	scr->cid = mlx_init();
	scr->wid = mlx_new_window(scr->cid, x, y, title);
	return (scr);
}

void	close_and_exit(t_dat *scr)
{
	mlx_clear_window(scr->cid, scr->wid);
	mlx_destroy_window(scr->cid, scr->wid);
	free(scr);
	exit(EXIT_SUCCESS);
}
