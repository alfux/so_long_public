/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/05 17:12:41 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <math.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	mlx = mlx_init();
	mlx = mlx_new_window(mlx, 500, 500, "Hi mofos");
	mlx_loop(mlx);
	return (0);
}
