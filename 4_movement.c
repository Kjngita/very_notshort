/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:55:54 by gita              #+#    #+#             */
/*   Updated: 2025/08/02 00:50:26 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	button_smash(mlx_key_data_t key_used, void *param)
{
	t_game	*game_elem;

	game_elem = (t_game *)param;
	if (key_used.action == MLX_PRESS)
	{
		if (key_used.key == MLX_KEY_W || key_used.key == MLX_KEY_UP)
			do_the_move(game_elem, 0, -1);
		if (key_used.key == MLX_KEY_A || key_used.key == MLX_KEY_LEFT)
			do_the_move(game_elem, -1, 0);
		if (key_used.key == MLX_KEY_S || key_used.key == MLX_KEY_DOWN)
			do_the_move(game_elem, 0, 1);
		if (key_used.key == MLX_KEY_D || key_used.key == MLX_KEY_RIGHT)
			do_the_move(game_elem, 1, 0);
		if (key_used.key == MLX_KEY_ESCAPE)
		{
			free_game(game_elem);
			error_print_n_exit("Game window closed X.x\n", game_elem->map);
		}
	}
}

static char	find_out_char(t_map	*map, size_t wanted_x, size_t wanted_y)
{
	size_t	x;
	size_t	y;

	if (wanted_x < 0 || wanted_y < 0 || wanted_x > map->width - 1 ||
		 wanted_y > map->height - 1)
		return ('X');
	y = 0;
	while (y <= wanted_y)
	{
		x = 0;
		while (x <= wanted_x)
		{
			if (x == wanted_x && y == wanted_y)
				return (map->arr_bundle[y][x]);
			x++;
		}
		y++;
	}
	return ('X');
}

void	do_the_move(t_game *game, int move_x, int move_y)
{
	// check future tile
	size_t	coord_x;
	size_t	coord_y;
	char	incoming;

	coord_x = game->map->player_x + move_x;
	coord_y = game->map->player_y + move_y;
	incoming = find_out_char(game->map, coord_x, coord_y);
	if (incoming == 'X')
	{
		free_game(game);
		error_print_n_exit("Could not find out char :(\n", game->map);
	}
	if (incoming == '1')
		return ;
	if (incoming == 'C')
	{
		
	}
	if (incoming == 'E')
	{
		
	}
	//move_instance
		

	// ok to move -> move instance function
}