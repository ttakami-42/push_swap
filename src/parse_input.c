/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:46:02 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/21 02:55:20 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char *argv[], int **vals, int *size)
{
	char **input;

	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			return (0);
		*size = count_inputlen(input);
	}
	else if (argc > 2)
		input = &(argv[1]);
	else
		return (0);
	*vals = validate_input(input, *size);
	if (argc == 2)
		free_input(input);
	if (!*vals)
		return (0);
	return (1);
}