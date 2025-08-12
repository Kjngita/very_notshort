NAME = so_long
CFILES = 0_cleaning.c \
	1_main.c \
	2_create_map.c \
	2_map_utils.c \
	2_path_check.c \
	3_mlx_start.c \
	4_movement.c
O_DIR = objdir
OFILES = $(addprefix $(O_DIR)/,$(CFILES:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Wextra -Werror
HEADERS = -I. -I$(MLX_DIR)/include -I$(LIBFT_DIR)

MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: $(MLX_DIR) $(LIBFT) $(NAME)

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42 $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	$(MAKE) all -C $(LIBFT_DIR)

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) $(LIBFT) $(MLX_LIB) -o $(NAME)
	@echo "┌───────────────────────────┐"
	@echo "│ ~~ \033[33m 🎮 Game ready! ✅ \033[0m ~~ │"
	@echo "└───────────────────────────┘"

$(O_DIR):
	mkdir -p $@

$(O_DIR)/%.o: %.c sl_header.h | $(O_DIR)
	cc $(FLAGS) -c $< -o $@ $(HEADERS)

clean:
	rm -rf $(O_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OFILES)

.PHONY: all clean fclean re

.SILENT: