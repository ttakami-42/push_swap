/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:05:42 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/23 23:06:24 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_rra(t_stk_info *in)
{
	t_elem	*new_top;

	if (!in->a->top->next)
		return (1);
	if (!opelst_add_back(&in->opelst, MSG_R_ROTATE_A))
		return (0);
	new_top = in->a->bottom;
	in->a->bottom = in->a->bottom->prev;
	in->a->bottom->next = NULL;
	new_top->prev = NULL;
	new_top->next = in->a->top;
	in->a->top->prev = new_top;
	in->a->top = new_top;
	return (1);
}

int	operation_rrb(t_stk_info *in)
{
	t_elem	*new_top;

	if (!in->b->top->next)
		return (1);
	if (!opelst_add_back(&in->opelst, MSG_R_ROTATE_B))
		return (0);
	new_top = in->b->bottom;
	in->b->bottom = in->b->bottom->prev;
	in->b->bottom->next = NULL;
	new_top->prev = NULL;
	new_top->next = in->b->top;
	in->b->top->prev = new_top;
	in->b->top = new_top;
	return (1);
}

int	operation_rrr(t_stk_info *in)
{
	t_elem	*new_top;

	if (!in->a->top->next || !in->b->top->next)
		return (1);
	if (!opelst_add_back(&in->opelst, MSG_R_ROTATE_BOTH))
		return (0);
	new_top = in->a->bottom;
	in->a->bottom = in->a->bottom->prev;
	in->a->bottom->next = NULL;
	new_top->prev = NULL;
	new_top->next = in->a->top;
	in->a->top->prev = new_top;
	in->a->top = new_top;
	new_top = in->b->bottom;
	in->b->bottom = in->b->bottom->prev;
	in->b->bottom->next = NULL;
	new_top->prev = NULL;
	new_top->next = in->b->top;
	in->b->top->prev = new_top;
	in->b->top = new_top;
	return (1);
}
