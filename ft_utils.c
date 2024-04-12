/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:27:58 by jalves-p          #+#    #+#             */
/*   Updated: 2024/01/18 13:09:34 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
    int	i;
    int	sign;
    int	result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    return (result * sign);
}

int	ft_strlen(char *str)
{
    int		i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	is_number(char **argv, int i, int j)
{
    while (argv[j])
    {
        while (argv[j][i])
        {
            if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
                return (0);
            i++;
        }
        i = 0;
        j++;
    }
    return (1);
}

int	get_time(void)
{
    struct timeval	tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * (int)1000) + (tv.tv_usec / 1000));
}
