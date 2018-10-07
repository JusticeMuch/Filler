/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 08:26:36 by jronald           #+#    #+#             */
/*   Updated: 2018/07/31 10:20:53 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_fill
{
	char		**piece;
	char		**map;
	int			piece_x;
	int			piece_y;
	int			map_x;
	int			map_y;
	char		player;
	char		enemy;
	int			play_x;
	int			play_y;
	int			done;
	int			pm[1000][2];
	int			pm_size;
	int			moves;
}				t_fill;

int				lst_clear(t_fill **temp);
int				read_game(t_fill *g, int fd, char **line);
int				algo(t_fill *game);
void			store_move(t_fill *game, int y, int x);
int				get_closest_move(t_fill *g, int i);
#endif
