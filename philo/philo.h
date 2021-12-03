/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskedduck <maskedduck@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:22:34 by eydupray          #+#    #+#             */
/*   Updated: 2021/12/03 23:47:54 by maskedduck       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct	s_glob
{
	int nphilo;
	int tdeath;
	int teat;
	int tsleep;
	int neat;
}               t_glob;

typedef struct	s_philo
{
	int state;
	int rfork;
	int lfork;
	int tdeath;
}				t_philo;

/*Utils*/
int		ft_atoi(const char *str);
void	exit_and_free();

#endif