/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:01:19 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/16 19:56:01 by afuchs           ###   ########.fr       */
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

static int	check_line(char *line, int *cep)
{
	size_t	i;
	int		only_ones;

	if (*line != '1')
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
	return (only_ones);
}

static int	check_map(int fd)
{
	char	*prev;
	char	*curr;
	int		cep[3];
	size_t	i;

	i = 0;
	while (i < 3)
		cep[i++] = 0;
	i = 0;
	curr = get_next_line(fd);
}

int	err_map(char *mapname)
{
	int	fd;

	if (!check_name(mapname))
		return (1);
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		return (2);
	if (!check_map(fd))
		return (3);
	if (close(fd) == -1)
		return (4);
	return (0);
}
