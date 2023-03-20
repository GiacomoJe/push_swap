/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_test.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jgiacomo <jefersongiacomo@gmail.com>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/17 14:42:08 by jgiacomo		  #+#	#+#			 */
/*   Updated: 2023/03/17 18:22:31 by jgiacomo		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <push_swap.h>

int	check_duplicate(t_lista *a)
{
	t_stack	*aux;
	int		i;
	int		*list;

	i = 0;
	list = (int *)calloc(a->size + 1, sizeof(int));
	aux = a->first;
	while (aux)
	{
		list[aux->weight]++;
		if (list[aux->weight] > 1)
		{
			free(list);
			return (1);
		}
		aux = aux->next;
	}
	free(list);
	return (0);
}

int	check_args(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	create_stack(t_lista *a, long *array_weight, int argc, const char **argv)
{
	int		id;
	long	number;

	id = 1;
	while (id < argc)
	{
		if (check_args(argv[id]))
		{
			number = ft_atoi(argv[id]);
			if (number > 2147483647 || number < -2147483648)
				return (error_out(a, array_weight));
			insert_end(a, number);
			array_weight[id - 1] = number;
			id++;
		}
		else
			return (error_out(a, array_weight));
	}
	return (0);
}

int	check_stack(t_lista *a, t_lista *b, long *array_weight)
{
	if (check_duplicate(a))
		return (error_out(a, array_weight));
	if (!(checker(a, a->size)))
		return (free_sucess(a, b, array_weight));
	if (a->size == 2)
		swap_a(a, 1);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 20)
		split_and_conquer_tiny(a, b);
	else
		split_and_conquer(a, b);
	return (free_sucess(a, b, array_weight));
}

int	main(int argc, const char **argv)
{
	t_lista	a;
	t_lista	b;
	long	*array_weight;

	set_list(&a);
	set_list(&b);
	array_weight = malloc(sizeof(long) * argc);
	if (argc == 1)
		return (free_sucess(&a, &b, array_weight));
	else if (create_stack(&a, array_weight, argc, argv))
		return (1);
	bubblesort(array_weight, argc - 1);
	set_weight(array_weight, &a);
	return (check_stack(&a, &b, array_weight));
}
