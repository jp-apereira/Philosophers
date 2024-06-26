/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:15:14 by joaopereira       #+#    #+#             */
/*   Updated: 2024/05/10 13:15:17 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks_and_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_mutex_init(&data->philos[i].state, NULL);
		data->forks[i].available = 1;
		pthread_mutex_init(&data->forks[i].mutex, NULL);
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].meals_count = 0;
		data->philos[i].l_fork = &data->forks[i];
		if (i == 0)
			data->philos[i].r_fork = &data->forks[data->number_of_philos - 1];
		else
			data->philos[i].r_fork = &data->forks[i - 1];
	}
}

int	initialize(int ac, char **av, t_data *data)
{
	if ((ac == 5 || ac == 6))
	{
		data->number_of_philos = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
	}
	if (av[5] && is_number(av, 0, 1))
		data->number_of_meals = ft_atoi(av[5]);
	else
		data->number_of_meals = -1;
	data->dead = 0;
	data->finished = 0;
	data->thread_id = malloc(sizeof(pthread_t) * data->number_of_philos);
	data->forks = malloc(sizeof(t_s) * data->number_of_philos);
	data->philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!data->philos || !data->forks || !data->thread_id)
		return (1);
	set_forks_and_philos(data);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	return (0);
}
