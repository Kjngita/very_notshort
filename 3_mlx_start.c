/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mlx_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:29:22 by gita              #+#    #+#             */
/*   Updated: 2025/08/01 20:40:40 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	start_game(t_game *game)
{
	if (!game || !game->map)
		error_printing("Could not start game -.-\n", game->map);
	game->window = mlx_init(game->map->width * TILE_SIZE,
		game->map->height * TILE_SIZE, "so_long", false);
	if (game->window == NULL)
		error_printing("Could not open game window X.x\n", game->map);

}

static mlx_image_t	*load_textures(t_game *game, char *img_path)
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

void	load_image_n_spread_floor(t_game *game)
{
	size_t	x;
	size_t	y;

	game->floor = load_textures(game, "./textures/floor.png");
	game->wall = load_textures(game, "./textures/wall.png");
	game->player = load_textures(game, "./textures/player.png");
	game->exit = load_textures(game, "./textures/exit.png");
	game->no_exit = load_textures(game, "./textures/no_exit.png");
	game->collectible = load_textures(game, "./textures/collect.png");
	if (game->floor == NULL || game->wall == NULL
		|| game->player == NULL || game->exit == NULL
		|| game->no_exit == NULL || game->collectible == NULL)
		error_printing("Could not load image ;_;\n", game->map);
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
			if (game->map->arr_bundle[y][x] == 'P')
				mlx_image_to_window(game->window, game->player, 
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
}
