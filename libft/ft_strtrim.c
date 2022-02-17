/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:21:35 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 04:50:41 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strldup(const char *s1, size_t dest_len)
{
	char	*s1_cpy;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (s1_len > dest_len)
		s1_cpy = (char *)malloc(dest_len + 1);
	else
		s1_cpy = (char *)malloc(s1_len + 1);
	if (s1_cpy == NULL)
		return (NULL);
	if (s1_len > dest_len)
		ft_strlcpy(s1_cpy, s1, dest_len + 1);
	else
		ft_strlcpy(s1_cpy, s1, s1_len + 1);
	return (s1_cpy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s;
	size_t	left;
	size_t	right;

	if (s1 == NULL)
		return (0);
	left = 0;
	right = ft_strlen(s1);
	while (left != right && ft_strchr(set, s1[left]))
		left++;
	while (left != right && ft_strrchr(set, s1[right]))
		right--;
	trim_s = ft_strldup(&s1[left], right - left + 1);
	if (trim_s == NULL)
		return (NULL);
	else
		return (trim_s);
}
