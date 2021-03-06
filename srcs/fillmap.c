/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:47:33 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/06 15:41:35 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	get_smap(t_dat *win, char **map)
{
	size_t	i;

	i = 0;
	win->map.h = 0;
	win->map.w = ft_strlen(*map);
	if (*(*map + win->map.w - 1) == '\n')
		win->map.w--;
	while (*(map + win->map.h))
		win->map.h++;
	win->map.imap = ft_calloc(win->map.h, sizeof (char *));
	while (i < win->map.h)
		*(win->map.imap + i++) = ft_calloc(win->map.w, sizeof (char));
}

static void	fill_firstlast(t_dat *win, char **map)
{
	size_t	i;

	i = 0;
	while (*(*map + i) != '\n' && *(*map + i))
	{
		if (*(*(map + 1) + i) == '1')
			*(*win->map.imap + i) = 15;
		else
			*(*win->map.imap + i) = 0;
		i++;
	}
	i = 0;
	while (*(*(map + win->map.h - 1) + i) != '\n'
		&& *(*(map + win->map.h - 1) + i))
	{
		if (*(*(map + win->map.h - 2) + i) == '1')
			*(*(win->map.imap + win->map.h - 1) + i) = 15;
		else
			*(*(win->map.imap + win->map.h - 1) + i) = 2;
		i++;
	}
}

static void	fill_lfirstlast(t_dat *win, char **map, size_t i)
{
	if (*(*(map + i) + 1) == '1')
		**(win->map.imap + i) = 15;
	else
		**(win->map.imap + i) = 1;
	if (*(*(map + i) + win->map.w - 2) == '1')
		*(*(win->map.imap + i) + win->map.w - 1) = 15;
	else
		*(*(win->map.imap + i) + win->map.w - 1) = 3;
}

static void	fill_line(t_dat *win, char **map, size_t i, size_t j)
{
	fill_lfirstlast(win, map, i);
	while (++j < win->map.w - 1)
	{
		if (*(*(map + i) + j) == '1')
			*(*(win->map.imap + i) + j) = around(map, i, j);
		else if (*(*(map + i) + j) == 'P')
		{
			*(*(win->map.imap + i) + j) = 13;
			rand_hum(win, set_coo(j * 32, i * 32), 0);
		}
		else if (*(*(map + i) + j) == 'E')
		{
			*(*(win->map.imap + i) + j) = 22;
			rand_exit(win, set_coo(j * 32, i * 32), 0);
		}
		else if (*(*(map + i) + j) == 'C')
		{
			*(*(win->map.imap + i) + j) = 18;
			bodytab(win, set_coo(j * 32, i * 32));
		}
		else
			*(*(win->map.imap + i) + j) = 13;
	}
}

void	process_map(t_dat *win, char **map)
{
	size_t	i;

	i = 0;
	get_smap(win, map);
	fill_firstlast(win, map);
	while (++i < win->map.h - 1)
		fill_line(win, map, i, 0);
	rand_exit(win, set_coo(0, 0), 1);
	rand_hum(win, set_coo(0, 0), 1);
	i = 0;
	while (*(map + i))
		free(*(map + i++));
	free(map);
}
