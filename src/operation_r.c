/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:48:50 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/25 17:40:03 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_ra(t_stk_info *in)
{
	t_elem	*new_bottom;

	if (!in->a->top || !in->a->top->next)
		return (1);
	new_bottom = stack_pop(in->a);
	if (!new_bottom)
		return (1);
	if (!opelst_add_back(&in->opelst, MSG_ROTATE_A))
		return (0);
	new_bottom->prev = in->a->bottom;
	new_bottom->next = NULL;
	in->a->bottom->next = new_bottom;
	in->a->bottom = new_bottom;
	in->a->size += 1;
	return (1);
}

int	operation_rb(t_stk_info *in)
{
	t_elem	*new_bottom;

	if (!in->b->top || !in->b->top->next)
		return (1);
	new_bottom = stack_pop(in->b);
	if (!new_bottom)
		return (1);
	if (!opelst_add_back(&in->opelst, MSG_ROTATE_B))
		return (0);
	new_bottom->prev = in->b->bottom;
	new_bottom->next = NULL;
	in->b->bottom->next = new_bottom;
	in->b->bottom = new_bottom;
	in->b->size += 1;
	return (1);
}

int	operation_rr(t_stk_info *in)
{
	t_elem	*new_bottom_a;
	t_elem	*new_bottom_b;

	if (!in->a->top || !in->a->top->next || !in->b->top || !in->b->top->next)
		return (1);
	new_bottom_a = stack_pop(in->a);
	new_bottom_b = stack_pop(in->b);
	if (!new_bottom_a || !new_bottom_b)
		return (1);
	if (!opelst_add_back(&in->opelst, MSG_ROTATE_BOTH))
		return (0);
	new_bottom_a->prev = in->a->bottom;
	new_bottom_a->next = NULL;
	in->a->bottom->next = new_bottom_a;
	in->a->bottom = new_bottom_a;
	in->a->size += 1;
	new_bottom_b->prev = in->b->bottom;
	new_bottom_b->next = NULL;
	in->b->bottom->next = new_bottom_b;
	in->b->bottom = new_bottom_b;
	in->b->size += 1;
	return (1);
}

int	operation_smart_r(t_stk_info *in, int bkt_size)
{
	int	val_limit;

	val_limit = in->a->min + bkt_size;
	if (in->a->top->value > val_limit
		&& in->a->top->value > val_limit + (bkt_size / 3 * 2))
		return (operation_rr(in));
	else
		return (operation_rb(in));
}
