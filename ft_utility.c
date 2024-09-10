/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:46 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/10 13:02:42 by mde-maga         ###   ########.fr       */
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
	char	*str;

	str = ft_itoa(game->m);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.hole)
		mlx_destroy_image(game->mlx, game->img.hole);
	if (game->img.close && game->img.close != game->img.hole)
		mlx_destroy_image(game->mlx, game->img.close);
	mlx_destroy_window(game->mlx, game->wnd);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	ft_printf("Number of movements: %s\n", str);
	free(str);
}
