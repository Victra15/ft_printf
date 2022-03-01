/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:38:07 by yolee             #+#    #+#             */
/*   Updated: 2022/02/26 03:01:40 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_char(va_list *ap, size_t *print_len)
{
	char	ch;

	ch = va_arg((*ap), int);
	write(1, &ch, 1);
	(*print_len) += 1;
}

void	parse_str(va_list *ap, size_t *print_len)
{
	char	*str;
	size_t	len;

	str = va_arg((*ap), char *);
	len = ft_strlen(str);
	write(1, str, len);
	(*print_len) += len;
}

void	parse_ptr(va_list *ap, size_t *print_len)
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

void	parse_decimal(va_list *ap, size_t *print_len)
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

void	parse_percent(size_t *print_len)
{
	write(1, "%", 1);
	(*print_len) += 1;
}
