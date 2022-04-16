# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afuchs <afuchs@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 14:43:45 by afuchs            #+#    #+#              #
#    Updated: 2022/04/16 23:04:36 by afuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	=	main.c					\
			loading.c				\
			animate.c				\
			kb_events.c				\
			window.c				\
			map.c					\
			too_long.c				\
			ft_atoi.c				\
			ft_memcpy.c				\
			ft_split.c				\
			ft_bzero.c				\
			ft_memmove.c			\
			ft_strchr.c				\
			ft_calloc.c				\
			ft_memset.c				\
			ft_strdup.c				\
			ft_isalnum.c			\
			ft_minmax.c				\
			ft_striteri.c			\
			ft_isalpha.c			\
			ft_printf.c				\
			ft_strjoin.c			\
			ft_isascii.c			\
			ft_putchar_fd.c			\
			ft_strlcat.c			\
			ft_isdigit.c			\
			ft_putchar_l.c			\
			ft_strlcpy.c			\
			ft_isprint.c			\
			ft_putendl_fd.c			\
			ft_strlen.c				\
			ft_itoa.c				\
			ft_putnbr_fd.c			\
			ft_strmapi.c			\
			ft_lstadd_back_bonus.c	\
			ft_putnbr_l.c			\
			ft_strncmp.c			\
			ft_lstadd_front_bonus.c	\
			ft_putnbr_lo.c			\
			ft_strnstr.c			\
			ft_lstclear_bonus.c		\
			ft_putnbrad_l.c			\
			ft_strrchr.c			\
			ft_lstdelone_bonus.c	\
			ft_putnbrh_l.c			\
			ft_strtrim.c			\
			ft_lstiter_bonus.c		\
			ft_putnbru_l.c			\
			ft_substr.c				\
			ft_lstlast_bonus.c		\
			ft_putnbru_lo.c			\
			ft_tolower.c			\
			ft_lstmap_bonus.c		\
			ft_putnbrux_lo.c		\
			ft_toupper.c			\
			ft_lstnew_bonus.c		\
			ft_putnbrx_lo.c			\
			get_next_line.c			\
			ft_lstsize_bonus.c		\
			ft_putnchar_l.c			\
			get_next_line_utils.c	\
			ft_memchr.c				\
			ft_putstr_fd.c			\
			ft_memcmp.c				\
			ft_putstr_l.c			\

LHEADER	= libft.h

SHEADER = so_long.h

OPATH	= obj/

LPATH	= libft/

SPATH	= srcs/

OBJ		= $(SRCS:%.c=$(OPATH)%.o)

OPT		= -Wall -Werror -Wextra -g

MLX		= -lmlx

MATH	= -lm

NAME	= so_long

all				:	$(NAME)

$(NAME)			:	$(OPATH) $(OBJ)
					@gcc $(OPT) $(MLX) $(MATH) $(OBJ) -o $(NAME)
					@echo "\033[32mCompilation complete.\033[0m"

$(OPATH)%.o		:	$(SPATH)%.c $(SPATH)$(SHEADER)
					@gcc -c $(OPT) $< -o $@
					@echo "\033[90m$@ objects file created.\033[0m"

$(OPATH)%.o		:	$(LPATH)%.c $(LPATH)$(LHEADER)
					@gcc -c $(OPT) $< -o $@
					@echo "\033[90m$@ object file created.\033[0m"

$(OPATH)		:	
					@mkdir $(OPATH)

clean			:
					@rm -rf $(OPATH)
					@echo "\033[31mObject files deleted.\033[0m"

fclean			:	clean
					@rm -rf $(NAME)
					@echo "\033[31m$(NAME) deleted.\033[0m"

re				:	fclean all

.PHONY			:	all clean fclean re
