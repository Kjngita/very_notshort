/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_cleaning.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:22:20 by gita              #+#    #+#             */
/*   Updated: 2025/07/27 20:38:48 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	clean_wipe(void *freethis)
{
	free (freethis);
	freethis = NULL;
}

void	error_printing(char *err_msg, t_map *map)
{
	int	i;

	if (map)
	{
		if (map->arr_bundle)
		{
			i = 0;
			while (map->arr_bundle[i])
				clean_wipe(map->arr_bundle[i++]);
			clean_wipe(map->arr_bundle);
		}
		if (map->row)
			clean_wipe(map->row);
	}
	clean_wipe(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit (1);
}

void	close_fd_n_err_print(char *err_msg, t_map *map, int fd)
{
	close(fd);
	error_printing(err_msg, map);	
}