/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/02/17 19:48:45 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing(va_list ap, const char *str, char *print_str)
{
	char	*iter;

	iter = str;
	while (1)
	{
		iter = ft_strchr(iter, '%');
		if (!iter)
			break ;
		iter++;
	}
}

size_t	print_len(va_list ap, const char *str)
{
	char	*iter;
	char	*temp_iter;
	size_t	len;

	iter = str;
	while (1)
	{
		temp_iter = iter;
		iter = ft_strchr(iter, '%');
		if (!iter)
		{
			iter = ft_strchr(iter, '\0');
			len += iter - temp_iter;
			break ;
		}
		iter++;
		len += iter - temp_iter;
		len += scan_format(ap, &iter);
	}
	return (len);
}

size_t	scan_format(va_list ap, char **iter)
{
	size_t	result;

	if ((*iter) == 'c')

	else if ((*iter) == 's')

	else if ((*iter) == 'p')

	else if ((*iter) == 'd')
	
	else if ((*iter) == 'i')
	
	else if ((*iter) == 'u')
	
	else if ((*iter) == 'x')
	
	else if ((*iter) == 'X')
	
	else if ((*iter) == '%')
	
	else
	



}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	print_str_len;
	char	*print_str;

	va_start(ap, str);
	print_str_len = print_len(ap, str);
	print_str = (char *)malloc(sizeof(char) * print_str_len);
	va_start(ap, str);
	parsing(ap, str, print_str);
	write(1, print_str, print_str_len);
	va_end(ap);
	return (0);
}
