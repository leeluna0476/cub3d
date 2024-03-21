/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:46:18 by yegkim            #+#    #+#             */
/*   Updated: 2023/10/18 12:44:42 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;
	char	*ptr;

	i = 0;
	ret = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			ret = ptr + i;
		i++;
	}
	if (ptr[i] == (char)c)
		ret = ptr + i;
	return (ret);
}
