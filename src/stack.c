/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:42:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:19:58 by ttakami          ###   ########.fr       */
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

	el = NULL;
	if (self->top == NULL)
		return (el);
	el = self->top;
	self->top = el->next;
	if (self->top)
		self->top->prev = NULL;
	el->prev = NULL;
	el->next = NULL;
	self->size -= 1;
	return (el);
}

int	stack_add_a_front(t_stk_info *in, int *vals)
{
	int		i;
	t_elem	*new;

	i = 0;
	while (i < in->size)
	{
		new = element_new(vals[i]);
		if (!new)
			return (0);
		stack_push(in->a, new);
		i++;
	}
	in->a->max = in->size - 1;
	in->b->max = in->size - 1;
	in->a->min = 0;
	in->a->size = in->size;
	return (1);
}

void	stack_reverse_a(t_stk_info *in)
{
	t_elem	*el;
	t_elem	*save;
	t_stk	*sa;

	sa = in->a;
	el = sa->bottom;
	sa->top = sa->bottom;
	while (el)
	{
		save = el->prev;
		el->prev = el->next;
		el->next = save;
		sa->bottom = el;
		el = save;
	}
}