/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:14:03 by yegkim            #+#    #+#             */
/*   Updated: 2023/12/05 14:03:37 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = arr[start];
	i = start;
	j = end;
	while (i < j)
	{
		while (pivot < arr[j])
			j--;
		while (i < j && pivot >= arr[i])
			i++;
		swap(arr + i, arr + j);
	}
	swap(arr + start, arr + j);
	ft_quick_sort(arr, start, j - 1);
	ft_quick_sort(arr, j + 1, end);
}
