/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mlx_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:29:22 by gita              #+#    #+#             */
/*   Updated: 2025/07/30 23:49:09 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

t_game	*start_game(t_map *map)
{
	t_game	*empty;

	empty = ft_calloc(1, sizeof(t_game));
	if (empty == NULL)
		error_printing("Could not start game -.-\n", map);
	empty->window = mlx_init(map->width * TILE_SIZE,
		map->height * TILE_SIZE, "so_long", false);
	if (empty->window == NULL)
		error_printing("Could not open game window X.x\n", map);
	return (empty);
}

static mlx_image_t	*load_textures(t_game *game_elem, char *img_path)
{
	mlx_texture_t	*vessel;
	mlx_image_t		*product;

	vessel = mlx_load_png(img_path);
	if (vessel == NULL)
		return (NULL);
	product = mlx_texture_to_image(game_elem->window, vessel);
	if (product == NULL)
	{
		mlx_delete_texture(vessel);
		return (NULL);
	}
	mlx_delete_texture(vessel);
	return(product);
}

void	load_image(t_game *game_elem, t_map *map)
{
	size_t	x;
	size_t	y;

	game_elem->floor = load_textures(game_elem, "./textures/floor.png");
	// game_elem->wall = load_textures(game_elem, "./textures/wall.png");
	game_elem->player = load_textures(game_elem, "./textures/player.png");
	// game_elem->exit = load_textures(game_elem, "./textures/exit.png");
	// game_elem->no_exit = load_textures(game_elem, "./textures/no_exit.png");
	game_elem->collectible = load_textures(game_elem, "./textures/collect.png");
	// if (game_elem->floor == NULL || game_elem->wall == NULL
	// 	|| game_elem->player == NULL || game_elem->exit == NULL
	// 	|| game_elem->no_exit == NULL || game_elem->collectible == NULL)
	if (game_elem->floor == NULL || game_elem->player == NULL || game_elem->collectible == NULL)
		error_printing("Could not load image ;_;\n", map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_image_to_window(game_elem->window, game_elem->floor, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
