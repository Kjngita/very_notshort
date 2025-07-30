/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_path_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:20:09 by gita              #+#    #+#             */
/*   Updated: 2025/07/30 16:06:29 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	player_pos(t_map *map)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->arr_bundle[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static t_map	*copy_map(t_map *map)
{
	t_map	*copied_map;
	size_t	i;

	copied_map = ft_calloc(1, sizeof(t_map));
	if (copied_map == NULL)
		return (NULL);
	copied_map->arr_bundle = ft_calloc(map->height + 1, sizeof (char*));
	if (copied_map->arr_bundle == NULL)
	{
		free_map(copied_map);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		copied_map->arr_bundle[i] = ft_strdup(map->arr_bundle[i]);
		if (copied_map->arr_bundle[i] == NULL)
		{
			free_map(copied_map);
			return (NULL);
		}
		i++;
	}
	copied_map->arr_bundle[i] = NULL;
	return (copied_map);
}

static void	flood_fill(t_map *map_copy, size_t x, size_t y)
{
	if (x > map_copy->width - 1 || y > map_copy->height - 1)
		return ;
	if (map_copy->arr_bundle[y][x] == '1' || map_copy->arr_bundle[y][x] == 'F')
		return ;
	map_copy->arr_bundle[y][x] = 'F';
	flood_fill (map_copy, x + 1, y);
	flood_fill (map_copy, x - 1, y);
	flood_fill (map_copy, x, y + 1);
	flood_fill (map_copy, x, y - 1);
}

bool	is_path_avail(t_map *map)
{
	t_map	*clone;
	size_t	i;

	clone = copy_map(map);
	if (clone == NULL)
		error_printing("Could not copy map line >_<\n", map);
	flood_fill(clone, map->player_x, map->player_y);
	clone->height = map->height;
	clone->arr_1line = NULL;
	map_arr1d(clone);
	i = 0;
	while (clone->arr_1line[i])
	{
		if (clone->arr_1line[i] == 'E' || clone->arr_1line[i] == 'C')
		{
			free_map(clone);
			return (false);
		}
		i++;
	}
	free_map(clone);
	return (true);
}
