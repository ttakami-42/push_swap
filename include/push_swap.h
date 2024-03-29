/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:30:23 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 08:18:47 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

# define MSG_FAILURE "Error"

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

typedef struct s_stack_infomation
{
	t_stk		*a;
	t_stk		*b;
	t_list		*opelst;
	int			size;
}				t_stk_info;

int		count_inputlen(char **input);
int		*convert_input_to_array(char **inputs, int size);
int		*validate_input(char **input, int size);
int		parse_input(int argc, char *argv[], int **vals, int *size);
void	free_input(char **array);
t_elem	*element_new(int val);
t_elem	*element_last(t_elem *el);
void	element_add_back(t_elem **el, t_elem *new);
t_stk	*stack_new(void);
void	stack_push(t_stk *self, t_elem *el);
t_elem	*stack_pop(t_stk *self);
int		stack_add_a_back(t_stk_info *in, int *vals);
int		stack_is_sorted(t_stk *self);
int		stack_get_max(t_stk *self);
int		stack_get_min(t_stk *self);
int		stack_get_index(t_stk *self, int num);
void	stack_free(t_stk *stk);
int		stack_info_init(t_stk_info *in, int size);
void	stack_info_deinit(t_stk_info *in);
int		opelst_add_back(t_list **lst, char *op);
void	opelst_print(void *op);
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
int		operation_smart_s(t_stk_info *in, int val_limit);
int		operation_smart_r(t_stk_info *in, int bkt_size);
int		solver_less_than_six(t_stk_info *in);
int		solver_six_or_more(t_stk_info *in);
int		push_swap(int *vals, int size);
void	puterr_exit(void);

#endif