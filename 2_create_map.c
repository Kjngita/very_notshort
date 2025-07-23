/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_create_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:00:34 by gita              #+#    #+#             */
/*   Updated: 2025/07/23 00:39:34 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

/*
map doesnt end with .ber
map is too small/too big/not rectangular
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

t_map	*create_map(char *mapfile)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		error_printing("Map creation failed T_T\n", map);
	map->arr_bundle = NULL;
	map->row = NULL;
	get_map_size(map, mapfile);
	map_arr2d(map, mapfile);
	if (is_map_enclosed(map) == false)
		error_printing("Something fishy with this map T_T\n", map);
	return (map);
}

void	get_map_size(t_map *map, char *mapfile)
{
	int		fd;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error_printing("Could not open map file T_T\n", map);
	line = get_next_line(fd);
	if (line == NULL)
		error_printing("Could not read map T_T\n", map);
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
			error_printing ("Map is not rectangle T_T\n", map);
	}
	close(fd);
	check_map_size(map);
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

void	check_map_size(t_map *map)
{
	int32_t	scrn_w;
	int32_t scrn_h;
	mlx_t	*mlx_test;

	mlx_test = mlx_init(1, 1, "Monitor size check", false);
	mlx_get_monitor_size(0, &scrn_w, &scrn_h);
	mlx_terminate(mlx_test);
	printf("scrn_w %i scrn_h %i\n", scrn_w, scrn_h);  //DELETEEEEEEE
	if (map->width <= 2 || map->height <= 2 || (int32_t)map->width > scrn_w
		|| (int32_t)map->height > scrn_h)
		error_printing ("Map size unacceptable T_T\n", map);
}
