NAME = so_long
CFILES = open_window.c
O_DIR = OBJdir
OFILES = $(addprefix $(O_DIR)/,$(CFILES:.c=.o))
FLAGS = -Wall -Wextra -Werror
HEADER = -I sl_header.h -I $(MLX_DIR)/include 

MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42 $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) $(MLX_LIB) -o $(NAME)
	echo "\033[33m-- 🎮 Game ready! ✅ --\033[0m"

$(O_DIR):
	mkdir -p $@

$(O_DIR)/%.o: %.c | $(O_DIR)
	cc $(FLAGS) -c $< -o $@ $(HEADER)

clean:
	rm -rf $(O_DIR) $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re