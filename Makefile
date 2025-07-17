NAME = so_long
CFILES = open_window.c
O_DIR = OBJdir
OFILES = $(addprefix $(O_DIR)/,$(CFILES:.c=.o))
MLX_DIR = MLX42
LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
FLAGS = -Wall -Wextra -Werror
# HEADER = -I $


all: $(NAME)

$(NAME): $(OFILES) createlib
	cc $(FLAGS) $(OFILES) $(LIB) -o $(NAME)

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@

createlib: $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(O_DIR):
	mkdir -p $@

$(O_DIR)/%.o: %.c | $(O_DIR)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR) $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re