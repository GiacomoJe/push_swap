/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiacomo <jefersongiacomo@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 09:03:56 by jgiacomo          #+#    #+#             */
/*   Updated: 2022/10/15 14:51:50 by jgiacomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_bzero_printf(void *s, size_t n);
char	*ft_n_zero(void);
char	*ft_n_neg(int n);
char	*ft_n_pos(unsigned int n);
char	*ft_itoa_printf(int n);
int		print_str(char *str);
int		print_char(int str);
int		print_int(int x);
int		print_unsignint(unsigned int x);
int		hexalloc(unsigned long size);
char	print_pointer_str(int dec, char mod);
int		dectohex(unsigned long adress, char c);
int		print_pointer(unsigned long p, char c);
int		print_hex(unsigned int dec, char c);
int		print_percent(void);
int		ft_formats(va_list args, int str);
int		ft_printf(const char *str, ...);

#endif