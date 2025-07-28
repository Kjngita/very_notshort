/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_cleaning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:22:20 by gita              #+#    #+#             */
/*   Updated: 2025/07/28 22:28:14 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	clean_free(void *trash)
{
	if (trash)
		free (trash);
	trash = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->arr_bundle)
	{
		i = 0;
		while (map->arr_bundle[i])
		{
			clean_free(map->arr_bundle[i]);
			i++;
		}
		clean_free(map->arr_bundle);
	}
	if (map->arr_1line)
		clean_free(map->arr_1line);
	if (map)
		clean_free(map);
}

void	error_printing(char *err_msg, t_map *map)
{
	free_map(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit (1);
}

void	close_fd_n_err_print(char *err_msg, t_map *map, int fd)
{
	close(fd);
	error_printing(err_msg, map);	
}
