/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:19:10 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 14:29:50 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdatomic.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

# define INT_MAX 2147483647

typedef struct s_sem
{
	sem_t	*sem;
	int		init;
}				t_sem;

typedef struct s_simulation
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat_amt;
	int				a_philo_died;
	long			start_time;
	pthread_t		track_eat;

	t_sem			forks;
	t_sem			data;
	t_sem			stop;
	t_sem			ready;
	t_sem			eat;

	struct s_philo	*philos;
}				t_simulation;

typedef struct s_philo
{
	int				number;
	int				eat_amt;
	long			last_ate;
	pid_t			pid;
	pthread_t		check_death;
	t_simulation	*sml;
}				t_philo;

// from philo_libft.c
void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(const char *nptr);
int		ft_err_return(char *msg);
int		ft_strcmp(char *s1, char *s2);

// from init_sml.c
int		init_sml(t_simulation *sml, int argc, char **argv);
int		validate_arg(int argc, char **argv, int i);
int		validate_all(t_simulation *sml, int argc);
int		init_sem(t_simulation *sml);
void	unlink_sem(void);

// from init_philo.c
int		init_all_philos(t_simulation *sml);	
void	init_philo(t_simulation *sml, t_philo *new_philo, int i);

// from simulation.c
int		start_simulation(t_simulation *sml);
void	end_simulation(t_simulation *sml);
void	*track_eat(void *arg);

// from philo_life.c
int		philo_life(t_philo *philo);
int		one_philo(t_philo *philo, t_simulation *sml);
void	philo_routine(t_philo *philo, t_simulation *sml);
void	philo_eats(t_philo *philo, t_simulation *sml);
void	*check_death(void *arg);

// from philo_utils.c
void	msleep(int time);
void	can_philo_eat(t_philo *philo, t_simulation *sml);
void	print_action(t_philo *philo, t_simulation *sml, char *action);
long	timestamp(void);

// from exit.c
void	free_pids(t_simulation *sml);
void	free_sml(t_simulation *sml);
void	clean_sem(t_simulation *sml);

#endif
