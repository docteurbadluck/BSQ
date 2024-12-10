/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:09:13 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 22:09:33 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error();
	return (fd);
}

char	*allocate_buffer(void)
{
	char	*buffer;

	buffer = (char *)malloc(12000);
	if (!buffer)
		handle_error();
	return (buffer);
}

ssize_t	read_file(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, 12000 - 1);
	if (bytes_read < 0)
		handle_error();
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

int	check_first_line_length(char *buffer, ssize_t bytes_read)
{
	int	char_count;
	int	i;

	char_count = 0;
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			break ;
		if (buffer[i] != '\r')
			char_count++;
		if (char_count >= 4)
			return (1);
		i++;
	}
	return (0);
}

int	is_first_line_at_least_four_chars(const char *filename)
{
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;
	int		result;

	fd = open_file(filename);
	buffer = allocate_buffer();
	bytes_read = read_file(fd, buffer);
	result = check_first_line_length(buffer, bytes_read);
	free(buffer);
	close(fd);
	return (result);
}
