/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:50 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 20:21:25 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *vals, int size)
{
	t_stk_info	in;
	void		(*f)(void *);

	f = opelst_print;
	if (!stack_info_init(&in, size))
		return (0);
	if (!stack_add_a_front(&in, vals))
	{
		free(vals);
		stack_info_deinit(&in);
		return (0);
	}
	free(vals);
	stack_reverse_a(&in);
	if (stack_is_sorted(in.a))
		return (1);
	if (!solver(&in))
		return (0);
	ft_lstiter(in.opelst, f);
	ft_lstclear(&(in.opelst), NULL);
	stack_info_deinit(&in);
	return (1);
}
