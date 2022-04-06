/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:47:54 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 18:35:02 by afuchs           ###   ########.fr       */
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
}
