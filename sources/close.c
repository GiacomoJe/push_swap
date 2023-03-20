/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:52:36 by jgiacomo          #+#    #+#             */
/*   Updated: 2023/03/20 16:46:08 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stack(t_stack *node)
{
	if (node == NULL)
		return ;
	free_stack(node->next);
	free(node);
}

int	error_out(t_lista *a, long *array_weight)
{
	free_stack(a->first);
	free(array_weight);
	ft_printf("Error\n");
	return (1);
}

int	free_sucess(t_lista *a, t_lista *b, long *array_weight)
{
	free_stack(a->first);
	free_stack(b->first);
	free(array_weight);
	return (0);
}
