/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:33:10 by jalves-p          #+#    #+#             */
/*   Updated: 2024/01/18 13:09:36 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
struct s_data;

typedef struct s_s
{
	int				available;
	pthread_mutex_t	mutex;
} t_s;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_count;
	int				time_to_die;
	pthread_mutex_t	state;
	t_s         	*r_fork;
	t_s     		*l_fork;
	struct s_data	*data;
} t_philo;

typedef struct s_data
{
    pthread_t		*thread_id;
    int				init_time;
    int				dead;
    int				finished;
    t_philo			*philos;
    int				number_of_philos;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				number_of_meals;
    t_s     		*forks;
    pthread_mutex_t	lock;
    pthread_mutex_t	write;
} t_data;

int check(int ac);
int	check_av(char **av);
int	is_dead(t_philo *philo);
int	special_case(t_philo *philo);
int are_forks_available(t_philo *philo);
void *monitor(void *arg);

void	grab_forks(t_philo *philo);
int	exec_routine(t_philo *philo);


void	set_forks_and_philos(t_data *data);
int	initialize(int ac, char **av, t_data *data);

void	*routine(void *thread_pointer);
void	end_simulation(t_data *data);
void	start_simulation(t_data *data);
int	main(int ac, char **av);


int	get_time(void);
int	ft_atoi(char *str);
int	is_number(char **argv, int i, int j);


#endif