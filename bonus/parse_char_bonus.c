/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:05:41 by yolee             #+#    #+#             */
/*   Updated: 2022/03/20 16:55:27 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	input_str(char ch,
		char *str,
		size_t str_size,
		t_pflag print_flags)
{
	int	loop;

	loop = 0;
	if (print_flags.left_adjust == 1)
	{
		ft_striteri(str, &fill_with_blank);
		str[0] = ch;
	}
	else
	{
		if (print_flags.zero_pad == 1)
			ft_striteri(str, &fill_with_zero);
		else
			ft_striteri(str, &fill_with_blank);
		str[str_size - 1] = ch;
	}
}

static int	str_allocate(char *output, t_pflag print_flags, size_t print_width)
{
	if (print_flags.width < 1)
		print_width = 1;
	else
		print_width = print_flags.width;
	output = (char *)malloc(print_width + 1);
	if (output == NULL)
		return (1);
	output[print_width] = '\0';
	return (0);
}

void	parse_char(va_list *ap, size_t *print_len, t_pflag print_flags)
{
	char	ch;
	char	*output;
	size_t	print_width;

	ch = va_arg((*ap), int);
	if (str_allocate(output, print_flags, print_width))
		return ;
	input_str(ch, output, print_width, print_flags);
	write(1, output, print_width);
	(*print_len) += print_width;
	free(output);
}
