/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_six_or_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:16:59 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/21 01:20:31 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_b(t_stk_info *in, int mn);
static int	push_b_opes(t_stk_info *in, t_elem *top, int limit, int mn);
static int	push_a(t_stk_info *in);
static int	should_rotate(t_stk_info *in);

int	solver_six_or_more(t_stk_info *in)
{
	while (in->a->size >= REF_NUM_HIGH && !stack_is_sorted(in->a))
		if (!push_b(in, in->a->size / 9))
			return (0);
	while (in->a->size >= REF_NUM_MID && !stack_is_sorted(in->a))
		if (!push_b(in, in->a->size / 7))
			return (0);
	while (in->a->size >= REF_NUM_BASE && !stack_is_sorted(in->a))
		if (!push_b(in, in->a->size / 5))
			return (0);
	while (in->a->size > REF_NUM_LOW && !stack_is_sorted(in->a))
		if (!push_b(in, in->a->size / 4))
			return (0);
	while (in->a->size > 1)
		if (!push_b(in, in->a->max - 1))
			return (0);
	while (in->b->top)
		if (!push_a(in))
			return (0);
	return (1);
}

static int	push_b(t_stk_info *in, int mn)
{
	int	limit;

	limit = in->a->min + mn;
	while (in->a->size > 0 && in->a->min < limit)
		if (!push_b_opes(in, in->a->top, limit, mn))
			return (0);
	return (1);
}

static int	push_b_opes(t_stk_info *in, t_elem *top, int limit, int mn)
{
	if (top->value <= limit)
		return (operation_pb(in));
	else if (top->value != in->a->max && (top->value > limit)
		&& (top->value <= limit + (mn / 3 * 2)))
	{
		if (!operation_pb(in))
			return (0);
		return (operation_smart_r(in, mn));
	}
	else if (top->next->value <= limit)
	{
		if (!operation_smart_s(in, mn))
			return (0);
		return (operation_pb(in));
	}
	else if (in->a->bottom->value <= limit)
	{
		if (!operation_rra(in))
			return (0);
		return (operation_pb(in));
	}
	else
		return (operation_ra(in));
}

static int	push_a(t_stk_info *in)
{
	int	flag;

	flag = 0;
	while (in->b->top->value != in->b->max)
	{
		if (!should_rotate(in))
			return (0);
		if (in->b->top->value == in->b->max - 1)
		{
			if (!operation_pa(in))
				return (0);
			flag = 1;
		}
	}
	if (!operation_pa(in))
		return (0);
	if (flag)
	{
		if (in->b->top->value < in->b->top->next->value)
			return (operation_ss(in));
		else
			return (operation_sa(in));
	}
	return (1);
}

static int	should_rotate(t_stk_info *in)
{
	if (stack_get_index(in->b, in->b->max) > (in->b->size / 2))
		return (operation_rrb(in));
	else
		return (operation_rb(in));
}
