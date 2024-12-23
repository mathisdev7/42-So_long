/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:01:30 by mazeghou          #+#    #+#             */
/*   Updated: 2024/11/15 14:37:24 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*fill_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = fill_line(stash);
	stash = create_stash(stash);
	return (line);
}

/*
int main(void)
{
    char *fileName = "./get_next_line.c";
    int fd = open(fileName, O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }
	while (1)
	{
		char *line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
		}
		else
			break;
		free(line);
	}
    close(fd);
    return 0;
}
*/
