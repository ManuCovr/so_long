/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:29:14 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/08 15:25:57 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keep_window(t_mapper *game)
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
	game->img.close = mlx_xpm_file_to_image(game->mlx, "imgs/close.xpm", 
											&p, &p);
	game->img.hole = mlx_xpm_file_to_image(game->mlx, "imgs/hole.xpm", \
											&p, &p);
}

/* static void	putimg(t_mapper *game, int i, int j)
{
    char *str;

    if (!game->map || !game->map[i])
        return;
    str = ft_itoa(game->m);
    if (!str)
        return;
    mlx_string_put(game->mlx, game->wnd, 10, 20, 0xffffffff, str);
    free(str);
    if (game->map[i][j] == '1')
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.wall, j * 16, i * 16);
    else if (game->map[i][j] == '0')
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.floor, j * 16, i * 16);
    else if (game->map[i][j] == 'E')
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.hole, j * 16, i * 16);
    else if (game->map[i][j] == 'C')
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.coin, j * 16, i * 16);

} */
static void	putimg(t_mapper *game, int i, int j)
{
    char *str;

    // Track function entry
    printf("Entering putimg: i = %d, j = %d\n", i, j);

    // Check map bounds
    if (!game->map || !game->map[i])
    {
        printf("Error: Invalid map or map row at i = %d\n", i);
        return;
    }

    // Convert a value to a string and print it
    str = ft_itoa(game->m);
    if (!str)
    {
        printf("Error: ft_itoa failed\n");
        return;
    }
    printf("Converted game->m = %d to string: %s\n", game->m, str);

    // Print string to window
    mlx_string_put(game->mlx, game->wnd, 10, 20, 0xffffffff, str);
    free(str); // Free the string after use

    // Check the images for null pointers and render accordingly
    if (game->map[i][j] == '1')
    {
        if (!game->img.wall)
        {
            printf("Error: game->img.wall is NULL\n");
            return;
        }
        printf("Rendering wall at i = %d, j = %d\n", i, j);
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.wall, j * 64, i * 64);
    }
    else if (game->map[i][j] == '0')
    {
        if (!game->img.floor)
        {
            printf("Error: game->img.floor is NULL\n");
            return;
        }
        printf("Rendering floor at i = %d, j = %d\n", i, j);
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.floor, j * 64, i * 64);
    }
    else if (game->map[i][j] == 'E')
    {
        if (!game->img.close)
        {
            printf("Error: game->img.close is NULL\n");
            return;
        }
        printf("Rendering hole at i = %d, j = %d\n", i, j);
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.close, j * 64, i * 64);
    }
    else if (game->map[i][j] == 'C')
    {
        if (!game->img.coin)
        {
            printf("Error: game->img.coin is NULL\n");
            return;
        }
        printf("Rendering coin at i = %d, j = %d\n", i, j);
        mlx_put_image_to_window(game->mlx, game->wnd, game->img.coin, j * 64, i * 64);
    }
    
    // Confirm function exit
    printf("Leaving putimg: i = %d, j = %d\n", i, j);
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
