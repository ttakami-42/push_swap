/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_less_than_six.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:12:38 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/21 01:06:39 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_b(t_stk_info *in);
static int	sort_three(t_stk_info *in, int fir, int sec, int thi);

int	solver_less_than_six(t_stk_info *in)
{
	while (in->a->size > 3)
		if (!push_b(in))
			return (0);
	if (in->a->size == 3 && !stack_is_sorted(in->a))
	{
		if (!sort_three(in, in->a->top->value, in->a->top->next->value,
				in->a->top->next->next->value))
			return (0);
	}
	else if (in->a->size == 2 && !stack_is_sorted(in->a))
	{
		if (!operation_sa(in))
			return (0);
	}
	while (in->b->top)
		if (!operation_pa(in))
			return (0);
	return (1);
}

static int	push_b(t_stk_info *in)
{
	int	min_idx;

	min_idx = stack_get_index(in->a, stack_get_min(in->a));
	if (min_idx == 4)
		if (!operation_rra(in))
			return (0);
	if (min_idx == 3)
		if (!operation_ra(in))
			return (0);
	if (min_idx >= 2 && 3 >= min_idx)
		if (!operation_ra(in))
			return (0);
	if (min_idx >= 1 && 3 >= min_idx)
		if (!operation_ra(in))
			return (0);
	return (operation_pb(in));
}

static int	sort_three(t_stk_info *in, int fir, int sec, int thi)
{
	if (fir < sec && sec > thi && fir < thi)
	{
		if (!operation_sa(in))
			return (0);
		return (operation_ra(in));
	}
	else if (fir > sec && sec < thi && fir < thi)
		return (operation_sa(in));
	else if (fir < sec && sec > thi && fir > thi)
		return (operation_rra(in));
	else if (fir > sec && sec < thi && fir > thi)
		return (operation_ra(in));
	else
	{
		if (!operation_sa(in))
			return (0);
		return (operation_rra(in));
	}
}
