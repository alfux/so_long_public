/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:55:29 by afuchs            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_coo	set_coo(int x, int y)
{
	t_coo	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void	frame_sync(clock_t start, clock_t end)
{
	clock_t	time;

	time = clock();
	while (time - start < end)
		time = clock();
}

void	animate(t_dat *win)
{
}
