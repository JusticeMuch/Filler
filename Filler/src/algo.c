/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:41:45 by jronald           #+#    #+#             */
/*   Updated: 2018/07/31 10:18:29 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_move(t_fill *g, int my, int mx)
{
	int ovlap;
	int px;
	int py;

	py = -1;
	ovlap = 0;
	while (++py < g->piece_y)
	{
		px = -1;
		while (++px < g->piece_x)
		{
			if (g->piece[py][px] == '*')
			{
				if ((mx + px) >= g->map_x || (my + py) >= g->map_y)
					return (0);
				else if (g->map[my + py][mx + px] == g->player ||
						g->map[my + py][px + mx] == g->player - 32)
					ovlap++;
				else if (g->map[my + py][mx + px] != '.' || ovlap > 1)
					return (0);
			}
		}
	}
	return (ovlap == 1 ? 1 : 0);
}

void	get_moves(t_fill *game)
{
	int count;
	int x;
	int y;

	count = 0;
	y = -1;
	while (++y < game->map_y)
	{
		x = -1;
		while (++x < game->map_x)
		{
			if (check_move(game, y, x) == 1)
			{
				game->pm[count][0] = y;
				game->pm[count][1] = x;
				count++;
			}
		}
	}
	game->pm_size = count;
	if (count == 0)
		game->done = 1;
}

int		best_move(t_fill *g, int i)
{
	if (g->moves % 2 == 1)
		return (g->map_y - g->pm[i][0] + g->map_x - g->pm[i][1]);
	else
		return (g->pm[i][0] + g->pm[i][1]);
}

void	get_best_move(t_fill *g)
{
	int count;
	int i;
	int comp;

	i = -1;
	count = 0;
	comp = 0;
	while (++i < (g->pm_size))
	{
		if (get_closest_move(g, i) == 1)
		{
			store_move(g, g->pm[i][0], g->pm[i][1]);
			return ;
		}
		count = best_move(g, i);
		comp = (comp == 0) ? count : comp;
		if (comp > count || i == 0)
		{
			count = comp;
			store_move(g, g->pm[i][0], g->pm[i][1]);
		}
	}
}

int		algo(t_fill *game)
{
	get_moves(game);
	get_best_move(game);
	if (game->done == 1)
		return (0);
	else
		return (1);
}
