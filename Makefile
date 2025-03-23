# Binary file
NAME = so_long

# Compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# MiniLibX Flags!
MLX_FLAGS = -L/usr/include/minilibx-linux -lmlx -lXext -lX11

# Source files folders
SRC = src/
INCLUDES = ./includes/

# Game
GRAPHIC = $(SRC)graphic/
PLAYER = $(GRAPHIC)player/
ITEMS = $(GRAPHIC)items/

# Get_Next_Line  library
GNL_PATH = $(INCLUDES)gnl/
GNL_LIB = gnl.a
GNL = $(GNL_PATH)$(GNL_LIB)

# Libft
LIBFT_PATH = $(INCLUDES)libft/
LIBFT_LIB = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_LIB)

# Ft_printf
FT_PRINTF_PATH = $(INCLUDES)ft_printf/
FT_PRINTF_LIB = libftprintf.a
FT_PRINTF = $(FT_PRINTF_PATH)$(FT_PRINTF_LIB)

FILES_SRC =	$(addprefix $(SRC), main.c map_checker.c utils.c floodfill.c) \
			$(addprefix $(GRAPHIC), init.c) \
			$(addprefix $(PLAYER), player.c moves.c) \
			$(addprefix $(ITEMS), items.c item_checker.c)

OBJ = $(FILES_SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< successfully! ✅"

$(NAME): $(OBJ) $(GNL) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@
	@echo "Your '$(NAME)' is ready to play! 🚀🎮 Enjoy the game!"


$(GNL):
	@echo "Building Get_Next_Line library... 📚"
	@$(MAKE) --no-print-directory -C $(GNL_PATH)
	@echo "Get_Next_Line built successfully! 👍"

$(LIBFT):
	@echo "Building LIBFT... 💪"
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	@echo "LIBFT built successfully! 👍"

$(FT_PRINTF):
	@echo "Building FT_PRINTF... 🖨️"
	@$(MAKE) --no-print-directory -C $(FT_PRINTF_PATH)
	@echo "FT_PRINTF built successfully! 👍"

all : $(NAME)

clean :
	@rm -f $(SRC)*.o
	@rm -f $(GRAPHIC)*.o
	@rm -f $(PLAYER)*.o
	@rm -f $(ITEMS)*.o
	@echo "Object files cleaned! 🧹"
	@$(MAKE) --no-print-directory clean -C $(GNL_PATH)
	@echo "Get_Next_Line cleaned! 🧼"
	@$(MAKE) --no-print-directory clean -C $(LIBFT_PATH)
	@echo "LIBFT cleaned! 🧼"
	@$(MAKE) --no-print-directory clean -C $(FT_PRINTF_PATH)
	@echo "FT_PRINTF cleaned! 🧼"

fclean : clean
	@$(MAKE) --no-print-directory fclean -C $(GNL_PATH)
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_PATH)
	@$(MAKE) --no-print-directory fclean -C $(FT_PRINTF_PATH)
	@rm -f $(NAME)
	@echo "Executable '$(NAME)' removed! 🗑️"

re : fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
