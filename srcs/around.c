/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   around.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:07:38 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/21 01:52:18 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	triple_wall(char a[4])
{
	if (a[0] != '1' && a[1] != '1' && a[2] != '1' && a[3] == '1')
		return (8);
	else if (a[0] != '1' && a[1] != '1' && a[2] == '1' && a[3] != '1')
		return (11);
	else if (a[0] != '1' && a[1] == '1' && a[2] != '1' && a[3] != '1')
		return (10);
	else// (a[0] == '1' && a[1] != '1' && a[2] != '1' && a[3] != '1')
		return (9);
}

static char	double_wall(char a[4])
{
	if (a[0] != '1' && a[1] != '1' && a[2] == '1' && a[3] == '1')
		return (6);
	else if (a[0] != '1' && a[1] == '1' && a[2] != '1' && a[3] == '1')
		return (17);
	else if (a[0] != '1' && a[1] == '1' && a[2] == '1' && a[3] != '1')
		return (5);
	else if (a[0] == '1' && a[1] != '1' && a[2] != '1' && a[3] == '1')
		return (7);
	else if (a[0] == '1' && a[1] != '1' && a[2] == '1' && a[3] != '1')
		return (16);
	else// (a[0] == '1' && a[1] == '1' && a[2] != '1' && a[3] != '1')
		return (4);
}

static char	simple_wall(char a[4])
{
	if (a[0] != '1' && a[1] == '1' && a[2] == '1' && a[3] == '1')
		return (1);
	else if (a[0] == '1' && a[1] != '1' && a[2] == '1' && a[3] == '1')
		return (2);
	else if (a[0] == '1' && a[1] == '1' && a[2] != '1' && a[3] == '1')
		return (3);
	else//  (a[0] == '1' && a[1] == '1' && a[2] == '1' && a[3] != '1')
		return (0);
}

char	around(char **map, size_t i, size_t j)
{
    char	a[4];
	char	k;
	char	no_one;

	a[0] = *(*(map + i) + j + 1);
	a[1] = *(*(map + i - 1) + j);
	a[2] = *(*(map + i) + j - 1);
	a[3] = *(*(map + i + 1) + j);
	no_one = 0;
	k = 0;
	while (k < 4)
		if (a[(int)k++] != '1')
			no_one++;
	if (!no_one)
		return (15);
	else if (no_one == 1)
		return (simple_wall(a));
	else if (no_one == 2)
		return (double_wall(a));
	else if (no_one == 3)
		return (triple_wall(a));
	else
		return (12);
}
