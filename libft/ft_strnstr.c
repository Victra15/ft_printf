/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:40:16 by yolee             #+#    #+#             */
/*   Updated: 2022/01/04 02:38:05 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip(const char h_chr,
	 const char *needle,
	 size_t n_idx,
	 size_t *h_idx)
{
	size_t	skip;

	skip = 0;
	while (n_idx >= skip
		&& h_chr != needle[n_idx - skip])
		skip++;
	(*h_idx) += skip;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	h_idx;
	size_t	n_idx;

	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)(haystack));
	h_idx = 0;
	while ((h_idx + n_len) <= len
		&& (h_idx + n_len) <= h_len)
	{
		n_idx = n_len - 1;
		while (n_idx > 0 && haystack[h_idx + n_idx] == needle[n_idx])
			n_idx--;
		if (n_idx == 0 && haystack[h_idx + n_idx] == needle[n_idx])
			return ((char *)(&haystack[h_idx + n_idx]));
		else
			ft_skip(haystack[h_idx + n_idx], needle, n_idx, &h_idx);
	}
	return (NULL);
}
