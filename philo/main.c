/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskedduck <maskedduck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:20:54 by eydupray          #+#    #+#             */
/*   Updated: 2021/12/07 23:51:02 by maskedduck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(char **av, t_glob *glob)
{
	glob->nphilo = ft_atoi(av[1]);
	glob->tdeath = ft_atoi(av[2]);
	glob->teat = ft_atoi(av[3]);
	glob->tsleep = ft_atoi(av[4]);
	if (av[5])
		glob->neat = ft_atoi(av[5]);
	else
		glob->neat = 0;
}

void	mutex_init(t_glob *glob)
{
	int i;

	i = 0;
	glob->forks = malloc(sizeof(pthread_mutex_t) * glob->nphilo);
	while (i < glob->nphilo)
	{
		pthread_mutex_init(&glob->forks[i], 0);
	}
}

void	ft_init_philo(t_glob *glob)
{
	t_philo *philo;
	int i;

	i = 0;
	philo = NULL;
	philo = malloc(sizeof(t_philo) * glob->nphilo);
	if (!philo)
		exit_and_free();
	while (i < glob->nphilo)
	{
		philo[i].position = i;
		philo[i].tdeath = glob->tdeath;
		philo[i].rfork = &(glob->forks[i]);
		philo[i].lfork = &(glob->forks[(i + 1) % glob->nphilo]);
		philo[i].glob = glob;
		i++;
	}
	glob->philo = philo;
}

__uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((__uint64_t)time.tv_sec * 1000 + ((__uint64_t)time.tv_usec) / 1000);
}

void	start_routine(t_philo *philo)
{
	__uint64_t lmeal;
	
	lmeal = get_time();
	while (1)
	{
		if ()
		pthread_mutex_lock(philo->lfork);
		pthread_mutex_lock(philo->rfork);
		if (philo->tdeath > get_time() - lmeal)
			break;
		lmeal = get_time();
		usleep(philo->glob->teat * 1000);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		usleep(philo->glob->tsleep * 1000);
	}
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);

}

void	start_thread(t_glob *glob)
{
	int i;
	pthread_t tid;

	i = 0;
	while (i < glob->nphilo)
	{
		pthread_create(tid, 0, start_routine, &glob->philo);
	}
}

int main(int ac, char **av)
{
	t_glob glob;
	t_philo *philo;

	philo = NULL;
	if (ac < 5 || ac > 6)
		return (0);
	ft_init(av, &glob);
	mutex_init(&glob);
	ft_init_philo(&glob);
}