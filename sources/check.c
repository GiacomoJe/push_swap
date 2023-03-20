/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:12:58 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/19 03:16:00 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	checker(t_lista *a, int size)
{
	t_stack	*aux;

	aux = a->first;
	if (a->size != size)
		return (1);
	while (aux->next)
	{
		if (aux->number < aux->next->number)
			aux = aux->next;
		else
			return (1);
	}
	return (0);
}

int	check_crescent(t_lista *stack)
{
	int		i;
	t_stack	*aux;

	i = 1;
	aux = stack->first;
	if (stack->size == 0)
		return (1);
	while (aux && aux->weight != stack->menor)
		aux = aux->next;
	while (i < stack->size)
	{
		if (aux && aux->next)
		{
			if (aux->weight > aux->next->weight)
				return (1);
			aux = aux->next;
		}
		else if (aux && aux->weight < stack->first->weight)
			aux = stack->first;
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_pos(t_lista *a, int weight)
{
	t_stack	*aux;
	int		pos;

	pos = 0;
	aux = a->first;
	while (aux->weight < weight)
	{
		pos++;
		if (aux->next)
			aux = aux->next;
		else
			return (pos);
	}
	return (pos);
}

void	insert_end(t_lista *lista, int number)
{
	t_stack	*node;
	t_stack	*aux;

	aux = (t_stack *)malloc(sizeof(t_stack));
	aux->number = number;
	aux->next = NULL;
	node = lista->first;
	if (lista->first == NULL)
	{
		lista->first = aux;
		lista->maior = aux->number;
		lista->menor = aux->number;
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = aux;
	}
	lista->last = aux;
	lista->size++;
	if (lista->maior < aux->number)
		lista->maior = aux->number;
	if (lista->menor > aux->number)
		lista->menor = aux->number;
}

int	remove_end(t_lista *bottom, int maior)
{
	t_stack	*aux;

	aux = bottom->first;
	if (!(aux->next))
	{
		free(bottom->first);
		bottom->first = NULL;
		return (0);
	}
	while (aux->next->next)
		aux = aux->next;
	free(aux->next);
	aux->next = NULL;
	aux = bottom->first;
	maior = 0;
	while (aux)
	{
		if (aux->number > maior)
			maior = aux->number;
		aux = aux->next;
	}
	return (maior);
}
