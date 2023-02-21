/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:08 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/18 18:59:52 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*element_new(int val)
{
	t_elem	*ptr;

	ptr = (t_elem *)malloc(sizeof(t_elem));
	if (!ptr)
		return (NULL);
	ptr->value = val;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_elem	*element_last(t_elem *el)
{
	if (!el)
		return (NULL);
	while (el->next)
		el = el->next;
	return (el);
}

void	element_add_back(t_elem **el, t_elem *new)
{
	t_elem	*cur_last;

	cur_last = element_last(*el);
	if (!cur_last)
		*el = new;
	else
	{
		new->prev = *el;
		cur_last->next = new;
	}
}