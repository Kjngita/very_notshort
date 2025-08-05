/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:34:24 by gita              #+#    #+#             */
/*   Updated: 2025/08/05 18:35:38 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	map_arr2d(t_map *map, char *mapfile)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error_print_n_exit("Map opening failed =_=\n", map);
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

void	map_arr1d(t_map *map)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < map->height)
	{
		line = gnl_strjoin(map->arr_1line, map->arr_bundle[i]);
		if (line == NULL)
			error_print_n_exit("Could not copy map line =_=\n", map);
		free(map->arr_1line);
		map->arr_1line = line;
		i++;
	}
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
			if (map->arr_bundle[0][x] != '1'
				|| map->arr_bundle[map->height - 1][x] != '1')
				return (false);
			x++;
		}
		if (map->arr_bundle[y][0] != '1'
			|| map->arr_bundle[y][map->width - 1] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	is_content_good(t_map *map)
{
	size_t	p_amount;
	size_t	e_amount;
	size_t	c_amount;
	size_t	i;

	p_amount = 0;
	e_amount = 0;
	c_amount = 0;
	i = 0;
	while (map->arr_1line[i])
	{
		if (ft_strchr("PEC01", map->arr_1line[i]) == NULL)
			return (false);
		count_elem(map->arr_1line[i], &p_amount, &e_amount, &c_amount);
		i++;
	}
	if (p_amount != 1 || e_amount != 1 || c_amount < 1)
		return (false);
	map->total_c = c_amount;
	return (true);
}

void	count_elem(char elem, size_t *p, size_t *e, size_t *c)
{
	if (elem == 'P')
		(*p)++;
	if (elem == 'E')
		(*e)++;
	if (elem == 'C')
		(*c)++;
}
