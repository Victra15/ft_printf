/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:36:45 by yolee             #+#    #+#             */
/*   Updated: 2021/12/27 15:31:27 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	base_size;
	size_t	src_size;
	size_t	loop;

	base_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	loop = 0;
	if (base_size >= dstsize)
		return (dstsize + src_size);
	while (base_size + loop < dstsize - 1)
	{
		if (loop < src_size)
			dst[base_size + loop] = src[loop];
		else
			break ;
		loop++;
	}
	dst[base_size + loop] = '\0';
	return (base_size + src_size);
}
