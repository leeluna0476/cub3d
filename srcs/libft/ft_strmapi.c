/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:12:49 by yegkim            #+#    #+#             */
/*   Updated: 2023/10/18 10:49:32 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		slen;
	char				*result;
	unsigned int		i;

	if (!s || !f)
		return (0);
	slen = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (slen + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < slen)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
