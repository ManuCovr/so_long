/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:36:26 by mde-maga          #+#    #+#             */
/*   Updated: 2024/09/08 14:53:47 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libs/mlx_linux/mlx.h"
# include "./libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>

typedef struct s_graph
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*hole;
	void	*close;
	int		direct;
	void	**t;
	void	**c;
	void	**r;
}			t_graph;


typedef struct s_mapper
{
	void	*mlx;
	void	*wnd;
	char	**map;
	int		c;
	int		e;
	int		p;
	int		row;
	int		column;
	int		l;
	int		m;
	int		h;
	int		count_player;
	int		count_exit;
	t_graph	img;
}			t_mapper;

// FUNCTIONS //

void			put_str(char *str);
void			error_syntax(int i, t_mapper *game);
void			free_map(char **map);
void			make_map(t_mapper *game);
void			put_me_in_coach(t_mapper *game, int i, int j);
void			map_print(t_mapper *game);
int				main(int argc, char **argv);
int				map_reader(t_mapper *game, char *argv);
int				check_map(t_mapper *game);
int				all_params(char c);
size_t			sl_strlen(const char *s);
void			keep_window(t_mapper *game);
void			janitor(t_mapper *game);
int				move_p(int cd, t_mapper *game);
int				eng(t_mapper *game);

#endif