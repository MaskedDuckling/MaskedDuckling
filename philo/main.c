/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskedduck <maskedduck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:20:54 by eydupray          #+#    #+#             */
/*   Updated: 2021/12/03 23:53:54 by maskedduck       ###   ########.fr       */
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

t_philo *ft_init_philo(t_glob *glob)
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
		philo[i].state = 0;
		philo[i].tdeath = glob->tdeath;
		i++;
	}
	return (philo);
}

int main(int ac, char **av)
{
	t_glob glob;
	t_philo *philo;

	philo = NULL;
	if (ac < 5 || ac > 6)
		return (0);
	ft_init(av, &glob);
	philo = ft_init_philo(&glob);
	int i = 0;
	while (i < glob.nphilo)
		printf("%d",philo[i++].state);
}