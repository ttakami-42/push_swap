# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:46:07 by ttakami           #+#    #+#              #
#    Updated: 2023/02/23 18:25:06 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
DEBUG		= -g -fsanitize=address -fsanitize=undefined
LEAK		= -g -fsanitize=leak
SRCS		=   utils.c \
				convert_input.c \
				validate_input.c \
				parse_input.c \
				element.c \
				stack.c \
				stack_utils.c \
				stack_info.c \
				opelst.c \
				operation_s.c \
				operation_p.c \
				operation_r.c \
				operation_rr.c \
				solver_less_than_six.c \
				solver_six_or_more.c \
				push_swap.c \
				main.c
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

$(OBJDIR)/%.o:	%.c
	@[ -d $(OBJDIR) ]
	$(CC) -c $(CFLAGS) -o $@ $< $(HEADERPATH)

$(LIBFT):
	@make bonus -C libft

$(NAME):	$(LIBFT) $(ALL_OBJS)
	$(CC) -o $(NAME) $(ALL_OBJS) $(LIBFT)

debug:	directories $(NAME)
	$(CC) $(DEBUG) -o $(NAME) $(ALL_OBJS) $(LIBFT)

leak:	directories $(NAME)
	$(CC) $(LEAK) -o $(NAME) $(ALL_OBJS) $(LIBFT)

.PHONY:	all clean fclean re debug leak

#.PHONY:	all clean fclean re bonus debug

vpath %.c src
