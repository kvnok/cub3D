SHELL := /bin/bash

NAME := cub3D

SRC_FILES	:=	main.c			\
				init_cleanup.c	\
				casting/dda/dda_main.c	\
				casting/dda/dda_calc.c	\
				casting/dda/dda_init.c	\
				casting/buffer.c		\
				\
				tmp.c

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
MLX_DIR := MLX42

OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
DEP_FILES := $(OBJ_FILES:.o=.d)

# SRC_SUBD = $(shell find $(SRC_DIR) -type d)
# OBJ_SUBD = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCSUBD))

MLX42 := $(MLX42_DIR)/build/libmlx42.a

CC  := cc

IFLAGS := -I $(INC_DIR) -I $(MLX_DIR)/include/$(MLX_DIR)
LFLAGS := -L $(MLX_DIR)/build -lmlx42 -lglfw -ldl -pthread -lm
CFLAGS := -Wall -Wextra -Werror -MMD -MP -g

_DEBUG := 0
ifeq ($(_DEBUG),1)
	LFLAGS += -g3 -fsanitize=address
endif

all: $(MLX42) $(NAME)

$(MLX42):
	git submodule update --init
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	$(MAKE) -C $(MLX_DIR)/build -j4 --quiet

$(NAME): $(OBJ_FILES)
	$(CC) $^ $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP_FILES)

clean:
	$(MAKE) clean -C $(MLX_DIR)/build -j4 --quiet
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) clean/fast -C $(MLX_DIR)/build -j4 --quiet
	-rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
