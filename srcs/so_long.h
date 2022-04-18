/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/19 00:57:28 by afuchs           ###   ########.fr       */
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
# define MOVE_UP 0xd
# define MOVE_DOWN 0x1
# define MOVE_LEFT 0x0
# define MOVE_RIGHT 0x2
# define ESCAPE 0x35
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

struct					s_coo
{
	int	x;
	int	y;
};
typedef struct s_coo	t_coo;
struct					s_img
{
	void	*iid;
	char	*fpx;
	int		w;
	int		h;
	int		bpp;
	int		sil;
	int		end;
};
typedef struct s_img	t_img;
struct					s_guy
{
	t_img	spr[16];
	t_coo	pos;
	int		k[4];
	int		i;
};
typedef struct s_guy	t_guy;
struct					s_dat
{
	void	*cid;
	void	*wid;
	int		w;
	int		h;
	char	*tit;
	t_guy	hum;
	char	**map;
};
typedef struct s_dat	t_dat;

t_dat	*open_win(int x, int y, char *title);
void	close_and_exit(t_dat *win);
void	kd_event(int keycode, t_dat *win);
void	ku_event(int keycode, t_dat *win);
void	load_player(t_dat *win, int x, int y);
void	free_player(t_dat *win);
void	animate(t_dat *win);
t_coo	set_coo(int x, int y);
void	move_player(t_dat *win, int reset);
int		mpitw(t_dat *win, void *img_ptr, int x, int y);
void	*mxfti(void *mlx_ptr, char *filename, int *width, int *height);
char	*mgda(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int		get_map(char *mapname, char ***map);
//int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*f)(), void *p);
#endif
