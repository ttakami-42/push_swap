/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_six_or_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:16:59 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/26 02:31:08 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	optimizer(t_stk_info *in, int bkt_size);
static int	optimizer_opes(t_stk_info *in, int val_limit, int bkt_size);
static int	sorter(t_stk_info *in);

int	solver_six_or_more(t_stk_info *in)
{
	while (in->a->size >= REF_NUM_HIGH && !stack_is_sorted(in->a))
		if (!optimizer(in, in->a->size / 9))
			return (0);
	while (in->a->size >= REF_NUM_MID && !stack_is_sorted(in->a))
		if (!optimizer(in, in->a->size / 7))
			return (0);
	while (in->a->size >= REF_NUM_BASE && !stack_is_sorted(in->a))
		if (!optimizer(in, in->a->size / 5))
			return (0);
	while (in->a->size > REF_NUM_LOW && !stack_is_sorted(in->a))
		if (!optimizer(in, in->a->size / 4))
			return (0);
	while (in->a->size > 1 && !stack_is_sorted(in->a))
		if (!optimizer(in, in->a->max - 1))
			return (0);
	while (in->b->top)
		if (!sorter(in))
			return (0);
	return (1);
}

static int	optimizer(t_stk_info *in, int bkt_size)
{
	int	val_limit;

	val_limit = in->a->min + bkt_size;
	while (in->a->size > 1 && in->a->min < val_limit && !stack_is_sorted(in->a))
		if (!optimizer_opes(in, val_limit, bkt_size))
			return (0);
	return (1);
}

static int	optimizer_opes(t_stk_info *in, int val_limit, int bkt_size)
{
	if (in->a->top->value != in->a->max && in->a->top->value <= val_limit)
		return (operation_pb(in));
	else if (in->a->top->value != in->a->max && in->a->top->value > val_limit
		&& in->a->top->value <= val_limit + (bkt_size / 3 * 2))
	{
		if (!operation_pb(in) || !operation_smart_r(in, bkt_size))
			return (0);
	}
	else if (in->a->top->next->value != in->a->max
		&& in->a->top->next->value <= val_limit)
	{
		if (!operation_smart_s(in, val_limit) || !operation_pb(in))
			return (0);
	}
	else if (in->a->bottom->value != in->a->max
		&& in->a->bottom->value <= val_limit)
	{
		if (!operation_rra(in) || !operation_pb(in))
			return (0);
	}
	else
		return (operation_ra(in));
	return (1);
}

static int	sorter(t_stk_info *in)
{
	while (in->b->top->value != in->b->max)
	{
		if (stack_get_index(in->b, in->b->max) > (in->b->size / 2))
		{
			if (!operation_rrb(in))
				return (0);
		}
		else
		{
			if (!operation_rb(in))
				return (0);
		}
		if (in->b->top->value == in->b->max - 1)
			if (!operation_pa(in))
				return (0);
	}
	if (!operation_pa(in))
		return (0);
	if (in->a->top->value != in->a->min
		&& in->b->top->value < in->b->top->next->value)
		return (operation_ss(in));
	if (in->a->top->value != in->a->min)
		return (operation_sa(in));
	return (1);
}
