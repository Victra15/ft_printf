/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:31:22 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 04:46:02 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_sub;
	size_t	s_sub_len;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		s_sub = (char *)malloc(1);
		if (s_sub == NULL)
			return (NULL);
		*s_sub = '\0';
		return (s_sub);
	}
	s_sub_len = ft_strlen(&s[start]);
	if (s_sub_len > len)
		s_sub = (char *)malloc(len + 1);
	else
		s_sub = (char *)malloc(s_sub_len + 1);
	if (s_sub == NULL)
		return (NULL);
	if (s_sub_len > len)
		ft_strlcpy(s_sub, &s[start], len + 1);
	else
		ft_strlcpy(s_sub, &s[start], s_sub_len + 1);
	return (s_sub);
}
