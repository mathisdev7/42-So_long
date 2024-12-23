/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:02:09 by mazeghou          #+#    #+#             */
/*   Updated: 2024/12/23 16:11:32 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

ssize_t	read(int fildes, void *buf, size_t nbyte);
size_t	ft_strlen(const char *str);
char	*fill_stash(int fd, char *stash);
char	*ft_strchr(const char *s, int c);
char	*fill_line(char *stash);
char	*create_stash(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
