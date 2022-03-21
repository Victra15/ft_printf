/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:25:45 by yolee             #+#    #+#             */
/*   Updated: 2022/03/21 18:22:18 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	input_str(char *i_str,
		char *str,
		size_t str_size,
		t_pflag print_flags)
{
	size_t	i_str_size;

	i_str_size = ft_strlen(i_str);
	print_flags.precision -= i_str_size;
	if (print_flags.left_adjust == 1)
	{
		if (print_flags.add_blank == 1)
			ft_memset(str, ' ');
		if (print_flags.precision > 0)
			ft_memset(str, '0', print_flags.precision)
		ft_memmove(str, i_str, i_str_size);
		ft_memset(str, ' ', print_flags)
	}
	else
	{

	}
	if (print_flags.zero_pad == 1);
	print_flags.precision;
}

static int	str_allocate(char *i_str,
		char *output,
		t_pflag print_flags,
		size_t *print_width)
{
	size_t	i_str_size;

	i_str_size = ft_strlen(i_str);
	print_flags.precision -= i_str_size;
	print_width = print_flags.precision + i_str_size;
	if ((*print_width) < print_flags.width)
		(*print_width) = print_flags.precision;
	if ((*print_width) < i_str_size)
		(*print_width) = i_str_size;
	output = (char *)malloc((*print_width) + 1);
	if (output == NULL)
		return (1);
	output[(*print_width)] = '\0';
	return (0);
}

void	parse_decimal(va_list *ap, size_t *print_len, t_pflag print_flags)
{
	int		nbr;
	char	*i_str;
	char	*output;
	size_t	print_width;

	nbr = va_arg((*ap), int);
	i_str = ft_itoa(nbr);
	if (str_allocate(i_str, output, print_flags, &print_width))
		return ;
	input_str(i_str, output, print_width, print_flags);
	write(1, output, print_width);
	(*print_len) += print_width;
	free(i_str);
	free(output);
}
