/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:20:58 by yolee             #+#    #+#             */
/*   Updated: 2022/01/03 20:26:48 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s1_cpy = (char *)malloc(s1_len + 1);
	if (s1_cpy == NULL)
		return (NULL);
	ft_strlcpy(s1_cpy, s1, s1_len + 1);
	return (s1_cpy);
}
