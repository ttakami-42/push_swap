/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_under_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:12:38 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:20:16 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solver_under_five_pb(t_stk_info *in);
static void	solver_three_elements(t_stk_info *in);

int	solver_under_five(t_stk_info *in)
{
	while (in->a->size > 3)
		solver_under_five_pb(in);
	if (in->a->size == 3 && !stack_is_sorted(in->a))
		solver_three_elements(in);
	else if (in->a->size == 2 && !stack_is_sorted(in->a))
		operation_sa(in);
	while (in->b->top)
		operation_pa(in);
	return (1);
}

static void	solver_under_five_pb(t_stk_info *in)
{
	int	min_idx;

	min_idx = stack_get_indexofnum(in->a, stack_get_min(in->a));
	if (min_idx == 4)
		operation_rra(in);
	if (min_idx == 3)
		operation_ra(in);
	if (min_idx >= 2 && 3 >= min_idx)
		operation_ra(in);
	if (min_idx >= 1 && 3 >= min_idx)
		operation_ra(in);
	operation_pb(in);
}

static void	solver_three_elements(t_stk_info *in)
{
	int	first;
	int	second;
	int	third;

	first = in->a->top->value;
	second = in->a->top->next->value;
	third = in->a->top->next->next->value;
	if (first < second && second > third && first < third)
	{
		operation_sa(in);
		operation_ra(in);
	}
	else if (first > second && second < third && first < third)
		operation_sa(in);
	else if (first < second && second > third && first > third)
		operation_rra(in);
	else if (first > second && second < third && first > third)
		operation_ra(in);
	else
	{
		operation_sa(in);
		operation_rra(in);
	}
}
