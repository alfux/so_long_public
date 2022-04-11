/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:47:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/11 18:31:50 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

unsigned int	argb(int a, int r, int g, int b)
{
	return ((a << 24) + (r << 16) + (g << 8) + (b % 256));
}

void	k_event(int keycode, t_dat *win)
{
	ft_printf("Keycode: %x\n", keycode);
	if (keycode == 0x35)
		close_and_exit(win);
	else if (keycode == 0x7d)
		win->hum.tgt.y += 32;
	else if (keycode == 0x7e)
		win->hum.tgt.y -= 32;
	else if (keycode == 0x7b)
		win->hum.tgt.x -= 32;
	else if (keycode == 0x7c)
		win->hum.tgt.x += 32;
}
