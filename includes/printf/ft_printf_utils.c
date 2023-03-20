/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 05:08:07 by jgiacomo          #+#    #+#             */
/*   Updated: 2022/10/15 14:51:40 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero_printf(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = '\0';
		n--;
	}
}

char	*ft_n_zero(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_n_neg(int n)
{
	char			*str;
	long			spot;
	int				decomp;
	unsigned int	x;

	x = n * -1;
	decomp = x;
	spot = 0;
	while (decomp)
	{
		decomp /= 10;
		spot++;
	}
	str = (char *)malloc((spot + 2) * sizeof(char));
	if (!str)
		return (0);
	str[spot + 1] = '\0';
	while (x)
	{
		str[spot] = x % 10 + '0';
		x /= 10;
		spot--;
	}
	str[spot] = '-';
	return (str);
}

char	*ft_n_pos(unsigned int n)
{
	char			*str;
	long			spot;
	unsigned int	decomp;

	if (n == 0)
		return (ft_n_zero());
	decomp = n;
	spot = 0;
	while (decomp)
	{
		decomp /= 10;
		spot++;
	}
	str = (char *)malloc((spot + 1) * sizeof(char));
	if (!str)
		return (0);
	str[spot] = '\0';
	while (n)
	{
		str[spot - 1] = n % 10 + '0';
		n /= 10;
		spot--;
	}
	return (str);
}

char	*ft_itoa_printf(int n)
{
	if (n == 0)
		return (ft_n_zero());
	else if (n > 0)
		return (ft_n_pos(n));
	else
		return (ft_n_neg(n));
}
