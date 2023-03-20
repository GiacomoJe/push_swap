/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:16:28 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/19 04:41:30 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	put_minor_on_top(t_lista *a)
{
	while (a->first->weight != a->menor)
		reverse_ra(a);
}

void	push_a_twice(t_lista *a, t_lista *b)
{
	push_a(a, b);
	push_a(a, b);
}

void	rotate_and_remove(t_lista *b, t_lista *bottom_b, t_ref *ref)
{
	while (b->first->weight != ref->maior_b_bottom)
	{
		reverse_rb(b);
		bottom_b->maior = remove_end(bottom_b, ref->maior_b_bottom);
	}
	ref->maior_b_bottom = bottom_b->maior;
}

void	push_a_and_set_last(t_lista *a, t_lista *b, t_ref *ref)
{
	push_a(a, b);
	ref->last_ok = 1;
}

void	push_and_rotate_a(t_lista *a, t_lista *b)
{
	push_a(a, b);
	rotate_a(a);
}
