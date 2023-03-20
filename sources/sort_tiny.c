/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:46:51 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/19 04:52:21 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	quick_sort_tiny(t_lista *a, t_lista *b, int split_size)
{
	t_lista	bottom_b;
	t_ref	ref;

	ref = (t_ref){0};
	set_list(&bottom_b);
	set_utils_var(a, b, &ref, &split_size);
	while (checker(a, a->size + b->size))
	{
		while (check_crescent(a)
			|| a->size != (split_size * ref.id) + ref.adc_fix)
		{
			if (b->first && b->first->weight >= ((b->size)
					- (split_size * ref.id) + a->size))
				getmove(a, b, &bottom_b, &ref);
			else if (ref.maior_b_bottom == a->first->weight
				- 1 && ref.last_ok == 1)
				rotate_and_remove(b, &bottom_b, &ref);
		}
		update_ref(&ref, split_size);
		put_minor_on_top(a);
	}
	free_stack(bottom_b.first);
}

void	split_tiny(t_lista *a, t_lista *b, t_number *numbers)
{
	if (a->size / 2 > numbers->higher)
		while (a->last->weight != a->size)
			numbers->higher -= rotate_a(a);
	else
		while (a->last->weight != a->size)
			numbers->higher += reverse_ra(a);
	while (numbers->id <= (numbers->size - 1))
	{
		if (a->first->weight > numbers->size / 2
			&& a->last->weight == numbers->size)
			rotate_a(a);
		else if (a->last->weight != a->size
			&& a->first->weight > a->last->weight)
			rotate_a(a);
		else
			push_b(a, b);
		numbers->id++;
	}
}

void	split_and_conquer_tiny(t_lista *a, t_lista *b)
{
	t_number	numbers;

	numbers.id = 1;
	numbers.size = a->size;
	numbers.higher = check_pos(a, a->size);
	split_tiny(a, b, &numbers);
	quick_sort_tiny(a, b, numbers.size);
}

void	sort_three(t_lista *a)
{
	int	pos;

	pos = 0;
	pos = check_pos(a, a->maior);
	if (pos == 0)
		rotate_a(a);
	else if (pos == 1)
		reverse_ra(a);
	swap_a(a, 1);
}
