/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:37:39 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/02 01:43:05 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_pa(t_stk_info *in)
{
	t_elem	*new;

	if (!opelst_add_back(&in->opelst, MSG_PUSH_A))
		return (0);
	new = stack_pop(in->b);
	if (new)
	{
		stack_push(in->a, new);
		in->a->min = stack_get_min(in->a);
		in->a->max = stack_get_max(in->a);
		in->b->min = stack_get_min(in->b);
		in->b->max = stack_get_max(in->b);
	}
	return (1);
}

int	operation_pb(t_stk_info *in)
{
	t_elem	*new;

	if (!opelst_add_back(&in->opelst, MSG_PUSH_B))
		return (0);
	new = stack_pop(in->a);
	if (new)
	{
		stack_push(in->b, new);
		in->a->min = stack_get_min(in->a);
		in->a->max = stack_get_max(in->a);
		in->b->min = stack_get_min(in->b);
		in->b->max = stack_get_max(in->b);
	}
	return (1);
}
