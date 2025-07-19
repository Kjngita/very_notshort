/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:06:54 by gita              #+#    #+#             */
/*   Updated: 2025/07/19 17:02:57 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	error_printing(int err_code)
{
	if (err_code == NO_MAP)
	{
		write (2, "Error\n", 6);
		write (2, "No map was provided O.o\n", 24);
		exit(1);
	}
	if (err_code == MANY_MAPS)
	{
		write (2, "Error\n", 6);
		write (2, "Too many maps, cannot choose X.x\n", 33);
		exit(1);
	}
	if (err_code == INVALID_MAP)
	{
		write (2, "Error\n", 6);
		write(2, "Something fishy with this map >_<\n", 34);
		exit(1);
	}
}

int main (int ac, char **av)
{
	if (ac == 1)
		error_printing(NO_MAP);
	if (ac > 2)
		error_printing(MANY_MAPS);
	check_map(av[1]);
}