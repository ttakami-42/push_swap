/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:30:23 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:23:44 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdio.h"

# define SWAP_A 1
# define SWAP_B 2
# define SWAP_BOTH 3
# define PUSH_A 4
# define PUSH_B 5
# define ROTATE_A 6
# define ROTATE_B 7
# define ROTATE_BOTH 8
# define R_ROTATE_A 9
# define R_ROTATE_B 10
# define R_ROTATE_BOTH 11

# define MSG_SWAP_A "sa"
# define MSG_SWAP_B "sb"
# define MSG_SWAP_BOTH "ss"
# define MSG_PUSH_A "pa"
# define MSG_PUSH_B "pb"
# define MSG_ROTATE_A "ra"
# define MSG_ROTATE_B "rb"
# define MSG_ROTATE_BOTH "rr"
# define MSG_R_ROTATE_A "rra"
# define MSG_R_ROTATE_B "rrb"
# define MSG_R_ROTATE_BOTH "rrr"

# define REF_NUM_LOW 10
# define REF_NUM_BASE 100
# define REF_NUM_MID 200
# define REF_NUM_HIGH 300

# define MSG_FAILURE "ERROR"

typedef struct s_element
{
	int					value;
	struct s_element	*next;
	struct s_element	*prev;
}				t_elem;

typedef struct s_stack
{
	t_elem	*top;
	t_elem	*bottom;
	int		size;
	int		min;
	int		max;
}				t_stk;

typedef struct s_operationlist
{
	int						op;
	struct s_operationlist	*next;
	struct s_operationlist	*prev;
}				t_opelst;

typedef struct s_stack_infomation
{
	t_stk		*a;
	t_stk		*b;
	t_opelst	*opelst;
	int			size;
}				t_stk_info;

int		count_inputlen(char **input);
int		*convert_input_to_array(char **inputs, int size);
int		*validate_input(char **input, int size);
t_elem	*element_new(int val);
t_stk	*stack_new(void);
void	stack_push(t_stk *self, t_elem *el);
t_elem	*stack_pop(t_stk *self);
int		stack_add_a_front(t_stk_info *in, int *vals);
void	stack_reverse_a(t_stk_info *in);
int		stack_info_init(t_stk_info *in, int size);
void	stack_info_deinit(t_stk_info *in);
int		stack_is_sorted(t_stk *self);
int		stack_get_max(t_stk *self);
int		stack_get_min(t_stk *self);
int		stack_get_indexofnum(t_stk *self, int num);
void	stack_free(t_stk *stk);
int		operationlist_add_back(t_stk_info *in, int op);
char	*operationlist_name(int op);
void	operationlist_print(t_opelst *lst);
void	operationlist_free(t_opelst *lst);
int		operation_sa(t_stk_info *in);
int		operation_sb(t_stk_info *in);
int		operation_ss(t_stk_info *in);
int		operation_pa(t_stk_info *in);
int		operation_pb(t_stk_info *in);
int		operation_ra(t_stk_info *in);
int		operation_rb(t_stk_info *in);
int		operation_rr(t_stk_info *in);
int		operation_rra(t_stk_info *in);
int		operation_rrb(t_stk_info *in);
int		operation_rrr(t_stk_info *in);
int		operation_smart_s(t_stk_info *in, int mn);
int		operation_smart_r(t_stk_info *in, int mn);
int		solver(t_stk_info *in);
int		solver_under_five(t_stk_info *in);
int		push_swap(int *vals, int size);
void	puterr_exit(void);

#endif