/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:59 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/30 12:13:04 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_change_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0' || buffer[1] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_create_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\0' || buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*ft_free_joined(char *buffer, char *tmp)
{
	char	*joined;

	joined = ft_strjoin(buffer, tmp);
	free(buffer);
	return (joined);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp;
	int		read_count;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, tmp, BUFFER_SIZE);
		if (read_count <= 0)
			break ;
		tmp[read_count] = '\0';
		buffer = ft_free_joined(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (buffer[fd] == 0)
		return (NULL);
	line = ft_create_line(buffer[fd]);
	buffer[fd] = ft_change_buffer(buffer[fd]);
	return (line);
}
