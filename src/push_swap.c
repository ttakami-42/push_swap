/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:50 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/21 02:52:54 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prepare(t_stk_info *in, int *vals, int size);

int	push_swap(int *vals, int size)
{
	t_stk_info	in;
	int			is_ok;
	void		(*f)(void *);

	f = opelst_print;
	if (!prepare(&in, vals, size))
		return (0);
	if (stack_is_sorted(in.a))
	{
		stack_info_deinit(&in);
		return (1);
	}
	if (in.size < REF_NUM_MINI)
		is_ok = solver_less_than_six(&in);
	else
		is_ok = solver_six_or_more(&in);
	if (!is_ok)
	{
		stack_info_deinit(&in);
		return (0);
	}
	ft_lstiter(in.opelst, f);
	stack_info_deinit(&in);
	return (1);
}

static int	prepare(t_stk_info *in, int *vals, int size)
{
	if (!stack_info_init(in, size))
		return (0);
	if (!stack_add_a_back(in, vals))
	{
		stack_info_deinit(in);
		return (0);
	}
	return (1);
}
