/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/03/24 15:24:31 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format_str(va_list *ap, const char **iter, int *print_len)
{
	char	format_char;

	format_char = (**iter);
	if (format_char == 'c')
		parse_char(ap, print_len);
	else if (format_char == 's')
		parse_str(ap, print_len);
	else if (format_char == 'p')
		parse_ptr(ap, print_len);
	else if (format_char == 'd')
		parse_decimal(ap, print_len);
	else if (format_char == 'i')
		parse_decimal(ap, print_len);
	else if (format_char == 'u')
		parse_unsigned_decimal(ap, print_len);
	else if (format_char == 'x')
		parse_lower_hexadecimal(ap, print_len);
	else if (format_char == 'X')
		parse_upper_hexadecimal(ap, print_len);
	else
		parse_etc(format_char, print_len);
	(*iter)++;
}

static void	print_parsed_str(va_list *ap, const char *str, int *print_len)
{
	const char	*iter;
	const char	*temp_iter;

	iter = str;
	while (1)
	{
		temp_iter = iter;
		iter = ft_strchr(temp_iter, '%');
		if (!iter)
		{
			iter = ft_strchr(temp_iter, '\0');
			(*print_len) += iter - temp_iter;
			if (iter - temp_iter)
				write(1, temp_iter, iter - temp_iter);
			break ;
		}
		(*print_len) += iter - temp_iter;
		if (iter - temp_iter)
			write(1, temp_iter, iter - temp_iter);
		iter++;
		print_format_str(ap, &iter, print_len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		print_len;

	print_len = 0;
	va_start(ap, str);
	print_parsed_str(&ap, str, &print_len);
	va_end(ap);
	return (print_len);
}
