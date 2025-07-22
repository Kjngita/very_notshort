/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:06:54 by gita              #+#    #+#             */
/*   Updated: 2025/07/22 20:24:06 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

static void	clean_wipe(void *freethis)
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
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_msg, 2);
	exit (1);
}
int main(int ac, char **av)
{
	t_map	*game_map;

	if (ac == 1)
		error_printing("No map was provided O.o\n", NULL);
	if (ac > 2)
		error_printing("Too many maps, cannot choose X.x\n", NULL);
	check_map_extension(av[1]);
	printf("Main: check extension ok\n");  //DELETEEEEEEEEEEEE
	game_map = create_map(av[1]);
	printf("Main: create map ok\n");  //DELETEEEEEEEEEEEE
	printf("Main: All seems good\n"); //DELETEEEEEEEEE
	return (0);
}
