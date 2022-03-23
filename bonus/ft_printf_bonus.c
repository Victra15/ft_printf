/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:21:19 by yolee             #+#    #+#             */
/*   Updated: 2022/03/23 19:39:56 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_format_str(char **format_str,
		t_pflag print_flags,
		int *print_len,
		char parse_chr)
{
	size_t	f_str_len;
	size_t	p_str_len;
	char	*padding;
	char	*print_str;

	padding = NULL;
	f_str_len = ft_strlen(*format_str);
	p_str_len = f_str_len;
	if (print_flags.width > f_str_len)
	{
		p_str_len = print_flags.width;
		padding = (char *)malloc(sizeof(char) * p_str_len - f_str_len + 1);
		if (print_str == NULL)
			return (1);
		padding[p_str_len - f_str_len] = '\0';
	}
	if (print_flags.left_adjust == 1)
	{
		ft_memset(padding, ' ', p_str_len - f_str_len);
	}
	else
	{
		if (print_flags.zero_pad == 1 && print_flags.precision >= 0)
			ft_memset(padding, ' ', p_str_len - f_str_len);
	}
	if (padding != NULL)
		free(padding);
	free(*format_str);
	free(print_str);
	format_str = NULL;
	return (0);
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
			return (0);
		}
		iter = temp_iter_2 + 1;
		if (read_format_str(ap, iter, &print_flags, &format_str))
			return (1);
		print_substr(temp_iter_1, temp_iter_2, print_len);
		if (print_format_str(&format_str, print_flags, print_len, (*iter)))
			return (1);
	}
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
