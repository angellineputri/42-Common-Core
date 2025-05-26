/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sml.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:01:46 by aputri-a          #+#    #+#             */
/*   Updated: 2025/01/18 17:56:29 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (init_forks(sml) == 1)
		return (1);
	if (init_mutex(sml) == 1)
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

int	init_forks(t_simulation *sml)
{
	int	*forks;
	int	i;

	forks = malloc(sizeof(int) * sml->number_of_philos);
	if (!forks)
		return (ft_err_return("malloc failed"));
	i = 0;
	while (i < sml->number_of_philos)
	{
		forks[i] = 1;
		i++;
	}
	sml->forks = forks;
	return (0);
}

int	init_mutex(t_simulation *sml)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * sml->number_of_philos);
	if (!forks)
		return (ft_err_return("malloc failed"));
	i = 0;
	while (i < sml->number_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (destroy_mutex_arr(&forks, i),
				ft_err_return("failed to initialize mutex for fork"));
		i++;
	}
	sml->forks_mutex = forks;
	if (pthread_mutex_init(&stop, NULL) != 0)
		return (ft_err_return("failed to initialize mutex for stop"));
	sml->stop = stop;
	return (0);
}
