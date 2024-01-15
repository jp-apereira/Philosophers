/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:09:08 by jalves-p          #+#    #+#             */
/*   Updated: 2024/01/15 17:14:04 by jalves-p         ###   ########.fr       */
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