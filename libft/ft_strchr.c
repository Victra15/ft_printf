/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:39:45 by yolee             #+#    #+#             */
/*   Updated: 2022/01/03 20:24:33 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	conv_c;

	conv_c = (char)c;
	while (*s != '\0')
	{
		if (*s == conv_c)
			return ((char *)(s));
		s++;
	}
	if (conv_c == '\0')
		return ((char *)(s));
	else
		return (NULL);
}
