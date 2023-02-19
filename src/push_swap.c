/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:50 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:20:51 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *vals, int size)
{
	t_stk_info	in;

	if (!stack_info_init(&in, size))
		return (0);
	if (!stack_add_a_front(&in, vals))
	{
		free(vals);
		stack_free(in.a);
		stack_free(in.b);
		return (0);
	}
	free(vals);
	stack_reverse_a(&in);
	if (stack_is_sorted(in.a))
		return (1);
	solver(&in);
	operationlist_print(in.opelst);
	stack_info_deinit(&in);
	return (1);
}
