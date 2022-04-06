/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 17:38:12 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define AF_KEYDOWN 2
# define AF_KEYUP 3
# define AF_MOUSEDOWN 4
# define AF_MOUSEUP 5
# define AF_MOUSEMOVE 6
# define AF_EXPOSE 12
# define AF_DESTROY 17
# include "libft/libft.h"
# include <mlx.h>

struct					s_dat
{
	void	*cid;
	void	*wid;
	void	*iid;
	char	*fpx;
	int		bpp;
	int		sil;
	int		end;
	int		col;
};
typedef struct s_dat	t_dat;

t_dat	*open_win(int x, int y, char *title);
void	close_and_exit(t_dat *scr);
void	k_event(int keycode, t_dat *scr);

#endif
