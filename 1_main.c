/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:06:54 by gita              #+#    #+#             */
/*   Updated: 2025/08/12 22:46:43 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

int	main(int ac, char **av)
{
	t_game	game_elem;

	if (ac == 1)
		error_print_n_exit("No map was provided X.x\n", NULL);
	if (ac > 2)
		error_print_n_exit("Too many maps, cannot choose X.x\n", NULL);
	check_map_extension(av[1]);
	game_elem.map = create_map(av[1]);
	start_game(&game_elem);
	mlx_key_hook(game_elem.window, button_smash, &game_elem);
	mlx_loop(game_elem.window);
	free_game(&game_elem);
	return (0);
}

void	check_map_extension(char *mapname)
{
	int		end;
	char	*extension;

	if (ft_strlen(mapname) < 4)
		error_print_n_exit("Map name too short >_<\n", NULL);
	end = ft_strlen(mapname) - 4;
	extension = ".ber";
	if (ft_strncmp(mapname + end, extension, 4) != 0)
		error_print_n_exit("Wrong map extension >_<\n", NULL);
}
