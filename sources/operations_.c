/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:35:09 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/20 16:46:21 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_b(t_lista *b)
{
	t_stack	*aux;
	t_stack	*node;

	if (!(b->first) || !(b->first->next))
		return ;
	aux = b->first;
	node = b->first;
	b->first = b->first->next;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	node->next = NULL;
	ft_printf("rb\n");
	set_last(b);
}

int	rotate_a(t_lista *a)
{
	t_stack	*aux;
	t_stack	*node;

	if (!(a->first) || !(a->first->next))
		return (0);
	aux = a->first;
	node = a->first;
	a->first = a->first->next;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	node->next = NULL;
	set_last(a);
	ft_printf("ra\n");
	return (1);
}

void	rotate_rr(t_lista *a, t_lista *b)
{
	rotate_a(a);
	rotate_b(b);
	ft_printf("rr\n");
}

void	reverse_rb(t_lista *b)
{
	t_stack	*node;
	t_stack	*aux;
	t_stack	*ant;

	if (!(b->first) || !(b->first->next))
		return ;
	aux = b->first;
	while (aux->next)
	{
		ant = aux;
		aux = aux->next;
	}
	node = aux;
	ant->next = NULL;
	node->next = b->first;
	b->first = node;
	set_last(b);
	ft_printf("rrb\n");
}

int	reverse_ra(t_lista *a)
{
	t_stack	*node;
	t_stack	*aux;
	t_stack	*ant;

	if (!(a->first) || !(a->first->next))
		return (0);
	aux = a->first;
	while (aux->next)
	{
		ant = aux;
		aux = aux->next;
	}
	node = aux;
	ant->next = NULL;
	node->next = a->first;
	a->first = node;
	a->primeiro = node->number;
	a->ultimo = ant->number;
	set_last(a);
	ft_printf("rra\n");
	return (1);
}
