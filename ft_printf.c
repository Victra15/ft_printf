/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/02/18 16:00:29 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format_str(va_list ap, char **iter)
{
	if ((*iter) == 'c')
		parse_char(ap);
	else if ((*iter) == 's')
		parse_str(ap);
	else if ((*iter) == 'p')
		parse_ptr(ap);
	else if ((*iter) == 'd')
		parse_decimal(ap);
	else if ((*iter) == 'i')
		parse_integer(ap);
	else if ((*iter) == 'u')
		parse_unsigned_decimal(ap);
	else if ((*iter) == 'x')
		parse_lower_hexadecimal(ap);
	else if ((*iter) == 'X')
		parse_upper_hexadecimal(ap);
	else if ((*iter) == '%')
		write(1, "%", 1);
	else
		return ;
	(*iter)++;
}

void	print_parsed_str(va_list ap, const char *str)
{
	char	*iter;

	iter = str;
	while (1)
	{
		iter = ft_strchr(iter, '%');
		if (!iter)
			break ;
		iter++;
		print_format_str(ap, &iter);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	print_str_len;
	char	*print_str;

	va_start(ap, str);
	print_parsed_str(ap, str);
	va_end(ap);
	return (0);
}
