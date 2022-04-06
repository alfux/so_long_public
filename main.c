/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 12:23:36 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>

void	esc_win(int	keycode, t_win *scr)
{
	ft_printf("Keycode: %x\n", keycode);
	if (keycode == 0x35)
	{
		mlx_clear_window(scr->cid, scr->wid);
		mlx_destroy_window(scr->cid, scr->wid);
		exit(EXIT_SUCCESS);
	}
}

int	main(void)
{
	t_win	scr;

	scr.cid = mlx_init();
	scr.wid = mlx_new_window(scr.cid, 840, 380, "so_long");
	mlx_key_hook(scr.wid, ((int (*)())&esc_win), &scr);
	mlx_loop(scr.cid);
	return (0);
}
