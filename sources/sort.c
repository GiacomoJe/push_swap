/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:45:06 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/19 04:46:32 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	quick_sort(t_lista *a, t_lista *b, int split_size)
{
	t_lista	bottom_b;
	t_ref	ref;

	ref = (t_ref){0};
	set_list(&bottom_b);
	set_utils_var(a, b, &ref, &split_size);
	while (checker(a, ref.size))
	{
		while (check_crescent(a)
			|| a->size != (split_size * ref.id) + ref.adc_fix)
		{
			if (b->first->weight >= ((b->size)
					- (split_size * ref.id) + a->size))
				getmove(a, b, &bottom_b, &ref);
			else if (ref.maior_b_bottom == a->first->weight
				- 1 && ref.last_ok == 1)
				rotate_and_remove(b, &bottom_b, &ref);
		}
		update_ref(&ref, split_size);
	}
	free_stack(bottom_b.first);
}

void	split(t_lista *a, t_lista *b, t_number *numbers)
{
	numbers->higher = numbers->weight + numbers->split_size;
	while (numbers->b_numbers < (numbers->higher) && a->first)
	{
		if (a->first->weight <= numbers->weight)
		{
			push_b(a, b);
			numbers->b_numbers++;
		}
		else if (a->first->weight > numbers->weight
			&& a->first->weight <= numbers->higher)
		{
			push_and_rotate_b(a, b, numbers);
		}
		else
			rotate_a(a);
	}
	if (numbers->b_auth == 1)
		while (numbers->b_auth++ <= numbers->split_size)
			reverse_rb(b);
	numbers->groups -= 2;
	numbers->b_auth = 0;
	if (numbers->groups == 1)
		while (numbers->b_auth++ <= numbers->split_size + numbers->groups)
			push_b(a, b);
	numbers->weight += 2 * numbers->split_size;
}

void	split_and_conquer(t_lista *a, t_lista *b)
{
	t_number	numbers;

	numbers.id = 1;
	numbers.b_numbers = 0;
	numbers.groups = 0;
	numbers.b_auth = 0;
	if (a->size % 2 == 1)
		numbers.size = a->size - 1;
	else
		numbers.size = a->size;
	while (numbers.size / numbers.id > 20 || numbers.size % numbers.id != 0)
		numbers.id++;
	numbers.split_size = numbers.size / numbers.id;
	numbers.groups = numbers.size / numbers.split_size;
	numbers.weight = numbers.split_size;
	while (a->size > 0)
		split(a, b, &numbers);
	quick_sort(a, b, numbers.split_size);
}
