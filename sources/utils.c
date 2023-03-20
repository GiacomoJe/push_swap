/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:24:58 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/17 23:32:07 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	number;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == 43) || (str[i] == 45) || ft_isdigit(str[i]))
	{
		sign = 1;
		if (str[i] == 45)
			sign = -1;
		if ((str[i] == 45) || (str[i] == 43))
			i++;
		number = 0;
		while (str[i] && (ft_isdigit(str[i])))
		{
			number = number * 10 + (str[i] - 48);
			i++;
		}
		return ((number * sign));
	}
	return (0);
}

void	set_last(t_lista *stack)
{
	t_stack	*aux;

	aux = stack->first;
	while (aux->next)
	{
		aux = aux->next;
	}
	stack->last = aux;
	stack->ultimo = aux->weight;
}

void	set_minor(t_lista *list)
{
	t_stack	*aux;

	aux = list->first;
	if (aux)
	{
		list->menor = aux->weight;
		list->maior = aux->weight;
	}
	while (aux)
	{
		if (list->maior < aux->weight)
			list->maior = aux->weight;
		if (list->menor > aux->weight)
			list->menor = aux->weight;
		aux = aux->next;
	}
}
