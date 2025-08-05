/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:55:54 by gita              #+#    #+#             */
/*   Updated: 2025/08/05 19:59:40 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	button_smash(mlx_key_data_t key_used, void *param)
{
	t_game	*game_elem;

	game_elem = (t_game *)param;
	if (key_used.action == MLX_PRESS || key_used.action == MLX_REPEAT)
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

void	do_the_move(t_game *game, int move_x, int move_y)
{
	size_t	incoming_x;
	size_t	incoming_y;
	char	incoming_tile;

	incoming_x = game->map->player_x + move_x;
	incoming_y = game->map->player_y + move_y;
	incoming_tile = game->map->arr_bundle[incoming_y][incoming_x];
	if (incoming_tile == '1')
		return ;
	game->map->player_x = incoming_x;
	game->map->player_y = incoming_y;
	move_normal(game->player, incoming_x, incoming_y);
	game->steps++;
	ft_putstr_fd("Steps taken: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putstr_fd("\n", 1);
	if (incoming_tile == 'C')
		on_collect_tile(game, incoming_x, incoming_y);
	else if (incoming_tile == 'E')
		on_exit_tile(game, incoming_x, incoming_y);
}

void	move_normal(mlx_image_t *the_player, int incoming_x, int incoming_y)
{
	the_player->instances->x = incoming_x * TILE_SIZE;
	the_player->instances->y = incoming_y * TILE_SIZE;
}

void	on_collect_tile(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->map->total_c)
	{
		if (game->collectible->instances[i].x == x * TILE_SIZE
			&& game->collectible->instances[i].y == y * TILE_SIZE)
		{
			game->collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	game->collected_c++;
	game->map->arr_bundle[y][x] = '0';
	if (game->collected_c == game->map->total_c)
	{
		game->no_exit->instances->enabled = false;
		mlx_image_to_window(game->window, game->exit,
			game->no_exit->instances->x,
			game->no_exit->instances->y);
	}
}

void	on_exit_tile(t_game *game, int x, int y)
{
	if (game->collected_c == game->map->total_c)
	{
		if (game->exit->instances->x == x * TILE_SIZE
			&& game->exit->instances->y == y * TILE_SIZE)
		{
			free_game(game);
			ft_putstr_fd("~~ Om nom nom nom nom ^w^ ~~\n", 1);
			exit (0);
		}
	}
}
