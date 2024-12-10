/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:23:24 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 22:18:39 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//cpy the argument in file_name
void	one_arg(char *arg, char *file_name)
{
	ft_strcpy(file_name, arg);
}

//read the input from the users in case no map have been given.
void	no_arg(char *file_name)
{
	ssize_t	bytes_read;
	char	buffer[128];

	bytes_read = read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1)
	{
		return ;
	}
	buffer[bytes_read - 1] = '\0';
	ft_strncpy(file_name, buffer, bytes_read);
}

int	open_output_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	read_from_stdin_and_write_to_file(void)
{
	char	buffer[12000];
	ssize_t	bytes_read;
	int		output_file;

	output_file = open_output_file("temp.txt");
	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (bytes_read < 0)
		{
			close(output_file);
			exit(EXIT_FAILURE);
		}
		if (bytes_read == 0)
			break ;
		if (write(output_file, buffer, bytes_read) < 0)
		{
			close(output_file);
			exit(EXIT_FAILURE);
		}
	}
	close(output_file);
}

void	handle_error(void)
{
	exit(EXIT_FAILURE);
}
