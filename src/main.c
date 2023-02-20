/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:18:42 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 23:25:43 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*vals;
	int		size;
	char	**input;

	size = argc - 1;
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			puterr_exit();
		size = count_inputlen(input);
	}
	else if (argc > 2)
		input = &(argv[1]);
	else
		exit(EXIT_SUCCESS);
	vals = validate_input(input, size);
	if (argc == 2)
		free_input(input);
	if (!vals)
		puterr_exit();
	if (!push_swap(vals, size))
		puterr_exit();
	exit(EXIT_SUCCESS);
}
