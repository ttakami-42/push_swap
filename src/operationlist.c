/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:56:53 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:22:36 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operationlist_add_back(t_stk_info *in, int op)
{
	t_opelst	*temp;
	t_opelst	*new;

	temp = in->opelst;
	new = (t_opelst *)malloc(sizeof(t_opelst));
	if (!new)
		return (0);
	new->next = NULL;
	new->prev = NULL;
	new->op = op;
	if (!temp)
		in->opelst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	return (1);
}

char	*operationlist_name(int op)
{
	if (op == SWAP_A)
		return (MSG_SWAP_A);
	else if (op == SWAP_B)
		return (MSG_SWAP_B);
	else if (op == SWAP_BOTH)
		return (MSG_SWAP_BOTH);
	else if (op == PUSH_A)
		return (MSG_PUSH_A);
	else if (op == PUSH_B)
		return (MSG_PUSH_B);
	else if (op == ROTATE_A)
		return (MSG_ROTATE_A);
	else if (op == ROTATE_B)
		return (MSG_ROTATE_B);
	else if (op == ROTATE_BOTH)
		return (MSG_ROTATE_BOTH);
	else if (op == R_ROTATE_A)
		return (MSG_R_ROTATE_A);
	else if (op == R_ROTATE_B)
		return (MSG_R_ROTATE_B);
	else if (op == R_ROTATE_BOTH)
		return (MSG_R_ROTATE_BOTH);
	else
		return (MSG_FAILURE);
}

void	operationlist_print(t_opelst *lst)
{
	t_opelst	*temp;

	temp = lst;
	while (temp)
	{
		ft_putendl_fd(operationlist_name(temp->op), STDOUT_FILENO);
		temp = temp->next;
	}
}

void	operationlist_free(t_opelst *lst)
{
	t_opelst	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}
