# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:43:46 by gabrodri          #+#    #+#              #
#    Updated: 2023/11/03 20:53:02 by gabrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra -I. -c

# Libft folder
#LIBFT_DIR   = libft

# Mandatory part
PART	= ft_printf.c \
		ft_print_char.c \
		ft_print_string.c \
		ft_print_decimal.c \
		ft_print_unsigned_decimal.c \
		ft_print_hexadecimal.c \
		ft_print_pointer.c \

OBJ		= $(PART:.c=.o)

# Bonus part
BONUS   = ft_printf_bonus.c
OBJ_BONUS = $(BONUS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "------------------------------------"
	@echo "Compiling libft"
	@echo "------------------------------------"
	# Make the libft library
	make bonus -C ./libft
	# Copy the libft.a file to the root of the project
	cp libft/libft.a .
	# Rename the libft.a file to $(NAME)
	mv libft.a $(NAME)

	@echo "------------------------------------"
	@echo "Compiling ft_printf Mandatory Part"
	@echo "------------------------------------"
	ar rcs $(NAME) $(OBJ)

# bonus: $(OBJ_BONUS)
# 	@echo "------------------------------------"
# 	@echo "Compiling ft_printf Bonus Part"
# 	@echo "------------------------------------"
# 	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

# Add a target to run tests using the test.sh script
test: all
	sh ./tests/test.sh

libft_clean:
	@echo "------------------------------------"
	@echo "Cleaning the libft object files"
	@echo "------------------------------------"
	make clean -C libft

clean: libft_clean
	@echo "------------------------------------"
	@echo "Cleaning the object files"
	@echo "------------------------------------"
	rm -f $(OBJ)

fclean: clean
	@echo "------------------------------------"
	@echo "Cleaning the object files and the libraries"
	@echo "------------------------------------"
	rm -f $(NAME)

re: fclean all

# .PHONY targets for clean, fclean, all, and re for better Makefile behavior
.PHONY: clean fclean all re
