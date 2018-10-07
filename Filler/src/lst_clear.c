/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:58:32 by jronald           #+#    #+#             */
/*   Updated: 2018/07/31 10:19:06 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		free_arr(char ***arr, int j)
{
	char	**temp;
	int		i;

	i = 0;
	temp = *arr;
	while (i < j)
	{
		free((void*)temp[i]);
		i++;
	}
	free(temp);
	return (1);
}

int		lst_clear(t_fill **temp)
{
	t_fill	*lst;
	int		count;

	count = 0;
	lst = *temp;
	free_arr(&(lst->piece), lst->piece_y);
	free_arr(&(lst->map), lst->map_y);
	lst->piece_x = 0;
	lst->piece_y = 0;
	lst->map_x = 0;
	lst->map_y = 0;
	lst->pm_size = 0;
	store_move(lst, 0, 0);
	while (count < 1000)
	{
		lst->pm[count][0] = 0;
		lst->pm[count][1] = 0;
		count++;
	}
	return (1);
}

void	store_move(t_fill *game, int y, int x)
{
	game->play_y = y;
	game->play_x = x;
}

int		get_closest_move(t_fill *g, int i)
{
	int		x;
	int		y;
	int		ret;
	char	c;

	x = g->pm[i][1];
	y = g->pm[i][0];
	ret = 0;
	c = g->enemy;
	ret = (x - 1 >= 0 && (g->map[y][x - 1] == c || g->map[y][x - 1] == c - 32))
		? 1 : ret;
	ret = (y - 1 >= 0 && (g->map[y - 1][x] == c || g->map[y - 1][x] == c - 32))
		? 1 : ret;
	ret = (x + 1 < g->map_x && (g->map[y][x + 1] == c || g->map[y][x + 1]
				== c - 32)) ? 1 : ret;
	ret = (y + 1 < g->map_y && (g->map[y + 1][x] == c || g->map[y + 1][x]
				== c - 32)) ? 1 : ret;
	return (ret);
}
