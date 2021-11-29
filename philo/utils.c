/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eydupray <eydupray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:46:21 by eydupray          #+#    #+#             */
/*   Updated: 2021/11/29 16:58:00 by eydupray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_and_free()
{
	write(2,"Error\n",6);
	exit(0);
}

int     ft_is_in(char c, char *s)
{
        int     i;

        i = 0;
        while (s[i])
        {
                if (s[i] == c)
                        return (1);
                i++;
        }
        return (0);
}

int	is_valid(char c, long int nb, long int neg)
{
		if ((ft_is_in(c, "-0123456789") == 0))
				return (0);
		if (neg == 1)
		{
				if (nb <= 214748364 && 2147483647 - nb * 10 >= c - '0')
						return (1);
		}
		else
				if (nb <= 214748364 && 2147483648 - nb * 10 >= c - '0')
						return (1);
		return (0);
}

int	ft_atoi(const char *str)
{
		int                     i;
		long int        res;
		long int        neg;

		i = 0;
		res = 0;
		neg = 1;
		if (!str)
			exit_and_free();
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
				|| str[i] == '\v' || str[i] == '\r' || str[i] == '\n')
				i++;
		if (str[i] == '-' || str[i] == '+')
				if (str[i++] == '-')
						neg = -1;
		while (str[i])
		{
				if (!is_valid(str[i], res, neg))
						exit_and_free();
				res = res * 10 + str[i] - '0';
				i++;
		}
		return (res * neg);
}