/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:38:07 by yolee             #+#    #+#             */
/*   Updated: 2022/02/25 19:56:04 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_char(va_list ap)
{
	char	ch;

	ch = va_arg(ap, int);
	write(1, &ch, 1);
}

void	parse_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	write(1, str, ft_strlen(str));
}

void	parse_ptr(va_list ap)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(ap, void *);
	str = ft_ptoa((unsigned long long) ptr);
	write(1, str, ft_strlen(str));
	free(str);
}

void	parse_decimal(va_list ap)
{
	int		nbr;
	char	*str;

	nbr = va_arg(ap, int);
	str = ft_itoa(nbr);
	write(1, str, ft_strlen(str));
	free(str);
}
