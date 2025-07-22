/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:34:24 by gita              #+#    #+#             */
/*   Updated: 2025/07/23 00:51:01 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

/*
map not enclosed
map not having 1 P, 1 E, min 1 C
flood fill map fail
*/

static void	map_coord_err(t_map *map, int code)
{
	if (code == GNL_FAILED)
}

void	map_arr2d(t_map *map, char *mapfile)
{
	int		fd;
	size_t	i;
	char	*line;
	size_t	end;
	
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error_printing("Map refused to open =_=\n", map);
	map->arr_bundle = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->arr_bundle)
		error_printing("Map memory alloc failed =_=\n", map);
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			close (fd);
			error_printing("Map coordinates fetching failed =_=\n", map);
		end = strlen_without_nl(line);
		line[end] = "\0";
		map->arr_bundle[i] = ft_strdup(line);
		if (map->arr_bundle[i] == NULL)
			close (fd);
			error_printing("str_dup failed =_=\n", map);
		free (line);
		i++;
	}
	map->arr_bundle[i] = NULL;
	close(fd);
}

void	map_arr1d(t_map *map)
{
	
}