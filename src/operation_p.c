/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:37:39 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:22:04 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_pa(t_stk_info *in)
{
	t_elem	*new;

	new = stack_pop(in->b);
	if (!new)
		return (1);
	stack_push(in->a, new);
	if (!operationlist_add_back(in, PUSH_A))
		return (0);
	in->a->min = stack_get_min(in->a);
	in->a->max = stack_get_max(in->a);
	in->b->min = stack_get_min(in->b);
	in->b->max = stack_get_max(in->b);
	return (1);
}

int	operation_pb(t_stk_info *in)
{
	t_elem	*new;

	new = stack_pop(in->a);
	if (!new)
		return (1);
	stack_push(in->b, new);
	if (!operationlist_add_back(in, PUSH_B))
		return (0);
	in->a->min = stack_get_min(in->a);
	in->a->max = stack_get_max(in->a);
	in->b->min = stack_get_min(in->b);
	in->b->max = stack_get_max(in->b);
	return (1);
}
