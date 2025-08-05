/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:22:26 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/04 16:11:45 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by juanandub on 31/7/25.
//

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/types.h>
# include <pthread.h>
# include <stdio.h>

# define MAX_PHILOS 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal_time;
	size_t			start_time;
	int				num_philos;
	int				times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}	t_program;

int	ft_atoi(const char *nptr);
int	check_args(int argc, char *argv[]);
int	is_number(char str[]);

#endif //PHILO_H
