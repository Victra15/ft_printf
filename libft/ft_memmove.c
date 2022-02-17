/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:39:32 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 04:17:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*conv_dst;
	const unsigned char	*conv_src;

	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
	{
		conv_dst = (unsigned char *)dst;
		conv_src = (const unsigned char *)src;
		while (len--)
			*(conv_dst++) = *(conv_src++);
	}
	else
	{
		conv_dst = (unsigned char *)dst + len - 1;
		conv_src = (const unsigned char *)src + len - 1;
		while (len--)
			*(conv_dst--) = *(conv_src--);
	}
	return (dst);
}
