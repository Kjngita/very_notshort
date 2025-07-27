/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_path_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:20:09 by gita              #+#    #+#             */
/*   Updated: 2025/07/27 21:13:39 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

static t_map	*copy_map(t_map *map)
{
	t_map	*copied_map;
	size_t	i;

	copied_map = ft_calloc(1, sizeof(t_map));
	if (copied_map == NULL)
		error_printing("Could not initiate copy map >_<\n", map);
	copied_map->height = map->height;
	copied_map->width = map->width;
	i = 0;
	while (i < map->height)
	{
		copied_map->arr_bundle[i] = ft_strdup(map->arr_bundle[i]);
		if (copied_map->arr_bundle[i] == NULL)
		{
			while (i >= 0)
				if (copied_map->arr_bundle[i])
					clean_wipe(copied_map->arr_bundle[i--]);
			clean_wipe(copied_map->arr_bundle);
			return (NULL);
		}
		i++;
	}
	copied_map->arr_bundle[i] = NULL;
	return (copied_map);
}

void	flood_fill(t_map *map_copy, size_t x, size_t y)
{
	if (x < 0 || y < 0 || x > map_copy->width - 1 || y > map_copy->height - 1)
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

	clone = copy_map(map);
	if (clone == NULL)
		error_printing("Could not copy map line >_<\n", map);
	flood_fill(clone, map->player_x, map->player_y);
	//check clone if E or C left -> fail
}
