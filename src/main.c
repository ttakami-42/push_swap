/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:18:42 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/21 02:55:28 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*vals;
	int	size;
	int	is_sorted;

	size = argc - 1;
	if (!parse_input(argc, argv, &vals, &size))
		puterr_exit();
	is_sorted = push_swap(vals, size);
	free(vals);
	if (!is_sorted)
		puterr_exit();
	exit(EXIT_SUCCESS);
}
