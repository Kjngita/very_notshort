/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mlx_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:29:22 by gita              #+#    #+#             */
/*   Updated: 2025/08/04 18:03:24 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	start_game(t_game *game)
{
	if (!game || !game->map)
		error_print_n_exit("Could not start game -.-\n", game->map);
	game->window = mlx_init(game->map->width * TILE_SIZE,
		game->map->height * TILE_SIZE, "Snow Whiskers", false);
	if (game->window == NULL)
	{
		free_game(game);
		error_print_n_exit("Could not open game window X.x\n", game->map);
	}
	game->collected_c = 0;
	game->steps = 0;
	load_images(game);
	spread_floor_instances(game);
	show_instances_on_window(game);
}

static mlx_image_t	*load_texture(t_game *game, char *img_path)
{
	mlx_texture_t	*vessel;
	mlx_image_t		*product;

	vessel = mlx_load_png(img_path);
	if (vessel == NULL)
		return (NULL);
	product = mlx_texture_to_image(game->window, vessel);
	if (product == NULL)
	{
		mlx_delete_texture(vessel);
		return (NULL);
	}
	mlx_delete_texture(vessel);
	return(product);
}

void	load_images(t_game *game)
{
	game->floor = load_texture(game, "./textures/floor.png");
	game->wall = load_texture(game, "./textures/wall.png");
	game->player = load_texture(game, "./textures/player.png");
	game->exit = load_texture(game, "./textures/exit.png");
	game->no_exit = load_texture(game, "./textures/no_exit.png");
	game->collectible = load_texture(game, "./textures/collect.png");
	if (game->floor == NULL || game->wall == NULL
		|| game->player == NULL || game->exit == NULL
		|| game->no_exit == NULL || game->collectible == NULL)
	{
		free_game(game);
		error_print_n_exit("Could not load image ;_;\n", game->map);
	}
}

void	spread_floor_instances(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_image_to_window(game->window, game->floor, 
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	show_instances_on_window(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->arr_bundle[y][x] == '1')
				mlx_image_to_window(game->window, game->wall, 
					x * TILE_SIZE, y * TILE_SIZE);
			if (game->map->arr_bundle[y][x] == 'E')
				mlx_image_to_window(game->window, game->no_exit, 
					x * TILE_SIZE, y * TILE_SIZE);
			if (game->map->arr_bundle[y][x] == 'C')
				mlx_image_to_window(game->window, game->collectible, 
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->window, game->player,
		game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE);
}
