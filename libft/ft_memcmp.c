/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:39:22 by yolee             #+#    #+#             */
/*   Updated: 2022/01/04 01:50:03 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*conv_s1;
	const unsigned char	*conv_s2;
	size_t				loop;

	if (n == 0)
		return (0);
	conv_s1 = s1;
	conv_s2 = s2;
	loop = 0;
	while (loop < n && *(conv_s1) == *(conv_s2))
	{
		if (++loop != n)
		{
			conv_s1++;
			conv_s2++;
		}
	}
	return (*conv_s1 - *conv_s2);
}
