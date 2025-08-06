/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:23:13 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/06 16:55:16 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by juanandub on 31/7/25.
//
#include "philo.h"

int	is_number(char str[])
{
	int	i;

	if (!str || str[0] == '\0')
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	check_logic_arguments(char str[])
{
	int	i;
	int	j;

	if (!str || str[0] == '\0')
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		j = ft_atoi(str);
		if (j <= 0)
		{
			printf("ERROR: Argument %s is negative or zero\n", str);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) == -1)
			return (-1);
		if (check_logic_arguments(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
