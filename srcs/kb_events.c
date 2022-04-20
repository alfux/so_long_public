/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:47:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/19 17:38:32 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	add_kbool(int keycode, t_dat *win)
{
	int	i;

	i = 0;
	while (i < 4 && win->hum.k[i] >= 0)
		i++;
	if (keycode == MOVE_UP || keycode == MOVE_DOWN
		|| keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
	{
		if (!i)
			win->hum.k[i] = keycode;
		else if (i < 4 && win->hum.k[i - 1] != keycode)
			win->hum.k[i] = keycode;
	}
	if (i < 4 && win->hum.k[i] >= 0)
		win->hum.i = i;
	else
		win->hum.i = i - 1;
}

static void	rem_kbool(int keycode, t_dat *win)
{
	size_t	i;

	i = 0;
	while (i < 4 && win->hum.k[i] != keycode && win->hum.k[i] >= 0)
		i++;
	if (i < 4)
		win->hum.k[i] = -1;
	while (i + 1 < 4 && win->hum.k[i + 1] >= 0)
	{
		win->hum.k[i] = win->hum.k[i + 1];
		win->hum.k[i + 1] = -1;
		i++;
	}
	win->hum.i = i - 1;
}

int	kd_event(int keycode, t_dat *win)
{
	ft_printf("%sKeycode: %#x\n%s", YELLOW, keycode, WHITE);
	if (keycode == ESCAPE)
		close_and_exit(win);
	add_kbool(keycode, win);
	return (0);
}

int	ku_event(int keycode, t_dat *win)
{
	rem_kbool(keycode, win);
	return (0);
}
