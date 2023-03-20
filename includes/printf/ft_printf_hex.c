/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 05:10:21 by jgiacomo          #+#    #+#             */
/*   Updated: 2022/10/15 14:52:41 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexalloc(unsigned long size)
{
	int	i;

	i = 0;
	while (size >= 16)
	{
		i++;
		size = size / 16;
	}
	i++;
	return (i);
}

char	print_pointer_str(int dec, char mod)
{
	char	c;

	if (dec >= 10)
	{
		if (mod == 'X')
			c = dec - 33 + mod;
		else
			c = dec + 'W';
	}
	else
	{
		c = dec + '0';
	}
	return (c);
}

int	dectohex(unsigned long adress, char c)
{
	int		i;
	int		size;
	char	*hex;

	size = hexalloc(adress);
	i = size - 1;
	hex = (char *)malloc((size + 1) * sizeof(char));
	ft_bzero_printf(hex, size + 1);
	while (adress >= 16)
	{
		hex[i] = print_pointer_str(adress % 16, c);
		adress = adress / 16;
		i--;
	}
	hex[i] = print_pointer_str(adress % 16, c);
	while (hex[i])
	{
		print_char(hex[i]);
		i++;
	}
	free(hex);
	return (size);
}

int	print_pointer(unsigned long p, char c)
{
	int	hex;

	if (p == 0 || '\0')
	{
		print_str("(nil)");
		return (5);
	}
	print_str("0x");
	hex = dectohex(p, c);
	return (hex + 2);
}

int	print_hex(unsigned int dec, char c)
{
	int	hex;

	hex = dectohex(dec, c);
	return (hex);
}
