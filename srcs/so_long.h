/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/02 18:58:02 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define MOVE_UP 0x7a
# define MOVE_DOWN 0x73
# define MOVE_LEFT 0x71
# define MOVE_RIGHT 0x64
# define ESCAPE 0xff1b
# define SPEED 60
# define RED "\033[31m"
# define WHITE "\033[0m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <time.h>

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
	t_img	spr[19];
	t_coo	pos;
	int		k[4];
	int		i;
};
typedef struct s_guy	t_guy;
struct					s_map
{
	t_img	pix[28];
	char	**imap;
	size_t	h;
	size_t	w;
	t_coo	exit;
};
typedef struct s_map	t_map;
struct					s_bad
{
	t_coo	pos;
	int		dir;
};
typedef struct s_bad	t_bad;
struct					s_dat
{
	void	*cid;
	void	*wid;
	int		w;
	int		h;
	char	*tit;
	t_guy	hum;
	t_map	map;
	size_t	bodyc;
	t_coo	expos;
	size_t	moves;
	size_t	nbad;
	t_bad	*bad;
};
typedef struct s_dat	t_dat;

t_dat	*open_win(char **map, char *title);
int		close_and_exit(t_dat *win);
int		kd_event(int keycode, t_dat *win);
int		ku_event(int keycode, t_dat *win);
void	load(t_dat *win, char **map);
void	free_player(t_dat *win);
void	free_map(t_dat *win);
int		animate(t_dat *win);
t_coo	set_coo(int x, int y);
void	move_player(t_dat *win, t_coo start, int reset);
int		mpitw(t_dat *win, void *img_ptr, int x, int y);
void	*mxfti(void *mlx_ptr, char *filename, int *width, int *height);
char	*mgda(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
int		get_map(char *mapname, char ***map);
char	around(char **map, size_t i, size_t j);
void	process_map(t_dat *win, char **map);
void	draw_map(t_dat *win);
void	redraw_zone(t_dat *win);
int		isobstacle(t_dat *win, size_t i, size_t j);
void	redraw_wall(t_dat *win);
void	clean_corpse(t_dat *win, char *sqr, char abort);
void	open_exit(t_dat *win);
void	game_over(t_dat *win, char wl);
void	show_moves(t_dat *win);
size_t	rng(size_t range);
void	show_enemy(t_dat *win);
#endif
