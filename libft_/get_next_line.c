/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:21:53 by iker              #+#    #+#             */
/*   Updated: 2025/09/09 16:15:27 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*temp;
	size_t	skip;
	size_t	i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n' && (*buffer)[i] != '\r')
		i++;
	line = ft_substr(*buffer, 0, i);
	skip = 0;
	if ((*buffer)[i] == '\r' && (*buffer)[i + 1] == '\n')
		skip = 2;
	else if ((*buffer)[i] == '\n' || (*buffer)[i] == '\r')
		skip = 1;
	temp = ft_strdup(*buffer + i + skip);
	free(*buffer);
	*buffer = temp;
	return (line);
}

static int	read_into_buffer(int fd, char **buffer)
{
	char	*temp;
	char	*buf;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*buffer, buf);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(*buffer, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	bytes_read = read_into_buffer(fd, &buffer);
	if (bytes_read < 0 || (bytes_read == 0 && !*buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (extract_line(&buffer));
}
