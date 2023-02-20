/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opelst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:49:26 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 20:12:37 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opelst_add_back(t_list **lst, char *op)
{
	t_list	*new;

	new = ft_lstnew(op);
	if (!new)
		return (0);
	ft_lstadd_back(lst, new);
	return (1);
}

void	opelst_print(void *op)
{
	ft_putendl_fd(op, STDOUT_FILENO);
}
