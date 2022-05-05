/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:31:49 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/05 17:55:47 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	iscolor(char *byte)
{
	if (!*byte && !*(byte + 1) && !*(byte + 2) && *(byte + 3) == -1)
		return (0);
	return (1);
}

void	putscr(t_img scr, t_img img, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 32)
	{
		while (++j < 32 * scr.bpp / 8)
		{
			if (iscolor(img.fpx + j + (i * img.sil)))
				*(scr.fpx + (x * scr.bpp / 8) + j + ((y + i) * scr.sil))
					= *(img.fpx + j + (i * img.sil));
			else
				j += 3;
		}
		j = -1;
	}
}
