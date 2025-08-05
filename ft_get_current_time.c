/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanandub <juanandub@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:47:14 by juanandub         #+#    #+#             */
/*   Updated: 2025/08/05 19:03:15 by juanandub        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		printf("ERROR: Failed to get current time\n");
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
