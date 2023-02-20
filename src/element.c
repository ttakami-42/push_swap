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
