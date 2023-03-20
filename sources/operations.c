/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:31:33 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/20 16:46:25 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(t_lista *a, int i)
{
	t_stack	*aux;

	if (!(a->first && a->first->next))
		return ;
	aux = (t_stack *)malloc(sizeof(t_stack));
	aux->number = a->first->number;
	aux->weight = a->first->weight;
	a->first->number = a->first->next->number;
	a->first->weight = a->first->next->weight;
	a->first->next->number = aux->number;
	a->first->next->weight = aux->weight;
	free(aux);
	if (i == 1)
		ft_printf("sa\n");
}

void	swap_b(t_lista *b, int i)
{
	t_stack	*aux;

	if (!(b->first && b->first->next))
		return ;
	aux = (t_stack *)malloc(sizeof(t_stack));
	aux->number = b->first->number;
	aux->weight = b->first->weight;
	b->first->number = b->first->next->number;
	b->first->weight = b->first->next->weight;
	b->first->next->number = aux->number;
	b->first->next->weight = aux->weight;
	free(aux);
	if (i == 1)
		ft_printf("sb\n");
}

void	swap_a_b(t_lista *a, t_lista *b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	ft_printf("ss\n");
}

void	push_b(t_lista *a, t_lista *b)
{
	t_stack	*aux;

	if (!(a->first))
		return ;
	aux = a->first;
	if (a->first->next)
		a->first = a->first->next;
	else
		a->first = NULL;
	aux->next = b->first;
	b->first = aux;
	a->size--;
	b->size++;
	set_minor(a);
	set_minor(b);
	set_last(b);
	ft_printf("pb\n");
}

void	push_a(t_lista *a, t_lista *b)
{
	t_stack	*aux;

	if (!(b->first))
		return ;
	aux = b->first;
	if (b->first->next)
		b->first = b->first->next;
	else
		b->first = NULL;
	aux->next = a->first;
	a->first = aux;
	b->size--;
	a->size++;
	set_minor(b);
	set_minor(a);
	set_last(a);
	ft_printf("pa\n");
}
