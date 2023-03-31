# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:46:07 by ttakami           #+#    #+#              #
#    Updated: 2023/03/31 12:08:12 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

ifdef WITH_DEBUG
	CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=undefined
endif

ifdef WITH_LEAK
	CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=leak
endif

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
LIBFTDIR	= libft
LIBFT		= $(addprefix $(LIBFTDIR)/, libft.a)
INC			= -Iinclude -I$(LIBFTDIR)
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@[ -d $(OBJDIR) ]
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	@make bonus --no-print-directory -sC $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@make fclean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

re: fclean all

debug: fclean
	@make --no-print-directory WITH_DEBUG=1
	@echo "$(GREEN)***   You can debug $(NAME)   ***\n$(RESET)"

leak: fclean
	@make --no-print-directory WITH_LEAK=1
	@echo "$(GREEN)***   You can see leaks $(NAME)   ***\n$(RESET)"

.PHONY:	all clean fclean re debug leak

vpath %.c src
