/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:00:56 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/08 14:43:49 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	need_space(int x, int y, t_mapper *game)
{
	if (game->map[game->column + y][game->row + x] == '0' 
		|| game->map[game->column + y][game->row + x] == 'C')
	{
		game->map[game->column][game->row] = '0';
		game->column += y;
		game->row += x;
		game->map[game->column][game->row] = 'P';
		game->m++;
	}
}

static void	movement(int x, int y, t_mapper *game)
{
	if (x == 1)
		game->img.direct = 1;
	if (x == -1)
		game->img.direct = -1;
	if (y == 1)
		game->img.direct = 1;
	if (y == -1)
		game->img.direct = -1;
	if (game->map[game->column + y][game->row + x] == 'C')
	{
		game->c--;
		if (game->c == 0)
			game->img.close = game->img.hole; 
	}
	if (game->map[game->column + y][game->row + x] == 'E' && game->c == 0)
	{
		put_str("YOU WON, YIPIEEEEEEEEEE!1!!1\n");
		janitor(game);
		exit (0);
	}
	need_space(x, y, game);
	map_print(game);
}

int	move_p(int kp, t_mapper *game)
{
	if (kp == 119)
		movement(0, -1, game);
	if (kp == 97)
		movement(-1, 0, game);
	if (kp == 115)
		movement(0, 1, game);
	if (kp == 100)
		movement(1, 0, game);
	if (kp == 65307)
	{
		put_str("Bye Bye ;3!\n");
		janitor(game);
		exit(0);
	}
	return (0);
}

int	eng(t_mapper *game)
{
	mlx_key_hook(game->wnd, move_p, game);
	return (0);
}