/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:03:44 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/04 16:11:44 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program->philos = philos;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
}

void    init_forks(pthread_mutex_t *forks, int num_philos)
{
    int i;

    i = 0;
    while (i < num_philos)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}
void    init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
                    char *argv[])
{
    int i;

    i = 0;
    while (i < ft_atoi(argv[1]))
    {
        philos[i].id = i;
        philos[i].eating = 0;
        philos[i].left_fork = &forks[i];
        philos[i].right_fork = &forks[(i + 1) % num_philos];
        i++;
    }
    