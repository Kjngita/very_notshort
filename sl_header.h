/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:52:31 by gita              #+#    #+#             */
/*   Updated: 2025/07/30 23:35:48 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_HEADER_H
# define SL_HEADER_H

# include<stdio.h> //DELETEEEEEEEEE

# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

# define TILE_SIZE 64

typedef struct s_map
{
	char	**arr_bundle;
	char	*arr_1line;
	size_t	width;
	size_t	height;
	size_t	player_x;
	size_t	player_y;
	size_t	C_total;
}	t_map;

typedef struct s_game
{
	mlx_t		*window;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*no_exit;
	mlx_image_t	*collectible;
}	t_game;


void	clean_free(void *trash);
void	free_map(t_map *map);
void	error_printing(char *err_msg, t_map *map);
void	close_fd_n_err_print(char *err_msg, t_map *map, int fd);

t_map	*create_map(char *mapfile);
void	check_map_extension(char *mapname);
void	get_map_size(t_map *map, char *mapfile);
void	check_map_too_large(t_map *map);
size_t	strlen_without_nl(const char *s);

void	map_arr2d(t_map *map, char *mapfile);
void	map_arr1d(t_map *map);
bool	is_map_enclosed(t_map *map);
bool	is_content_good(t_map *map);
void	count_elem(char	elem, size_t *P, size_t *E, size_t *C);

void	player_pos(t_map *map);
bool	is_path_avail(t_map *map);

t_game	*start_game(t_map *map);
void	load_image_n_spread_floor(t_game *game_elem, t_map *map);
void	show_img_on_window(t_game *game_elem, t_map *map);
#endif