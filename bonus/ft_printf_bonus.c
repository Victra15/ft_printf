/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 17:23:05 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_format_str(char **format_str,
		t_pflag print_flags,
		int *print_len)
{
	print_flags.left_adjust;
	print_flags.width;
	print_flags.zero_pad;
}

static void	print_substr(const char *start, const char *end, int *print_len)
{
	(*print_len) += end - start;
	if (end - start)
		write(1, start, end - start);
}

static int	print_parsed_str(va_list *ap, const char *str, int *print_len)
{
	const char	*iter;
	const char	*temp_iter_1;
	const char	*temp_iter_2;
	char		*format_str;
	t_pflag		print_flags;

	init_flags(&print_flags);
	iter = str;
	while (1)
	{
		temp_iter_1 = iter;
		temp_iter_2 = ft_strchr(temp_iter_1, '%');
		if (!temp_iter_2)
		{
			temp_iter_2 = ft_strchr(temp_iter_1, '\0');
			print_substr(temp_iter_1, temp_iter_2, print_len);
			break ;
		}
		iter = temp_iter_2 + 1;
		if (read_format_str(ap, iter, &print_flags, &format_str))
			return (1);
		print_substr(temp_iter_1, temp_iter_2, print_len);
		print_format_str(&format_str, print_flags, print_len);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		print_len;

	print_len = 0;
	va_start(ap, str);
	if (print_parsed_str(&ap, str, &print_len))
		print_len = -1;
	va_end(ap);
	return (print_len);
}
