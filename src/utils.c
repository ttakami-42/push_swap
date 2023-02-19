/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 03:16:36 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:18:24 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_inputlen(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

void	puterr_exit(void)
{
	ft_putendl_fd(MSG_FAILURE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
