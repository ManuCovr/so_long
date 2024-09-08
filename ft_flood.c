/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:08:29 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/06 12:14:54 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood(t_mapper *game, int x, int y, char **n_map)
{
	if (n_map[y][x] == '1' || n_map[y][x] == 'F')
		return ;
	else if (n_map[y][x] == 'C')
		game->count_player--;
	else if (n_map[y][x] == 'E')
	{
		game->count_exit = 1;
		return ;
	}
	n_map[y][x] = 'F';
	ft_flood(game, x - 1, y, n_map);
	ft_flood(game, x + 1, y, n_map);
	ft_flood(game, x, y - 1, n_map);
	ft_flood(game, x, y + 1, n_map);
}

void	make_map(t_mapper *game)
{
	int		i;
	char	**n_map;

	game->count_player = game->c;
	n_map = (char **)ft_calloc(sizeof(char *), (game->h + 1));
	if (!n_map)
		return ;
	i = 0;
	while (game->map[i])
	{
		n_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	n_map[i] = NULL;
	ft_flood(game, game->row, game->column, n_map);
	free_map(n_map);
	if (game->count_player != 0 || game->count_exit != 1)
	{
		put_str("Error, map not winnable :/\n");
		free_map(game->map);
		exit(1);
	}
}
