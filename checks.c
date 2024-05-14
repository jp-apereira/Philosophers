/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:09:08 by jalves-p          #+#    #+#             */
/*   Updated: 2024/05/10 13:36:57 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong amount of arguments\n");
		printf("Arguments:\n\t./philo\n\tnumber_of_philosophers\n\t");
		printf("time_to_die\n\ttime_to_eat\n\ttime_to_sleep\n\t");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}

int	check_av(int ac, char **av, t_data *philo)
{
	if ((ac == 5 || ac == 6) && is_number(av, 0, 1))
	{
		philo->number_of_philos = ft_atoi(av[1]);
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
		philo->number_of_meals = -1;
		if (ac == 6)
			philo->number_of_meals = ft_atoi(av[5]);
		if (philo->number_of_philos <= 0 || philo->time_to_sleep <= 0
			|| philo->time_to_die <= 0 || philo->time_to_eat <= 0
			|| (ac == 6 && philo->number_of_meals <= 0))
			return (0);
		return (1);
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (get_time() >= philo->time_to_die)
	{
		if (philo->data->dead == 0)
		{
			philo->data->dead = 1;
			pthread_mutex_lock(&philo->data->write);
			printf("%dms philo %d died\n", get_time() - philo->data->init_time,
				philo->id);
			pthread_mutex_unlock(&philo->data->write);
		}
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}

int	special_case(t_philo *philo)
{
	if (philo == NULL || philo->data == NULL
		|| philo->data->number_of_meals == 0
		|| philo->data->number_of_philos == 1)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%dms philo %d is thinking\n",
			get_time() - philo->data->init_time, philo->id);
		pthread_mutex_unlock(&philo->data->write);
		usleep(philo->data->time_to_die * 1000);
		pthread_mutex_lock(&philo->data->write);
		printf("%dms philo %d is dead\n",
			get_time() - philo->data->init_time, philo->id);
		pthread_mutex_unlock(&philo->data->write);
		return (1);
	}
	return (0);
}

int	are_forks_available(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->r_fork->mutex);
		if (!philo->r_fork->available)
		{
			pthread_mutex_unlock(&philo->r_fork->mutex);
			return (0);
		}
		pthread_mutex_lock(&philo->l_fork->mutex);
		if (!philo->l_fork->available)
		{
			pthread_mutex_unlock(&philo->r_fork->mutex);
			pthread_mutex_unlock(&philo->l_fork->mutex);
			return (0);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork->mutex);
		if (!philo->l_fork->available)
		{
			pthread_mutex_unlock(&philo->l_fork->mutex);
			return (0);
		}
		pthread_mutex_lock(&philo->r_fork->mutex);
		if (!philo->r_fork->available)
		{
			pthread_mutex_unlock(&philo->l_fork->mutex);
			pthread_mutex_unlock(&philo->r_fork->mutex);
			return (0);
		}
	}
	return (1);
}
