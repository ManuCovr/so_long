/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:29:14 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/10 11:16:20 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_input(t_mapper *game)
{
	int	p;

	p = 64;
	game->img.player = mlx_xpm_file_to_image(game->mlx, "imgs/cat.xpm", \
											&p, &p);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "imgs/coin.xpm", \
											&p, &p);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", \
											&p, &p);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", \
											&p, &p);
	game->img.close = mlx_xpm_file_to_image(game->mlx, "imgs/close.xpm", \
											&p, &p);
	game->img.hole = mlx_xpm_file_to_image(game->mlx, "imgs/hole.xpm", \
											&p, &p);
}

static void	putimg(t_mapper *game, int i, int j)
{
	char	*str;

	if (!game->map || !game->map[i])
		return ;
	str = ft_itoa(game->m);
	if (!str)
		return ;
	mlx_string_put(game->mlx, game->wnd, 10, 20, 0xffffff, str);
	free(str);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.wall, \
								j * 64, i * 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.floor, \
								j * 64, i * 64);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.close, \
								j * 64, i * 64);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->wnd, game->img.coin, \
								j * 64, i * 64);
}

void	map_print(t_mapper *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(game->mlx, game->wnd);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			putimg(game, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->wnd, game->img.player, \
	game->row * 64, game->column * 64);
}
