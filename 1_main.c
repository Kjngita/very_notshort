/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:06:54 by gita              #+#    #+#             */
/*   Updated: 2025/07/24 18:22:39 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int main(int ac, char **av)
{
	t_map	*game_map;

	if (ac == 1)
		error_printing("No map was provided O.o\n", NULL);
	if (ac > 2)
		error_printing("Too many maps, cannot choose X.x\n", NULL);
	check_map_extension(av[1]);
	game_map = create_map(av[1]);
	printf("Main: create map ok\n");  //DELETEEEEEEEEEEEE
	printf("Main: All seems good\n"); //DELETEEEEEEEEE
	return (0);
}
