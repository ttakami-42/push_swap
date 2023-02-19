/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:01:36 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:19:41 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_info_init(t_stk_info *in, int size)
{
	in->a = stack_new();
	if (!in->a)
		return (0);
	in->b = stack_new();
	if (!in->b)
		return (0);
	in->b->min = INT_MAX;
	in->opelst = NULL;
	in->size = size;
	return (1);
}

void	stack_info_deinit(t_stk_info *in)
{
	operationlist_free(in->opelst);
	stack_free(in->a);
	stack_free(in->b);
}
