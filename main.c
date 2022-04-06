/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:57:42 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 12:48:54 by afuchs           ###   ########.fr       */
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

t_win	*open_win()
{
	t_win	*scr;

	scr = ft_calloc(1, sizeof (t_win));
	scr->cid = mlx_init();
	scr->wid = mlx_new_window(scr->cid, 600, 500, "so_long");
	return (scr);
}

int	main(void)
{
	t_win	*scr;

	scr = open_win();
	mlx_key_hook(scr->wid, ((int (*)())&esc_win), scr);
	mlx_loop(scr->cid);
	return (0);
}
