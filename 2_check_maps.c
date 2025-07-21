/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:42:29 by gita              #+#    #+#             */
/*   Updated: 2025/07/22 00:17:00 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

/*
map doesnt end with .ber
GNL
map is not rectangular
map not enclosed
map not having 1 P, 1 E, min 1 C
flood fill map fail

*/

void	check_map_extension(char *mapname)
{
	int		end;
	char	*extension;

	end = ft_strlen(mapname) - 4;
	extension = ".ber";
	if (ft_strncmp(mapname + end, extension, 4) != 0)
		error_printing("Wrong map extension >_<\n", NULL);
}

static void	get_map_size(t_map *map, char *mapfile)
{
	int	fd;
	int	line;
	int32_t	*scrn_w;
	int32_t *scrn_h;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error_printing("Could not open map file T_T\n", map);
	line = get_next_line(fd);
	if (line == NULL)
		error_printing("Could not read map T_T\n", map);
	map->width = ft_strlen(line) - 1;
	map->height = 1;
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		map->height++;
		if (ft_strlen(line) != map->width)
			error_printing ("Map is not rectangle T_T\n", map);
	}
	close(fd);
	mlx_get_monitor_size(0, scrn_w, scrn_h);
	if (map->width <= 2 || map->height <= 2 || map->width > &scrn_w
		|| map->height > &scrn_h)
		error_printing ("Map size unacceptable T_T\n", map);
}

t_map	*create_map(char *mapfile)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		error_printing("Map creation failed T_T\n", map);
	map->arr_bundle = NULL;
	map->row = NULL;
	get_map_size(map, mapfile);
}
