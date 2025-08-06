/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:15:14 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/06 11:44:44 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	oberserver_thread;
	int			i;

	if (pthread_create(&oberserver_thread, NULL,
			&monitor, program->philos) != 0)
		destroy_all("thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].num_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			destroy_all("thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(oberserver_thread, NULL) != 0)
		destroy_all("thread join error", program, forks);
	while (i < program->philos[0].num_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("thread join error", program, forks);
		i++;
	}
	return (0);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (philo_ptr);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
