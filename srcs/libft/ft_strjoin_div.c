/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:13:39 by yegkim            #+#    #+#             */
/*   Updated: 2024/01/15 09:43:57 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_div(char const *s1, char const *s2, char div)
{
	char	*result;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2 || !div)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (result == 0)
		return (0);
	i = 0;
	while (i < s1_len + s2_len + 1)
	{
		if (i < s1_len)
			result[i] = s1[i];
		else if (i == s1_len)
			result[i] = div;
		else
			result[i] = s2[i - s1_len - 1];
		i++;
	}
	result[i] = 0;
	return (result);
}
