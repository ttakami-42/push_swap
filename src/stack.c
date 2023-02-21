/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:42:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/21 02:53:09 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stack_new(void)
{
	t_stk	*ptr;

	ptr = (t_stk *)malloc(sizeof(t_stk));
	if (!ptr)
		return (NULL);
	ptr->top = NULL;
	ptr->bottom = NULL;
	ptr->size = 0;
	return (ptr);
}

void	stack_push(t_stk *self, t_elem *el)
{
	if (self->top)
	{
		el->next = self->top;
		self->top->prev = el;
	}
	else
	{
		self->bottom = el;
		el->next = NULL;
	}
	self->top = el;
	self->size += 1;
}

t_elem	*stack_pop(t_stk *self)
{
	t_elem	*el;

	el = self->top;
	if (self->top == NULL)
		return (el);
	self->top = el->next;
	if (self->top)
		self->top->prev = NULL;
	el->prev = NULL;
	el->next = NULL;
	self->size -= 1;
	return (el);
}

int	stack_add_a_back(t_stk_info *in, int *vals)
{
	int		i;
	t_elem	*new;

	i = 0;
	while (i < in->size)
	{
		new = element_new(vals[i]);
		if (!new)
			return (0);
		element_add_back(in->a->top, new);
		in->a->bottom = new;
		i++;
	}
	in->a->max = in->size - 1;
	in->b->max = in->size - 1;
	in->a->min = 0;
	in->a->size = in->size;
	return (1);
}
