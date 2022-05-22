# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:02:47 by yolee             #+#    #+#              #
#    Updated: 2022/05/16 19:23:20 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./libft -I ./srcs -I ./bonus

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./libft
LIBFT = libft.a

SRCS_DIR = ./srcs
SRCS_FILE = ft_printf.c \
	parse_char.c \
	parse_decimal.c \
	parse_etc.c \
	parse_lower_hexadecimal.c \
	parse_ptr.c \
	parse_str.c \
	parse_unsigned_decimal.c \
	parse_upper_hexadecimal.c \
	
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

SRCS_DIR_B = ./bonus
SRCS_FILE_B = ft_printf_bonus.c \
	flag_control_bonus.c \
	manage_format_str_bonus.c \
	parse_char_bonus.c \
	parse_decimal_bonus.c \
	parse_etc_bonus.c \
	parse_lower_hexadecimal_bonus.c \
	parse_ptr_bonus.c \
	parse_str_bonus.c \
	parse_unsigned_decimal_bonus.c \
	parse_upper_hexadecimal_bonus.c \

SRCS_B = $(addprefix $(SRCS_DIR_B)/, $(SRCS_FILE_B))
	
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef BONUS_FLAG
	OBJS = $(OBJS_B)
endif

all : $(LIBFT) $(NAME)

$(LIBFT) :
	$(MAKE) bonus -C $(LIBFT_DIR)

bonus :
	$(MAKE) BONUS_FLAG=1

%.o : %.c
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $?

clean : 
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	
re : fclean all
	
.PHONY : bonus all clean fclean re