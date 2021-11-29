/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eydupray <eydupray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:20:54 by eydupray          #+#    #+#             */
/*   Updated: 2021/11/29 17:40:25 by eydupray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	ft_init(char **av)
{
	t_state state;

	state.nphilo = ft_atoi(av[1]);
	state.tdeath = ft_atoi(av[2]);
	state.teat = ft_atoi(av[3]);
	state.tsleep = ft_atoi(av[4]);
	if (av[5])
		state.neat = ft_atoi(av[5]);
	else
		state.neat = 0;
	return (state);
}

t_philo *ft_init_philo(t_state state)
{
	t_philo *philo;
	int i;

	i = 0;
	philo = NULL;
	philo = malloc(sizeof(t_philo) * state.nphilo);
	if (!philo)
		exit_and_free();
	while (i < state.nphilo)
	{
		philo[i].state = 0;
		philo[i].rfork = 1;
		philo[i].lfork = -1;
		philo[i].tdeath = state.tdeath;
		i++;
	}
	return (philo);
}

int main(int ac, char **av)
{
	t_state state;
	t_philo *philo;

	philo = NULL;
	if (ac < 5 || ac > 6)
		return (0);
	state = ft_init(av);
	philo = ft_init_philo(state);
	int i = 0;
	while (i < state.nphilo)
		printf("%d",philo[i++].state);
}