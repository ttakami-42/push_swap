/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:04:20 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/23 23:33:57 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stk *self)
{
	int		temp;
	t_elem	*el;

	temp = 0;
	if (!self)
		return (-1);
	el = self->top;
	while (el)
	{
		if (el->value < temp)
			return (0);
		temp = el->value;
		el = el->next;
	}
	return (1);
}

int	stack_get_max(t_stk *self)
{
	int		max;
	t_elem	*el;

	max = 0;
	if (!self)
		return (-1);
	el = self->top;
	while (el)
	{
		if (max < el->value)
			max = el->value;
		el = el->next;
	}
	return (max);
}

int	stack_get_min(t_stk *self)
{
	int		min;
	t_elem	*el;

	min = INT_MAX;
	if (!self)
		return (-1);
	el = self->top;
	while (el)
	{
		if (min > el->value)
			min = el->value;
		el = el->next;
	}
	return (min);
}

int	stack_get_index(t_stk *self, int num)
{
	int		idx;
	t_elem	*el;

	idx = 0;
	if (!self)
		return (-1);
	el = self->top;
	while (el)
	{
		if (num == el->value)
			return (idx);
		el = el->next;
		idx++;
	}
	return (-1);
}

void	stack_free(t_stk *stk)
{
	t_elem	*el;

	el = stack_pop(stk);
	while (el)
	{
		free(el);
		el = stack_pop(stk);
	}
	free(stk);
}
