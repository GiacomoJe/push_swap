/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:11:02 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/20 16:53:26 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <ft_printf.h>

typedef struct s_stack
{
	int				number;
	int				weight;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ref
{
	int	size;
	int	id;
	int	last_ok;
	int	maior_b_bottom;
	int	size_caps;
	int	adc;
	int	adc_fix;
}	t_ref;

typedef struct s_number
{
	int	weight;
	int	b_numbers;
	int	b_auth;
	int	id;
	int	groups;
	int	split_size;
	int	size;
	int	higher;
}	t_number;

typedef struct s_lista{
	t_stack	*first;
	t_stack	*last;
	int		maior;
	int		menor;
	int		primeiro;
	int		ultimo;
	int		size;
	int		total;
}	t_lista;

int		ft_isdigit(int c);
long	ft_atoi(const char *str);
void	set_list(t_lista *list);
void	set_last(t_lista *stack);

void	free_stack(t_stack *node);

void	swap_a(t_lista *a, int i);
void	swap_b(t_lista *b, int i);
void	swap_a_b(t_lista *a, t_lista *b);
void	push_b(t_lista *a, t_lista *b);
void	push_a(t_lista *a, t_lista *b);
void	rotate_b(t_lista *b);
int		rotate_a(t_lista *a);
void	rotate_rr(t_lista *a, t_lista *b);
void	reverse_rb(t_lista *b);
int		reverse_ra(t_lista *a);
void	reverse_rrr(t_lista *a, t_lista *b);

void	rotate_and_remove(t_lista *b, t_lista *bottom_b, t_ref *ref);
void	push_a_and_set_last(t_lista *a, t_lista *b, t_ref *ref);
void	push_and_rotate_a(t_lista *a, t_lista *b);
void	push_and_rotate_b(t_lista *a, t_lista *b, t_number *numbers);
void	push_a_twice(t_lista *a, t_lista *b);
void	insert_bottom_b_and_rotate(t_lista *b, t_lista *bottom_b, t_ref *ref);
void	pa_or_rb(t_lista *a, t_lista *b, t_lista *bottom_b, t_ref *ref);

void	insert_end(t_lista *lista, int number);
int		remove_end(t_lista *bottom, int maior);

void	set_minor(t_lista *list);

int		checker(t_lista *a, int size);
int		check_crescent(t_lista *stack);
int		check_pos(t_lista *a, int weight);

void	put_minor_on_top(t_lista *a);
void	swap(long *xp, long *yp);
void	bubblesort(long arr[], int n);
void	set_weight(long arr[], t_lista *a);

void	set_list(t_lista *list);
void	set_utils_var(t_lista *a, t_lista *b, t_ref *ref, int *split_size);
void	update_ref(t_ref *ref, int split_size);

void	getmove(t_lista *a, t_lista *b, t_lista *bottom_b, t_ref *ref);

void	quick_sort(t_lista *a, t_lista *b, int split_size);
void	quick_sort_tiny(t_lista *a, t_lista *b, int split_size);
void	split(t_lista *a, t_lista *b, t_number *numbers);
void	split_and_conquer(t_lista *a, t_lista *b);
void	split_tiny(t_lista *a, t_lista *b, t_number *numbers);
void	split_and_conquer_tiny(t_lista *a, t_lista *b);

void	sort_three(t_lista *a);
int		error_out(t_lista *a, long *array_weight);
int		check_duplicate(t_lista *a);
int		check_args(const char *str);
int		free_sucess(t_lista *a, t_lista *b, long *array_weight);
int		create_stack(t_lista *a, long *array_weight,
			int argc, const char **argv);
int		check_stack(t_lista *a, t_lista *b, long *array_weight);

#endif