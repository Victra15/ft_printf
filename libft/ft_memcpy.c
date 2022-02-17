/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:39:30 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 03:45:31 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*conv_dst;
	const unsigned char	*conv_src;

	if (dst == NULL && src == NULL)
		return (dst);
	conv_dst = dst;
	conv_src = src;
	while (n--)
		*(conv_dst++) = *(conv_src++);
	return (dst);
}
