/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:40:11 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:41:46 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_bad	*another_dir(t_bad *bad)
{
	int	tried;
	int	*next_try;
	int	i;
	int	j;

	bad->tr[bad->step / 2] = 1;
	tried = bad->tr[0] + bad->tr[1] + bad->tr[2] + bad->tr[3];
	if (tried == 4)
		return (bad);
	next_try = ft_calloc(4 - tried, sizeof (int));
	i = -1;
	j = 0;
	while (++i < 4 - tried)
	{
		while (*(bad->tr + j))
			j++;
		*(next_try + i) = j * 2;
		j++;
	}
	bad->step = *(next_try + rng(4 - tried));
	return (bad);
}
