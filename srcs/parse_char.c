/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:23 by yolee             #+#    #+#             */
/*   Updated: 2022/03/24 15:31:43 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_char(va_list *ap, int *print_len)
{
	char	ch;

	ch = va_arg((*ap), int);
	write(1, &ch, 1);
	(*print_len) += 1;
}
