/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:22:26 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/06 11:52:03 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by juanandub on 31/7/25.
//

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

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

// Init functions
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int num_philos);
void	init_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char *argv[]);
void	init_input(t_philo *philo, char *argv[]);

// Utility func and files
size_t	get_current_time(void);
int		ft_atoi(const char *nptr);

//check_args.c
int		check_args(int argc, char *argv[]);
int		is_number(char str[]);

// threads.c
int		thread_create(t_program *program, pthread_mutex_t *forks);
void	*philo_routine(void *philo_ptr);
int		dead_loop(t_philo *philo);

// actions.c
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);

void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks);
void	*monitor(void *philos);

#endif //PHILO_H
