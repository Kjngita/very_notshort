/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:52:31 by gita              #+#    #+#             */
/*   Updated: 2025/07/22 00:16:49 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_HEADER_H
# define SL_HEADER_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>


typedef struct s_map
{
	char	**arr_bundle;
	char	*row;
	int		width;
	int		height;
}	t_map;


void	error_printing(char *err_msg, t_map *map);

void	check_map_extension(char *mapname);

#endif