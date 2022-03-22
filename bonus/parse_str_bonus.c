/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:29:04 by yolee             #+#    #+#             */
/*   Updated: 2022/03/22 18:32:59 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parse_str(va_list *ap, t_pflag *print_flags)
{
	char	*str;
	char	*param_str;

	param_str = va_arg((*ap), char *);
	if (param_str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(param_str);
	return (str);
}
