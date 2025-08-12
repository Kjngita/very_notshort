/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_cleaning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:22:20 by gita              #+#    #+#             */
/*   Updated: 2025/08/12 22:26:42 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	*clean_free(void *trash)
{
	if (trash)
		free (trash);
	trash = NULL;
	return (trash);
}

void	*free_map(t_map *map)
{
	int	i;

	if (map->arr_bundle)
	{
		i = 0;
		while (map->arr_bundle[i])
		{
			map->arr_bundle[i] = clean_free(map->arr_bundle[i]);
			i++;
		}
		map->arr_bundle = clean_free(map->arr_bundle);
	}
	if (map->arr_1line)
		map->arr_1line = clean_free(map->arr_1line);
	if (map)
		map = clean_free(map);
	return (NULL);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		game->map = free_map(game->map);
	if (game->floor)
		mlx_delete_image(game->window, game->floor);
	if (game->wall)
		mlx_delete_image(game->window, game->wall);
	if (game->player)
		mlx_delete_image(game->window, game->player);
	if (game->exit)
		mlx_delete_image(game->window, game->exit);
	if (game->collectible)
		mlx_delete_image(game->window, game->collectible);
	if (game->window)
		mlx_terminate(game->window);
}

void	error_print_n_exit(char *err_msg, t_map *map)
{
	if (map)
		free_map(map);
	if (err_msg)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err_msg, 2);
	}
	exit (1);
}

void	close_fd_n_err_print(char *err_msg, t_map *map, int fd)
{
	close(fd);
	error_print_n_exit(err_msg, map);
}
