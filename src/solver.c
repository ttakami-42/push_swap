/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:16:59 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:20:40 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solver_push_b(t_stk_info *in, int mn);
static void	solver_push_a(t_stk_info *in);

int	solver(t_stk_info *in)
{
	if (in->size <= 5)
		solver_under_five(in);
	else
	{
		while (in->a->size >= REF_NUM_HIGH && !stack_is_sorted(in->a))
			solver_push_b(in, in->a->size / 9);
		while (in->a->size >= REF_NUM_MID && !stack_is_sorted(in->a))
			solver_push_b(in, in->a->size / 7);
		while (in->a->size >= REF_NUM_BASE && !stack_is_sorted(in->a))
			solver_push_b(in, in->a->size / 5);
		while (in->a->size > REF_NUM_LOW && !stack_is_sorted(in->a))
			solver_push_b(in, in->a->size / 4);
		while (in->a->size > 1)
			solver_push_b(in, in->a->max - 1);
		while (in->b->top)
			solver_push_a(in);
	}
	return (0);
}

static void	solver_push_b(t_stk_info *in, int mn)
{
	int	limit;

	limit = in->a->min + mn;
	while (in->a->size > 0 && in->a->min < limit)
	{
		if (in->a->top->value <= limit)
			operation_pb(in);
		else if (in->a->top->value != in->a->max && (in->a->top->value > limit)
			&& (in->a->top->value <= limit + (mn / 3 * 2)))
		{
			operation_pb(in);
			operation_smart_r(in, mn);
		}
		else if (in->a->top->next->value <= limit)
		{
			operation_smart_s(in, mn);
			operation_pb(in);
		}
		else if (in->a->bottom->value <= limit)
		{
			operation_rra(in);
			operation_pb(in);
		}
		else
			operation_ra(in);
	}
}

static void	solver_push_a(t_stk_info *in)
{
	int	flag;

	flag = 0;
	while (in->b->top->value != in->b->max)
	{
		if (stack_get_indexofnum(in->b, in->b->max)
			> (in->b->size / 2))
			operation_rrb(in);
		else
			operation_rb(in);
		if (in->b->top->value == in->b->max - 1)
		{
			operation_pa(in);
			flag = 1;
		}
	}
	operation_pa(in);
	if (flag)
	{
		if (in->b->top->value < in->b->top->next->value)
			operation_ss(in);
		else
			operation_sa(in);
	}
}
