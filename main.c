/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:40:54 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/09 14:52:16 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_wnd(t_mapper *game)
{
	put_str("Bye bye :3!\n");
	janitor(game);
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mapper	game;

	if (argc != 2)
		error_syntax (0, &game);
	if (ft_strnstr(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", ft_strlen(argv[1])) == NULL)
		error_syntax(1, &game);
	ft_memset(&game, 0, sizeof(t_mapper));
	if ((map_reader(&game, argv[1]) == 0) || (check_map(&game) == 0))
		error_syntax(2, &game);
	make_map(&game);
	game.mlx = mlx_init();
	img_input(&game);
	game.wnd = mlx_new_window(game.mlx, \
								sl_strlen(game.map[0]) * 64, \
								game.h * 64, "Stray");
	map_print(&game);
	mlx_hook(game.wnd, 2, 1L << 0, move_p, &game);
	mlx_hook(game.wnd, 17, 0, close_wnd, &game);
	mlx_loop(game.mlx);
}
