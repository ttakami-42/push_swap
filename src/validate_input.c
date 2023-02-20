/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:36:36 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:17:42 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_sorted_values(int *values, int size);
static void	sort_array(int *arr, int left, int right);
static int	is_duplicated(int *values, int size);
static void	compress_array(int *vals, int *sorted_vals, int size);

int	*validate_input(char **input, int size)
{
	int		*values;
	int		*sorted_values;

	values = convert_input_to_array(input, size);
	if (!values)
		return (NULL);
	sorted_values = create_sorted_values(values, size);
	if (!sorted_values || is_duplicated(sorted_values, size))
	{
		free(values);
		free(sorted_values);
		return (NULL);
	}
	compress_array(values, sorted_values, size);
	free(sorted_values);
	return (values);
}

static int	*create_sorted_values(int *values, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = values[i];
		i++;
	}
	sort_array(arr, 0, size - 1);
	return (arr);
}

static void	sort_array(int *arr, int left, int right)
{
	int		shaft;
	int		temp;
	int		i;
	int		j;

	if (left < right)
	{
		shaft = arr[(left + right) / 2];
		i = left - 1;
		j = right + 1;
		while (1)
		{
			while (arr[++i] < shaft)
				;
			while (arr[--j] > shaft)
				;
			if (i >= j)
				break ;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		sort_array(arr, left, i - 1);
		sort_array(arr, j + 1, right);
	}
}

static int	is_duplicated(int *values, int size)
{
	int	prev;
	int	i;

	prev = values[0];
	i = 1;
	while (i < size)
	{
		if (prev == values[i])
			return (1);
		prev = values[i];
		i++;
	}
	return (0);
}

static void	compress_array(int *vals, int *sorted_vals, int size)
{
	int	i;
	int	head;
	int	tail;
	int	middle;

	i = 0;
	while (i < size)
	{
		head = 0;
		tail = size;
		while (head <= tail)
		{
			middle = (head + tail) / 2;
			if (vals[i] == sorted_vals[middle])
				break ;
			else if (sorted_vals[middle] < vals[i])
				head = middle + 1;
			else
				tail = middle - 1;
		}
		vals[i] = middle;
		i++;
	}
}
