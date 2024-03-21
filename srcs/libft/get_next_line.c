/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:00:14 by yegkim            #+#    #+#             */
/*   Updated: 2023/12/05 15:01:41 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_file(int fd, t_file **head, t_file **file_p)
{
	t_file	*prev;

	*file_p = *head;
	prev = 0;
	while (*file_p)
	{
		if ((*file_p)->fd == fd)
			return (1);
		prev = *file_p;
		*file_p = (*file_p)->next;
	}
	*file_p = (t_file *)malloc(sizeof(t_file));
	if (!*file_p)
		return (0);
	(*file_p)->fd = fd;
	(*file_p)->prev = prev;
	(*file_p)->next = 0;
	(*file_p)->save = ft_strdup("");
	if (!(*file_p)->save)
		return (0);
	if (prev)
		prev->next = *file_p;
	else
		*head = *file_p;
	return (1);
}

static void	free_file(t_file *file, t_file **head, char *result)
{
	if (result)
		free(result);
	if (!file)
		return ;
	if (file->prev)
		file->prev->next = file->next;
	else
		*head = file->next;
	if (file->next)
		file->next->prev = file->prev;
	if (file->save)
		free(file->save);
	free(file);
}

static char	*get_result_and_save(t_file *file, char *ptr)
{
	char	*tmp_p;
	char	*result;

	result = ft_substr(file->save, 0, ptr - file->save + 1);
	tmp_p = file->save;
	file->save = ft_strdup(ptr + 1);
	free(tmp_p);
	if (!file->save)
	{
		free(result);
		return (0);
	}
	return (result);
}

static int	get_result(t_file *file, char **result_p)
{
	ssize_t	r_len;
	char	*ptr;
	char	*tmp_p;

	ptr = 0;
	while (!ptr)
	{
		ptr = ft_strchr(file->save, '\n');
		if (ptr)
			break ;
		r_len = read(file->fd, file->buf, BUFFER_SIZE);
		if (r_len < 0)
			return (0);
		(file->buf)[r_len] = 0;
		tmp_p = file->save;
		file->save = ft_strjoin(file->save, file->buf);
		free(tmp_p);
		if (!file->save)
			return (0);
		if (!r_len)
			ptr = file->save + ft_strlen(file->save) - 1;
	}
	*result_p = get_result_and_save(file, ptr);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_file	*head;
	t_file			*file;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	file = 0;
	if (!find_file(fd, &head, &file))
	{
		free_file(file, &head, 0);
		return (0);
	}
	result = 0;
	if (!get_result(file, &result) || !result || !*result)
	{
		free_file(file, &head, result);
		return (0);
	}
	return (result);
}
