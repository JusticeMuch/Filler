/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:57:34 by jronald           #+#    #+#             */
/*   Updated: 2018/07/31 10:20:20 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_atoi_twice(int *n1, int *n2, char *str)
{
	*n1 = ft_atoi(str);
	while (*str != ' ')
		str++;
	*n2 = ft_atoi(str);
	if (*n1 && *n2)
		return (1);
	else
		return (0);
}

int		get_piece(char **line, t_fill *g, int fd)
{
	int		i;
	char	**temp;

	if (ft_strstr(*line, "Piece"))
		if (ft_atoi_twice(&(g->piece_y), &(g->piece_x), *line + 6) == 0)
			return (0);
	i = 0;
	if (!(g->piece = (char**)malloc(sizeof(char*) * (g->piece_y + 1))))
		return (0);
	temp = g->piece;
	while (i < g->piece_y)
	{
		if (get_next_line(fd, line) <= -1)
			return (0);
		if (!(temp[i] = ft_strdup(*line)))
			return (0);
		i++;
	}
	return (1);
}

int		get_map(char **line, t_fill *g, int fd)
{
	int		i;
	char	**temp;

	if (get_next_line(fd, line) > -1)
		if (ft_strstr(*line, "Plateau"))
			if (ft_atoi_twice(&(g->map_y), &(g->map_x), *line + 8) == 0)
				return (0);
	i = 0;
	get_next_line(fd, line);
	if (!(g->map = (char**)malloc(sizeof(char*) * (g->map_y + 1))))
		return (0);
	temp = g->map;
	while (i < g->map_y)
	{
		if (get_next_line(fd, line) <= -1)
			return (0);
		if (!(temp[i] = ft_strdup(*line + 4)))
			return (0);
		i++;
	}
	return (1);
}

int		read_game(t_fill *g, int fd, char **line)
{
	if (get_map(line, g, fd) == 0)
		return (0);
	if (get_next_line(fd, line) > -1)
		if (get_piece(line, g, fd) == 0)
			return (0);
	return (1);
}
