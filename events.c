/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:47:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 17:38:38 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

unsigned int	argb(int a, int r, int g, int b)
{
	return ((a << 24) + (r << 16) + (g << 8) + (b % 256));
}

void	k_event(int keycode, t_dat *scr)
{
	static int	a;
	static int	r;
	static int	g;
	static int	b;

	ft_printf("Keycode: %x\n", keycode);
	ft_printf("Color_int: %i\n", scr->col);
	if (keycode == 0x35)
		close_and_exit(scr);
	else if (keycode == 0x7b)
		r = (r + 1) % 256;
	else if (keycode == 0x7e)
		g = (g + 1) % 256;
	else if (keycode == 0x7c)
		b = (b + 1) % 256;
	else if (keycode == 0x7d)
		a = (a + 1) % 256;
	ft_printf("a: %i | R: %i | G: %i | B: %i\n", a, r, g, b);
	mlx_clear_window(scr->cid, scr->wid);
}
