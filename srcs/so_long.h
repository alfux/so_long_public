/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/05/08 16:37:03 by afuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# define MOVE_UP 0xd
# define MOVE_DOWN 0x1
# define MOVE_LEFT 0x0
# define MOVE_RIGHT 0x2
# define ESCAPE 0x35
# define RED "\033[31m"
# define WHITE "\033[0m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
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
	int		aff;
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
	t_coo	prev_pos;
	int		dir;
	int		tr[4];
	int		next;
	int		sync;
	int		step;
	int		aff;
	clock_t	curr;
	clock_t	prev;
	clock_t	tbc;
};
typedef struct s_bad	t_bad;
struct					s_drw
{
	t_coo	*pos;
	int		*aff;
};
typedef struct s_drw	t_drw;
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
	t_coo	*bodies;
	t_coo	expos;
	size_t	moves;
	size_t	nbad;
	t_bad	*bad;
	t_drw	*drw;
	char	wl;
	t_img	scr;
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
void	redraw_zone(t_dat *win, t_coo pos);
int		can_it_move(t_dat *win, t_coo pos, int x, int y);
int		isobstacle(t_dat *win, size_t i, size_t j);
void	redraw_wall(t_dat *win, t_coo pos);
void	clean_corpse(t_dat *win, char *sqr, char abort);
void	open_exit(t_dat *win);
int		game_over(t_dat *win);
int		show_moves(t_dat *win);
size_t	rng(size_t range);
void	putenemy(t_dat *win);
void	move_enemy(t_dat *win);
t_bad	*another_dir(t_bad *bad);
void	drwtab(t_dat *win);
void	drawscr(t_dat *win);
int		loser(t_dat *win);
void	putscr(t_img scr, t_img img, int x, int y);
void	rand_exit(t_dat *win, t_coo add, char end);
void	rand_hum(t_dat *win, t_coo add, char end);
size_t	sqrdd(t_coo p, t_coo q);
t_coo	syncp(t_coo humpos);
char	isfree(char c);
void	bodytab(t_dat *win, t_coo add);
void	remove_body(t_dat *win, char *sqr);
void	blood_drop(t_dat *win);
char	near_corpse(t_dat *win);
#endif
