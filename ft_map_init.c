/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:47:46 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/09 12:47:32 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *argv)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	c = '\0';
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		put_str("Error opening file\n");
		return (0);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			i++;
	}
	if (c != '\n')
		i++;
	close(fd);
	return (i);
}

int	map_reader(t_mapper *game, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	game->h = count_lines(argv);
	if (game->h == 1)
	{
		put_str("Not a valid file, sorry :P\n");
		return (0);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->h + 1));
	if (!game->map)
		return (0);
	while (i <= game->h)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
