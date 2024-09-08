/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:46 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/08 09:37:46 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

size_t	sl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	all_params(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n')
		return (0);
	return (1);
}

void	put_me_in_coach(t_mapper *game, int i, int j)
{
	game->p++;
	game->row = j;
	game->column = i;
}

void	janitor(t_mapper *game)
{
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.hole);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.hole);
	mlx_destroy_image(game->mlx, game->img.coin);
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->wnd);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
