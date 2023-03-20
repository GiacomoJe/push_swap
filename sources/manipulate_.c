/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:41:59 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/19 04:51:23 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	insert_bottom_b_and_rotate(t_lista *b, t_lista *bottom_b, t_ref *ref)
{
	if (ref->maior_b_bottom < b->first->weight)
		ref->maior_b_bottom = b->first->weight;
	insert_end(bottom_b, b->first->weight);
	rotate_b(b);
}

void	pa_or_rb(t_lista *a, t_lista *b, t_lista *bottom_b, t_ref *ref)
{
	if ((a->ultimo == a->maior && ref->last_ok == 1)
		|| (b->first->weight > a->ultimo
			&& b->first->weight > ref->size_caps - ref->adc))
		push_and_rotate_a(a, b);
	else if (b->first->weight > ref->size_caps - ref->adc)
		insert_bottom_b_and_rotate(b, bottom_b, ref);
}

void	update_ref(t_ref *ref, int split_size)
{
	ref->size_caps -= split_size;
	ref->adc = 0;
	ref->id++;
	ref->maior_b_bottom = 0;
}

void	push_and_rotate_b(t_lista *a, t_lista *b, t_number *numbers)
{
	push_b(a, b);
	rotate_b(b);
	numbers->b_numbers++;
	numbers->b_auth = 1;
}

void	getmove(t_lista *a, t_lista *b, t_lista *bottom_b, t_ref *ref)
{
	if (ref->maior_b_bottom == a->first->weight - 1 && ref->last_ok == 1)
		rotate_and_remove(b, bottom_b, ref);
	if (b->first && a->first->weight - 1 == b->first->weight
		&& ref->last_ok == 1)
		push_a(a, b);
	else if (b->first && b->first->weight == b->maior
		&& ref->last_ok == 0 && b->first->weight > ref->size_caps)
		push_a_and_set_last(a, b, ref);
	else if (b->first && b->first->weight < a->first->weight
		&& b->first->weight > ref->size_caps - ref->adc)
		pa_or_rb(a, b, bottom_b, ref);
	else if (b->first && b->first->weight > a->maior && ref->last_ok == 0)
		push_and_rotate_a(a, b);
	else if (b->first && b->first->weight > a->first->weight
		&& b->first->weight < a->ultimo && ref->last_ok == 0)
		pa_or_rb(a, b, bottom_b, ref);
	while (a->ultimo == a->first->weight - 1 && ref->last_ok == 1)
		reverse_ra(a);
}
