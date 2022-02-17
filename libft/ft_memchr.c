/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:39:18 by yolee             #+#    #+#             */
/*   Updated: 2022/01/06 21:44:44 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			conv_c;
	const unsigned char		*conv_s;

	conv_c = c;
	conv_s = s;
	while (n--)
	{
		if (*conv_s == conv_c)
			return ((void *)(conv_s));
		conv_s++;
	}
	return (NULL);
}
