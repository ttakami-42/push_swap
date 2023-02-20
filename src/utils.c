/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 03:16:36 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 23:37:05 by ttakami          ###   ########.fr       */
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

void	free_input(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	puterr_exit(void)
{
	ft_putendl_fd(MSG_FAILURE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
