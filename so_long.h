/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:24:29 by afuchs            #+#    #+#             */
/*   Updated: 2022/04/06 14:29:29 by afuchs           ###   ########.fr       */
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

struct					s_win
{
	void	*cid;
	void	*wid;
};
typedef struct s_win	t_win;

#endif
