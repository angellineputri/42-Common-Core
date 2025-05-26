/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sml_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:19:00 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 14:25:48 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sml(t_simulation *sml, int argc, char **argv)
{
	(*sml) = (t_simulation){0};
	sml->number_of_philos = validate_arg(argc, argv, 1);
	sml->time_to_die = validate_arg(argc, argv, 2);
	sml->time_to_eat = validate_arg(argc, argv, 3);
	sml->time_to_sleep = validate_arg(argc, argv, 4);
	sml->max_eat_amt = validate_arg(argc, argv, 5);
	sml->start_time = 0;
	if (validate_all(sml, argc) == 1)
		return (1);
	if (init_sem(sml) == 1)
		return (1);
	if (init_all_philos(sml) == 1)
		return (1);
	return (0);
}

int	validate_arg(int argc, char **argv, int i)
{
	long	num;
	int		j;

	j = 0;
	if (i >= argc)
		return (-1);
	while (argv[i][j])
	{
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (-1);
		j++;
	}
	num = ft_atoi(argv[i]);
	if (num <= 0 || num > INT_MAX)
		return (-1);
	else
		return ((int)num);
}

int	validate_all(t_simulation *sml, int argc)
{
	if (sml->number_of_philos == -1)
	{
		ft_putstr_fd("invalid number_of_philosophers\n", 2);
	}
	if (sml->time_to_die == -1)
	{
		ft_putstr_fd("invalid time_to_die\n", 2);
	}
	if (sml->time_to_eat == -1)
	{
		ft_putstr_fd("invalid time_to_eat\n", 2);
	}
	if (sml->time_to_sleep == -1)
	{
		ft_putstr_fd("invalid time_to_sleep\n", 2);
	}
	if (sml->max_eat_amt == -1 && argc == 6)
	{
		ft_putstr_fd("invalid number_of_times_each_philosopher_must_eat\n", 2);
	}
	if (sml->number_of_philos == -1 || sml->time_to_die == -1
		|| sml->time_to_eat == -1 || sml->time_to_sleep == -1
		|| (sml->max_eat_amt == -1 && argc == 6))
		return (1);
	return (0);
}

int	init_sem(t_simulation *sml)
{
	unlink_sem();
	sml->forks.sem = sem_open("/forks", O_CREAT, 0666, sml->number_of_philos);
	if (sml->forks.sem == (sem_t *) -1)
		return (ft_err_return("failed to initialize semaphore for fork"));
	sml->forks.init = 1;
	sml->data.sem = sem_open("/data", O_CREAT, 0666, 1);
	if (sml->data.sem == (sem_t *) -1)
		return (ft_err_return("failed to initialize semaphore for data"));
	sml->data.init = 1;
	sml->stop.sem = sem_open("/stop", O_CREAT, 0666, 0);
	if (sml->stop.sem == (sem_t *) -1)
		return (ft_err_return("failed to initialize semaphore for stop"));
	sml->stop.init = 1;
	sml->ready.sem = sem_open("/ready", O_CREAT, 0666, 0);
	if (sml->ready.sem == (sem_t *) -1)
		return (ft_err_return("failed to initialize semaphore for ready"));
	sml->ready.init = 1;
	sml->eat.sem = sem_open("/eat", O_CREAT, 0666, 0);
	if (sml->eat.sem == (sem_t *) -1)
		return (ft_err_return("failed to initialize semaphore for eat"));
	sml->eat.init = 1;
	return (0);
}

void	unlink_sem(void)
{
	sem_unlink("/forks");
	sem_unlink("/data");
	sem_unlink("/stop");
	sem_unlink("/ready");
	sem_unlink("/eat");
}
