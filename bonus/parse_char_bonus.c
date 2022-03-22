/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:22:23 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 18:28:36 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parse_char(va_list *ap, t_pflag *print_flags)
{
	char	ch;
	char	*str;

	ch = va_arg((*ap), int);
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[1] = '\0';
	str[0] = ch;
	return (str);
}
