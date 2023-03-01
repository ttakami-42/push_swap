/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:52:13 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/02 01:43:54 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_sa(t_stk_info *in)
{
	int	temp;

	if (!opelst_add_back(&in->opelst, MSG_SWAP_A))
		return (0);
	if (!in->a->top || !in->a->top->next)
		return (1);
	temp = in->a->top->next->value;
	in->a->top->next->value = in->a->top->value;
	in->a->top->value = temp;
	return (1);
}

int	operation_sb(t_stk_info *in)
{
	int	temp;

	if (!opelst_add_back(&in->opelst, MSG_SWAP_B))
		return (0);
	if (!in->b->top || !in->b->top->next)
		return (1);
	temp = in->b->top->next->value;
	in->b->top->next->value = in->b->top->value;
	in->b->top->value = temp;
	return (1);
}

int	operation_ss(t_stk_info *in)
{
	int	temp;

	if (!opelst_add_back(&in->opelst, MSG_SWAP_BOTH))
		return (0);
	if (!in->a->top || !in->a->top->next || !in->b->top || !in->b->top->next)
		return (1);
	temp = in->a->top->next->value;
	in->a->top->next->value = in->a->top->value;
	in->a->top->value = temp;
	temp = in->b->top->next->value;
	in->b->top->next->value = in->b->top->value;
	in->b->top->value = temp;
	return (1);
}

int	operation_smart_s(t_stk_info *in, int val_limit)
{
	if (in->b->top && in->b->top->next
		&& in->b->top->value < in->b->top->next->value
		&& in->b->top->next->value <= val_limit)
		return (operation_ss(in));
	else
		return (operation_sa(in));
}
