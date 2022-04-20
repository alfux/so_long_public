/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <alexis.t.fuchs@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:47:33 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/20 16:39:56 by afuchs           ###   ########.fr       */
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
		if (*(*(map - 1) + i) == '1')
			*(*win->map.imap + i) = 15;
		else
			*(*win->map.imap + i) = 2;
		i++;
	}
}

static void	process_line(t_dat *win, char **map, size_t i, size_t j)
{
	//AFAIRE
}

static void	fill_line(t_dat *win, char **map, size_t i)
{
	size_t	j;
	char	*line;

	line = *(map + i);
	if (*(line + 1) == '1')
		**(win->map.imap + i) = 15;
	else
		**(win->map.imap + i) = 1;
	if (*(line + win->map.w - 2) == '1')
		*(*(win->map.imap + i) + win->map.w - 1) = 15;
	else
		*(*(win->map.imap + i) + win->map.w - 1) = 3;
	j = 0;
	while (++j < win->map.w - 1)
		*(*(win->map.imap + i) + j) = process_line(win, map, i, j);
}

static void	process_map(t_dat *win, char **map)
{
	size_t	i;

	i = 0;
	fill_firstlast(win, map);
	while (++i < win->map.h - 1)
		fill_line(win, map, i);
}
