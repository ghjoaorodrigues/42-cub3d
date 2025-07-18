#
# ░█▀▀░█░█░█▀▄░▀▀█░█▀▄
# ░█░░░█░█░█▀▄░░▀▄░█░█
# ░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░ by fsilva-p & joao-alm
#

# Compiler Settings
NAME			= cub3D
NAME_BONUS		= cub3D_bonus
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -rf
O_DIR			= obj

# Print Settings
header			= obj/header
col1pad			= 12
col2pad			= 27

# Mandatory Files
INC				= -I include
SRC_MAIN		= src/main/main.c \
				  src/main/init.c \
				  src/main/free.c
SRC_INPUT		= src/input/input.c \
				  src/input/filename.c \
				  src/input/read/read.c \
				  src/input/read/texture.c \
				  src/input/read/map.c \
				  src/input/read/color_helper.c\
				  src/input/check_map.c \
				  src/input/format_map.c \
				  src/input/flood_fill.c
SRC_GRAPHIC		= src/graphic/raycast.c \
				  src/graphic/raycast_utils.c \
				  src/graphic/draw.c
SRC_KEYHOOK		= src/keyhook/keyhook.c \
				  src/keyhook/keyhook_rotate.c \
				  src/keyhook/keyhook_walk.c
SRC				= $(SRC_MAIN) $(SRC_INPUT) $(SRC_GRAPHIC) $(SRC_KEYHOOK)
OBJ				= $(SRC:src/%.c=$(O_DIR)/mandatory/$(notdir %.o))

# Bonus Files
SRC_BONUS		= $(SRC_MAIN) $(SRC_INPUT) $(SRC_GRAPHIC) src/keyhook/keyhook.c src/keyhook/keyhook_rotate.c  src/bonus/keyhook_walk_bonus.c
OBJ_BONUS		= $(SRC_BONUS:src/%.c=$(O_DIR)/bonus/$(notdir %.o))

# JAL Settings
JAL_DIR			= lib/jal
JAL				= $(JAL_DIR)/libjal.a
JAL_INC			= -I $(JAL_DIR)/include
JAL_O_DIR		= $(JAL_DIR)/obj
JAL_ADD			= -L $(JAL_DIR) -l jal

# MLX Settings
MLX_DIR			= lib/mlx
MLX				= $(MLX_DIR)/libmlx.a
MLX_INC			= -I $(MLX_DIR)
MLX_ADD			= -L $(MLX_DIR) -l mlx -L/usr/lib -lXext -lX11 -lm 

# Lib Settings
LIB_INC		= $(JAL_INC) $(MLX_INC)
LIB_ADD		= $(JAL_ADD) $(MLX_ADD)

# Mandatory Rules
all: $(header) $(JAL) $(MLX) $(NAME)

$(O_DIR)/mandatory/%.o: src/%.c
	@mkdir -p $(dir $@)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(notdir $@) --no-print-directory
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(LIB_INC)

$(NAME): $(OBJ)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(NAME) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB_ADD)
	@make .print_end print_color="$(y)" print_action="Compiling" print_name=$(NAME) --no-print-directory

clean:
	@if [ ! -d $(O_DIR) ] && [ ! -d $(JAL_O_DIR) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ]; then make -C $(JAL_DIR) clean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi
	@if [ -d $(O_DIR) ]; then make .remove tname="minishell_objects" t1=$(O_DIR) --no-print-directory; fi

fclean:
	@if [ ! -d $(O_DIR) ] && [ ! -f $(NAME) ] && [ ! -f $(NAME_BONUS) ] && [ ! -d $(JAL_O_DIR) ] && [ ! -f $(JAL) ] && [ ! -f $(MLX) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ] || [ -f $(JAL) ]; then make -C $(JAL_DIR) fclean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi
	@if [ -f $(MLX) ]; then make mlx_fclean --no-print-directory; fi
	@if [ -d $(O_DIR) ]; then make .remove tname=$(O_DIR) t1=$(O_DIR) t2=$(O_DIR) --no-print-directory; fi
	@if [ -f $(NAME) ]; then make .remove tname=$(NAME) t1=$(NAME) t2=$(NAME) --no-print-directory; fi
	@if [ -f $(NAME_BONUS) ]; then make .remove tname=$(NAME_BONUS) t1=$(NAME_BONUS) t2=$(NAME_BONUS) --no-print-directory; fi

re: fclean all

# Bonus Rules
bonus: $(header) $(JAL) $(MLX) $(NAME_BONUS)

$(O_DIR)/bonus/%.o: src/%.c
	@mkdir -p $(dir $@)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME_BONUS) print_file=$(notdir $@) --no-print-directory
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(LIB_INC)

$(NAME_BONUS): $(OBJ_BONUS)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME_BONUS) print_file=$(NAME_BONUS) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@ $(LIB_ADD)
	@make .print_end print_color="$(y)" print_action="Compiling" print_name=$(NAME_BONUS) --no-print-directory

# JAL Rule
$(JAL):
	@make -C $(JAL_DIR) col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory

# MLX Rules
$(MLX):
	@make .print_start print_color="$(y)" print_action="Compiling" print_name="MLX" print_file=$(notdir $(MLX)) --no-print-directory
	@make -C $(MLX_DIR) all --no-print-directory > /dev/null 2>&1;
	@make .print_end print_color="$(y)" print_action="Compiling" print_name="MLX" --no-print-directory

mlx_fclean:
	@make .print_start print_color="$(p)" print_action="Removing" print_name="MLX" print_file=$(notdir $(MLX)) --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1;
	@make .print_end print_color="$(p)" print_action="Removing" print_name="MLX" --no-print-directory

# Custom Rules
.print_start:
	@printf "$(print_color)%-$(col1pad).$(col1pad)s$(r) %-$(col2pad).$(col2pad)s %s$(c)\r" "$(print_action)" "$(print_name)" "$(print_file)"

.print_end:
	@printf "$(print_color)%-$(col1pad).$(col1pad)s$(r) %-$(col2pad).$(col2pad)s $(g)Success$(r)$(c)\n" "$(print_action)" "$(print_name)"

.remove:
	@make .print_start print_color="$(p)" print_action="Removing" print_name=$(tname) print_file=$(t1) --no-print-directory
	@$(RM) $(t1)
	@make .print_start print_color="$(p)" print_action="Removing" print_name=$(tname) print_file=$(t2) --no-print-directory
	@$(RM) $(t2)
	@make .print_end print_color="$(p)" print_action="Removing" print_name=$(tname) --no-print-directory

# Headers
$(header):
	@mkdir -p $(O_DIR)
	@printf "$(y)\n"
	@printf "                  888       .d8888b.  8888888b.       \n"
	@printf "                  888      d88P  Y88b 888  \"Y88b     \n"
	@printf "                  888           .d88P 888    888      \n"
	@printf " .d8888b 888  888 88888b.      8888\"  888    888     \n"
	@printf "d88P\"    888  888 888\"88b     \"Y8b.   888    888   \n"
	@printf "888      888  888 888  888 888    888 888    888      \n"
	@printf "Y88b.    Y88b 888 888 d88P Y88b  d88P 888  .d88P      \n"
	@printf " \"Y8888P \"Y88888  88888P\"  \"Y8888P\"   8888888P\" \n"
	@printf "                                                      \n"
	@printf "                 by fsilva-p, joao-alm & ChatGPT      \n"
	@printf "$(r)\n"
	@touch $(header)

# Colours
c	= \033[K
p	= \033[38;2;211;125;174m
y	= \033[38;2;255;231;151m
g	= \033[38;2;117;197;141m
b	= \033[1m
r	= \033[0m

# Phony
.PHONY: all clean fclean re
