/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:52:31 by gita              #+#    #+#             */
/*   Updated: 2025/07/23 00:51:29 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_HEADER_H
# define SL_HEADER_H

# include<stdio.h> //DELETEEEEEEEEE

# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>


typedef struct s_map
{
	char	**arr_bundle;
	char	*row;
	size_t	width;
	size_t	height;
}	t_map;

enum	e_err_code
{
	GNL_FAILED,


};

void	error_printing(char *err_msg, t_map *map);

t_map	*create_map(char *mapfile);
void	check_map_extension(char *mapname);
void	get_map_size(t_map *map, char *mapfile);
void	check_map_size(t_map *map);
size_t	strlen_without_nl(const char *s);

void	map_arr2d(t_map *map, char *mapfile);
bool	is_map_enclosed(t_map *map);

#endif