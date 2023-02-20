/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:27:27 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/20 04:22:48 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert_input_to_int(const char *str, int *flag);
static int	isoverflow_int(long num, int is_neg, int c);

int	*convert_input_to_array(char **inputs, int size)
{
	int	i;
	int	*values;
	int	is_err;

	i = 0;
	is_err = 0;
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (NULL);
	while (i < size)
	{
		values[i] = convert_input_to_int(inputs[i], &is_err);
		if (is_err)
			return (NULL);
		i++;
	}
	return (values);
}

static int	convert_input_to_int(const char *str, int *flag)
{
	long	num;
	int		is_neg;

	num = 0;
	is_neg = 0;
	if (*str == '-')
		is_neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (isoverflow_int(num, is_neg, *str - '0'))
		{
			*flag = 1;
			return (0);
		}
		num = num * 10 + (*str++ - '0');
	}
	if (*str)
		*flag = 1;
	if (is_neg)
		return (-num);
	return (num);
}

static int	isoverflow_int(long num, int is_neg, int c)
{
	long	cutoff;
	int		cutlim;

	if (is_neg)
	{
		cutoff = -(INT_MIN / 10);
		cutlim = -(INT_MIN % 10);
	}
	else
	{
		cutoff = INT_MAX / 10;
		cutlim = INT_MAX % 10;
	}
	if (num > cutoff || (num == cutoff && c > cutlim))
		return (1);
	return (0);
}
