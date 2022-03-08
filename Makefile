# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:02:47 by yolee             #+#    #+#              #
#    Updated: 2022/03/09 00:46:55 by yolee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./libft -I ./srcs

AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./libft
LIBFT = libft.a

SRCS_DIR = ./srcs
SRCS_FILE = ft_printf.c \
	ft_uitoa_hex.c \
	ft_uitoa.c \
	ft_ptoa.c \
	parse_func1.c \
	parse_func2.c \
	
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

SRCS_DIR_B = ./bonus
SRCS_FILE_B = ft_printf_bonus.c \
	ft_uitoa_hex_bonus.c \
	ft_uitoa_bonus.c \
	ft_ptoa_bonus.c \
	parse_func1_bonus.c \
	parse_func2_bonus.c \

SRCS_B = $(addprefix $(SRCS_DIR_B)/, $(SRCS_FILE_B))
	
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
	
.PHONY : bonus all clean fclean re