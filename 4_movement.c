/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_movement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:55:54 by gita              #+#    #+#             */
/*   Updated: 2025/08/01 18:13:59 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_header.h"

void	button_smash(mlx_key_data_t key_in_use, void *game_data)
{
	t_map	*so_long;

	so_long = game_data;
	if (key_in_use.key == MLX_KEY_W || key_in_use.key == MLX_KEY_UP)
		so_long->player_y--;
}