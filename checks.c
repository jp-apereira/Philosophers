/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:09:08 by jalves-p          #+#    #+#             */
/*   Updated: 2024/01/18 13:09:32 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check(int ac)
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


int	check_av(char **av)
{
    int	number_of_philos;
    int	time_to_die;
    int	time_to_eat;
    int	time_to_sleep;
    int	number_of_times_each_philosopher_must_eat;

    number_of_philos = ft_atoi(av[1]);
    time_to_die = ft_atoi(av[2]);
    time_to_eat = ft_atoi(av[3]);
    time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        number_of_times_each_philosopher_must_eat = 0;
    if (number_of_philos < 1 || number_of_philos > 200 || time_to_die < 0
        || time_to_eat < 0 || time_to_sleep < 0
        || number_of_times_each_philosopher_must_eat < 0)
    {
        printf("Error: Invalid arguments\n");
        return (0);
    }
    return (1);
}

int	is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->lock);
    if ((int)get_time() >= philo->time_to_die)
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
    pthread_mutex_unlock(&philo->data->lock);
    return (0);
}

int	special_case(t_philo *philo)
{
    if (philo == NULL || philo->data == NULL || philo->data->number_of_meals == 0 || philo->data->number_of_philos == 1)
    {
        pthread_mutex_lock(&philo->data->write);
        printf("%dms philo %d is thinking\n", get_time() - philo->data->init_time, philo->id);
        pthread_mutex_unlock(&philo->data->write);
        is_dead(philo);
        return 1;
    }
    return 0;
}

int are_forks_available(t_philo *philo)
{
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

    if (philo->id % 2 == 0)
    {
      first_fork = &philo->r_fork->mutex;
      second_fork = &philo->l_fork->mutex;
    }
    else
    {
      first_fork = &philo->l_fork->mutex;
      second_fork = &philo->r_fork->mutex;
    }
    pthread_mutex_lock(first_fork);
    if (!philo->r_fork->available)
    {
      pthread_mutex_unlock(first_fork);
      return 0;
    }
    pthread_mutex_lock(second_fork);
    if (!philo->l_fork->available)
    {
      pthread_mutex_unlock(first_fork);
      pthread_mutex_unlock(second_fork);
      return 0;
    }
    return 1;
}