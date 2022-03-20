/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:38:07 by yolee             #+#    #+#             */
/*   Updated: 2022/03/20 16:37:18 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	fill_with_blank(unsigned int idx, char *str)
{
	(*str) = ' ';
}

void	fill_with_zero(unsigned int idx, char *str)
{
	(*str) = '0';
}

void	parse_str(va_list *ap, size_t *print_len, t_pflag print_flags)
{
	char	*str;
	size_t	len;

	str = va_arg((*ap), char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*print_len) += 6;
	}
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
		(*print_len) += len;
	}
}

void	parse_ptr(va_list *ap, size_t *print_len, t_pflag print_flags)
{
	void	*ptr;
	char	*str;
	size_t	len;

	ptr = va_arg((*ap), void *);
	str = ft_ptoa((unsigned long long) ptr);
	len = ft_strlen(str);
	write(1, str, len);
	(*print_len) += len;
	free(str);
}

void	parse_decimal(va_list *ap, size_t *print_len, t_pflag print_flags)
{
	int		nbr;
	char	*str;
	size_t	len;

	nbr = va_arg((*ap), int);
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	write(1, str, len);
	(*print_len) += len;
	free(str);
}

void	parse_etc(char *iter, size_t *print_len, t_pflag print_flags)
{
	write(1, iter, 1);
	(*print_len) += 1;
}
