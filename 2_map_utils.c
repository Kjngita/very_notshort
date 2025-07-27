/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:34:24 by gita              #+#    #+#             */
/*   Updated: 2025/07/27 19:15:55 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

/*
map not enclosed
map not having 1 P, 1 E, min 1 C, having foreign chars
flood fill map fail
*/

void	map_arr2d(t_map *map, char *mapfile)
{
	int		fd;
	size_t	i;
	char	*line;
	
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		close_fd_n_err_print("Map opening failed =_=\n", map, fd);
	map->arr_bundle = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->arr_bundle)
		close_fd_n_err_print("Map memory alloc failed =_=\n", map, fd);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			close_fd_n_err_print("Map lines fetching failed =_=\n", map, fd);
		line[strlen_without_nl(line)] = '\0';
		map->arr_bundle[i] = ft_strdup(line);
		if (map->arr_bundle[i] == NULL)
			close_fd_n_err_print("Map coord duplicate failed =_=\n", map, fd);
		free (line);
		i++;
	}
	map->arr_bundle[i] = NULL;
	close(fd);
}

bool	is_map_enclosed(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->arr_bundle[0][x] != '1' || map->arr_bundle[map->height - 1][x] != '1')
				return (false);
			x++;
		}
		if (map->arr_bundle[y][0] != '1' || map->arr_bundle[y][map->width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}


bool	is_content_good(t_map *map)
{
	size_t	P_amount;
	size_t	E_amount;
	size_t	C_amount;
	size_t	x;
	size_t	y;

	P_amount = 0;
	E_amount = 0;
	C_amount = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_strchr("PEC01", map->arr_bundle[y][x]) == NULL)
				return (false);
			count_elem(map->arr_bundle[y][x], &P_amount, &E_amount, &C_amount);
			x++;
		}
		y++;
	}
	if (P_amount != 1 || E_amount != 1 || C_amount < 1)
		return (false);
	return (true);
}

void	count_elem(char	elem, size_t *P, size_t *E, size_t *C)
{	
	if (elem == 'P')
		(*P)++;
	if (elem == 'E')
		(*E)++;
	if (elem == 'C')
		(*C)++;
}


