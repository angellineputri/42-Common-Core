/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:11:00 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:59:32 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647

typedef struct s_simulation
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat_amt;
	int				all_ate;
	int				a_philo_died;
	long			start_time;
	int				*forks;

	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	stop;
	int				stop_mutex_init;

	struct s_philo	*philos;
	pthread_t		*threads;
}				t_simulation;

typedef struct s_philo
{
	int				number;
	int				eat_amt;
	long			last_ate;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	data;
	t_simulation	*sml;
}				t_philo;

// init_sml.c
int		init_sml(t_simulation *sml, int argc, char **argv);
int		validate_arg(int argc, char **argv, int i);
int		validate_all(t_simulation *sml, int argc);
int		init_forks(t_simulation *sml);
int		init_mutex(t_simulation *sml);

// init_philos.c
int		init_all_philos(t_simulation *sml);
void	init_philo(t_simulation *sml, t_philo *new_philo, int i);

// simulation.c
int		start_simulation(t_simulation *sml);
void	check_death(t_simulation *sml, int i);

// philo_life.c
void	*philo_life(void *arg);
void	one_philo(t_philo *philo, t_simulation *sml);
void	philo_routine(t_philo *philo, t_simulation *sml);
void	philo_eats(t_philo *philo, t_simulation *sml);
void	can_philo_eat(t_philo *philo, t_simulation *sml);

// exit.c
void	free_sml(t_simulation *sml);

// philo_utils.c
void	msleep(t_simulation *sml, int time);
void	print_action(t_philo *philo, t_simulation *sml, char *action);
long	timestamp(void);
void	take_fork(t_simulation *sml, int fork);
void	release_fork(t_simulation *sml, int fork);

// philo_libft.c
void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(const char *nptr);
int		ft_err_return(char *msg);
int		ft_strcmp(char *s1, char *s2);
void	destroy_mutex_arr(pthread_mutex_t **arr, int size);

#endif
