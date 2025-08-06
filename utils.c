/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:56:45 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/06 16:55:11 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milsec)
{
	size_t	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < milsec)
	{
		usleep(100);
	}
	return (0);
}

void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	while (i < program->philos[0].num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	print_message(const char *message, t_philo *philo, int id)
{
	size_t	current_time;

	pthread_mutex_lock(philo->write_lock);
	current_time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
	{
		printf("%zu %d %s\n", current_time, id, message);
	}
	pthread_mutex_unlock(philo->write_lock);
}
