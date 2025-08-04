/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_create_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:00:34 by gita              #+#    #+#             */
/*   Updated: 2025/08/04 18:26:27 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	check_map_extension(char *mapname)
{
	int		end;
	char	*extension;

	end = ft_strlen(mapname) - 4;
	extension = ".ber";
	if (ft_strncmp(mapname + end, extension, 4) != 0)
		error_print_n_exit("Wrong map extension >_<\n", NULL);
}

t_map	*create_map(char *mapfile)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		error_print_n_exit("Map creation failed T_T\n", map);
	map->arr_bundle = NULL;
	map->arr_1line = NULL;
	get_map_size(map, mapfile);
	map_arr2d(map, mapfile);
	map_arr1d(map);
	if (is_map_enclosed(map) == false)
		error_print_n_exit("Map wall is breached T_T\n", map);
	if (is_content_good(map) == false)
		error_print_n_exit("Map content not good T_T\n", map);
	player_pos(map);
	if (is_path_avail(map) == false)
		error_print_n_exit("No valid path T_T\n", map);
	check_map_too_large(map);
	return (map);
}

void	get_map_size(t_map *map, char *mapfile)
{
	int		fd;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error_print_n_exit("Could not open map file T_T\n", map);
	line = get_next_line(fd);
	if (line == NULL)
		error_print_n_exit("Could not read map T_T\n", map);
	map->width = strlen_without_nl(line);
	map->height = 1;
	while (1)
	{
		free (line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->height++;
		if (strlen_without_nl(line) != map->width)
		{
			free (line);
			error_print_n_exit ("Map is not rectangle T_T\n", map);
		}
	}
	close(fd);
}

size_t	strlen_without_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == '\n')
		i--;
	return (i);
}

void	check_map_too_large(t_map *map)
{
	int32_t	scrn_w;
	int32_t scrn_h;
	mlx_t	*mlx_test;

	mlx_test = mlx_init(1, 1, "Monitor size check", false);
	mlx_get_monitor_size(0, &scrn_w, &scrn_h);
	mlx_terminate(mlx_test);
	if ((int32_t)map->width * TILE_SIZE > scrn_w
		|| (int32_t)map->height * TILE_SIZE > scrn_h)
		error_print_n_exit ("Map larger than monitor T_T\n", map);
}
