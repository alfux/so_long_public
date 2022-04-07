/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/07 17:55:14 by afuchs           ###   ########.fr       */
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

struct					s_img
{
	void	*iid;
	char	*fpx;
	int		bpp;
	int		sil;
	int		end;
};
typedef struct s_img	t_img;

struct					s_dat
{
	void	*cid;
	void	*wid;
	int		w;
	int		h;
	char	*title;
	t_img	*img;
};
typedef struct s_dat	t_dat;

t_dat	*open_win(int x, int y, char *title);
void	close_and_exit(t_dat *win);
void	k_event(int keycode, t_dat *win);
//int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*f)(), void *p);
#endif
