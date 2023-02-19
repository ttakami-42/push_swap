# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:46:07 by ttakami           #+#    #+#              #
#    Updated: 2023/02/20 03:34:12 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= main.c \
				convert_input.c \
				validate_input.c \
				element.c \
				stack.c \
				stack_utils.c \
				stack_info.c \
				operationlist.c \
				operation_s.c \
				operation_p.c \
				operation_r.c \
				operation_rr.c \
				solver.c \
				solver_under_five.c \
				push_swap.c \
				utils.c
#SRCSB		=
OBJDIR		= obj
LIBFT		= libft/libft.a
HEADERPATH	= -I include
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#OBJSB		= $(addprefix $(OBJDIR)/, $(SRCSB:.c=.o))

#ifdef WITH_BONUS
#ALL_OBJS	= $(OBJSB)
#else
ALL_OBJS	= $(OBJS)
#endif

all:	directories $(NAME)

directories:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	@make -C libft clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re:	fclean all

#bonus:
#@$(MAKE) WITH_BONUS=1 $(NAME)

debug:		$(ALL_OBJS)
	gcc --sanitize=leak -o $(NAME) $(ALL_OBJS) ./libft/libft.a

$(OBJDIR)/%.o:	%.c
	@[ -d $(OBJDIR) ]
	$(CC) -c $(CFLAGS) -o $@ $< $(HEADERPATH)

$(LIBFT):
	@make bonus -C libft

$(NAME):	$(LIBFT) $(ALL_OBJS)
	gcc -o $(NAME) $(ALL_OBJS) ./libft/libft.a

.PHONY:	all clean fclean re

#.PHONY:	all clean fclean re bonus debug

vpath %.c src
