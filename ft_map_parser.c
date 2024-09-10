/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:05 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/09 12:45:35 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	square_map(t_mapper *game)
{
	int	i;
	int	j;
	int	len;
	int	tmp;

	i = 0;
	j = 0;
	len = sl_strlen(game->map[0]);
	while (game->map[i] && game->map[i][0] == '1')
		i++;
	while (j < i)
	{
		tmp = sl_strlen(game->map[j]);
		if (tmp != len)
			return (0);
		j++;
	}
	return (1);
}

static int	check_param(t_mapper *game)
{
	static int	i;
	int			j;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!all_params(game->map[i][j]))
				return (0);
			if (game->map[i][j] == 'P')
				put_me_in_coach(game, i, j);
			if (game->map[i][j] == 'C')
				game->c++;
			if (game->map[i][j] == 'E')
				game->e++;
			j++;
		}
		i++;
	}
	if (game->p != 1 || game->e != 1 || game->c == 0)
		return (0);
	return (1);
}

static int	where_walls(t_mapper *game)
{
	int	i;

	i = 0;
	game->l = sl_strlen(game->map[0]) - 1;
	while (i < game->h)
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->l] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->l)
	{
		if ((game->map[0][i] != '1') || (game->map[game->h - 1][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_mapper *game)
{
	if (game->map[0] == NULL)
		return (0);
	if (where_walls(game) && check_param(game) && square_map(game))
		return (1);
	return (0);
}
