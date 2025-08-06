/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:22:37 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/06 16:55:04 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by juanandub on 31/7/25.
//
#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];

	if (argc < 5 || argc > 6 || check_args(argc, argv) == -1
		|| argc > MAX_PHILOS)
	{
		printf("ERROR: Invalid arguments\n");
		return (-1);
	}
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destroy_all(NULL, &program, forks);
	return (0);
}
