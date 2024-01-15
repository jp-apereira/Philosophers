/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:23:37 by jalves-p          #+#    #+#             */
/*   Updated: 2024/01/15 17:34:11 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    thinking(t_philo *philo)
{
    print_message("is thinking", philo, philo->id);
}

void    sleeping(t_philo *philo)
{
    print_message("is sleeping", philo, philo->id);
    ft_usleep(philo->time_to_sleep)
}