/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_set_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:18:01 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/19 05:21:47 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(long *xp, long *yp)
{
	long	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubblesort(long arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	set_weight(long arr[], t_lista *a)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = a->first;
	while (aux)
	{
		while (arr[i] != aux->number)
			i++;
		aux->weight = i + 1;
		i = 0;
		aux = aux->next;
	}
	aux = NULL;
	free(aux);
}

void	set_list(t_lista *list)
{
	list->size = 0;
	list->first = NULL;
	list->size = 0;
	list->total = 0;
	list->maior = 0;
	list->menor = 0;
}

void	set_utils_var(t_lista *a, t_lista *b, t_ref *ref, int *split_size)
{
	ref->id = 1;
	ref->size = b->size;
	b->menor = b->size - *split_size;
	b->maior = b->size;
	if (b->first->weight == b->maior
		|| b->first->next->weight == b->maior || b->size <= 20)
		ref->last_ok = 1;
	if (b->size > 20)
		push_a_twice(a, b);
	if (ref->last_ok == 0 && a->first->weight > a->first->next->weight)
		rotate_a(a);
	else if (ref->last_ok == 1 && a->first->weight < a->first->next->weight)
		rotate_a(a);
	if (b->size % 2 == 1)
	{
		ref->adc = 1;
		ref->adc_fix = 1;
		if (b->size <= 20)
		{
			ref->size = *split_size;
			*split_size = *split_size - 1;
		}
	}
	ref->size_caps = ((b->size) - (*split_size * ref->id) + a->size) - ref->adc;
}
