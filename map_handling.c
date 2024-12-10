/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:33:40 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 21:43:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//Open the file, copy the contene in a the argument buffer.
char	*ft_file_to_str(char *file_name, char *buffer)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	read_file_content(fd, buffer);
	close(fd); 
	return (buffer);
}

//copy the file in a string. return nothing
void	read_file_content(int fd, char *buffer)
{
	char	c;
	int		index;

	index = 0;
	while (read(fd, &c, 1) > 0)
	{
		buffer[index] = c;
		index++;
		if (index >= 12000 - 1)
			break ;
	}
	buffer[index] = '\0';
}

//copy the file in a string. return nothing
int	count_first_line(int fd, char *buffer)
{
	char	c;
	int		index;

	index = 0;
	while (read(fd, &c, 1) > 0)
	{
		buffer[index] = c;
		write(1, &c, 1);
		if (buffer[index] == '\n')
		{
			return (index); 
		}
		index++;
		if (index >= 12000 - 1)
			break ;
	}
	return (-1);
}

//count the number of line in the file
int	ft_count_line(char *buffer)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}

//verify if all line have the same size initialate Len_line_main
int	ft_is_valid(char *buffer, int nbr_line, int *len_line_main)
{
	char	*beggin;
	int		len_line;
	int		new_len_line;
	int		i;

	beggin = buffer;
	while (*buffer != '\n')
		buffer++;
	buffer++;
	len_line = ft_str_len_line(buffer);
	buffer += (len_line + 1);
	i = 1; 
	while (++i <= nbr_line)
	{
		new_len_line = ft_str_len_line(buffer);
		if (new_len_line != len_line)
		{
			return (0);
		}
		buffer += (new_len_line + 1);
	}
	*len_line_main = len_line;
	buffer = beggin;
	return (1);
}
