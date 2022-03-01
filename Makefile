# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:02:47 by yolee             #+#    #+#              #
#    Updated: 2022/03/01 23:11:50 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./libft

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./libft
LIBFT = libft.a

SRCS = ft_printf.c \
	ft_itoa_hex.c \
	ft_ptoa.c \
	ft_uitoa.c \
	parse_func1.c \
	parse_func2.c \

SRCS_B = ft_printf_bonus.c \
	ft_itoa_hex_bonus.c \
	ft_ptoa_bonus.c \
	ft_uitoa_bonus.c \
	parse_func1_bonus.c \
	parse_func2_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef BONUS_FLAG
	OBJS += $(OBJS_B)
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
	
re : fclean bonus
	
.PHONY : libft bonus all clean fclean re