/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:43:31 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/06 11:44:01 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_syntax(int i, t_mapper *game)
{
	if (i == 0)
	{
		put_str("Error, no map input detected\n");
		exit (0);
	}
	if (i == 1)
	{
		put_str("Not a valid file (not .ber / doesn't exist)\n");
		exit (0);
	}
	if (i == 2)
	{
		put_str("Error, turning off\n");
		if (game->map)
			free_map(game->map);
		exit (0);
	}
	exit (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}