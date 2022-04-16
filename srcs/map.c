/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:01:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/16 23:40:58 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

static int	check_name(char *mapname)
{
	size_t	i;

	i = ft_strlen(mapname);
	if (i >= 5)
		if (*(mapname + i - 1) == 'r')
			if(*(mapname + i - 2) == 'e')
				if(*(mapname + i - 3) == 'b')
					if(*(mapname + i - 4) == '.')
						return (1);
	return (0);
}

static int	check_line(char *line, int *cep, size_t *size)
{
	size_t	i;
	int		only_ones;

	if (!line || *line != '1')
		return (0);
	i = 1;
	only_ones = 2;
	while (*(line + i) && *(line + i) != '\n')
	{
		if (!check_char(*(line + i)))
			return (0);
		if (only_ones == 2 && *(line + i) != '1')
			only_ones = 1;
		if (!cep[0] && *(line + i) == 'C')
			cep[0] = 1;
		else if (!cep[1] && *(line + i) == 'E')
			cep[1] = 1;
		else if (!cep[2] && *(line + i) == 'P')
			cep[2] = 1;
		i++;
	}
	if (*(line + i - 1) != '1')
		return (0);
	*size = i;
	return (only_ones);
}
/*NORMINETTE/!\*/
static char	**check_map(int fd, int *cep, size_t *size, int row)
{
	char	**map;
	char	*line;
	int		only_ones;

	line = get_next_line(fd);
	if (line)
	{
		only_ones = check_line(line, cep, size + 1);
		if (!only_ones)
			return (return_and_free((void *)0, line));
		if (!*size)
			*size = *(size + 1);
		else if (*size != *(size + 1))
			return (return_and_free((void *)0, line));
		map = check_map(fd, cep, size, row + 1);
		if (!map)
			return (return_and_free((void *)0, line));
		if ((!*(map + row + 1) || !row) && only_ones != 2)
			return (return_and_free(return_and_free((void *)0, line), map));
		*(map + row) = line;
		return (map);
	}
	if (!*cep || !*(cep + 1) || !*(cep + 2))
		return ((void *)0);
	map = ft_calloc(row + 1, sizeof (char *));
	*(map + row) = line;
	return (map);
}

int	get_map(char *mapname, char ***map)
{
	int		fd;
	int		cep[3];
	size_t	size[2];

	if (!check_name(mapname))
		return (1);
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return (2);
	ft_bzero(cep, 3 * sizeof (int));
	ft_bzero(size, 2 * sizeof (size_t));
	*map = check_map(fd, cep, size, 0);
	if (!*map)
		return (3);
	if (close(fd) == -1)
		return (4);
	return (0);
}
