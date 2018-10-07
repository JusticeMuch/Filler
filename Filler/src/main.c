/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:24:42 by jronald           #+#    #+#             */
/*   Updated: 2018/07/31 10:19:40 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	output_move(t_fill *game)
{
	ft_putnbr(game->play_y);
	ft_putchar(' ');
	ft_putnbr(game->play_x);
	ft_putchar('\n');
}

int		main(void)
{
	t_fill	*game;
	char	*line;

	game = (t_fill*)malloc(sizeof(t_fill));
	get_next_line(0, &line);
	game->player = (ft_atoi(line + 10) == 1) ? 'o' : 'x';
	game->enemy = game->player == 'x' ? 'o' : 'x';
	game->done = 0;
	store_move(game, 0, 0);
	game->moves = 0;
	while (1)
	{
		if (read_game(game, 0, &line) == 0)
			game->done = 1;
		if (algo(game) == 0)
			game->done = 1;
		output_move(game);
		lst_clear(&game);
		if (game->done == 1)
			break ;
		(game->moves)++;
	}
	free(game);
	return (0);
}
