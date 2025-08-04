/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:52:31 by gita              #+#    #+#             */
/*   Updated: 2025/08/04 18:45:43 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_HEADER_H
# define SL_HEADER_H

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
	size_t	total_c;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	mlx_t		*window;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*no_exit;
	mlx_image_t	*collectible;
	size_t		collected_c;
	size_t		steps;
}	t_game;

void	*clean_free(void *trash);
void	*free_map(t_map *map);
void	free_game(t_game *game);
void	error_print_n_exit(char *err_msg, t_map *map);
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
void	count_elem(char elem, size_t *p, size_t *e, size_t *c);

void	player_pos(t_map *map);
bool	is_path_avail(t_map *map);

void	start_game(t_game *game);
void	load_images(t_game *game);
void	spread_floor_instances(t_game *game);
void	show_instances_on_window(t_game *game);

void	button_smash(mlx_key_data_t key_used, void *param);
void	do_the_move(t_game *game, int move_x, int move_y);
void	move_normal(mlx_image_t *the_player, int incoming_x, int incoming_y);
void	on_collect_tile(t_game *game, int x, int y);
void	on_exit_tile(t_game *game, int x, int y);

#endif