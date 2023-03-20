/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:45:34 by jgiacomo          #+#    #+#             */
/*   Updated: 2022/08/08 18:45:52 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_formats(va_list args, int str)
{
	int	x;

	x = 0;
	if (str == 'd' || str == 'i')
		x = print_int(va_arg(args, int));
	else if (str == 's')
		x = print_str(va_arg(args, char *));
	else if (str == 'c')
		x = print_char(va_arg(args, int));
	else if (str == 'p')
		x = print_pointer(va_arg(args, unsigned long), str);
	else if (str == 'u')
		x = print_unsignint(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		x = print_hex(va_arg(args, unsigned long), str);
	else if (str == '%')
		x = print_percent();
	else
		x = 1 + print_percent();
	return (x);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	int				x;
	va_list			args;

	va_start(args, str);
	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			x = x + ft_formats(args, str[i + 1]);
			i = i + 2;
		}
		else
		{
			x = x + print_char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (x);
}
