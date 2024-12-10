/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:10:09 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 20:26:43 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//initiate the 3 char use for the map and the number of line of the map
int	handle_map_char(char *buffer, char *map_char, int *nbr_line)
{
	char	line_nbr_char[300];
	int		size_map_char;

	size_map_char = ft_str_len_line(buffer);
	ft_strncpy(line_nbr_char, buffer, (size_map_char - 3));
	*nbr_line = ft_atoi(line_nbr_char);
	if (*nbr_line == 0)
	{
		return (0);
	}
	buffer += (size_map_char -3);
	ft_strncpy(map_char, buffer, 3);
	return (1);
}

//valid the map_char (no double char in it) no not printable char in it)
int	ft_is_valid_2(char *map_char)
{
	int	i;

	i = 0;
	while (map_char[i] != '\0')
	{
		if (ft_char_is_double(map_char, map_char[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	if (ft_str_is_printable(map_char) == 0)
	{
		return (0);
	}
	return (1);
}

//copy the map from the buffer in the array of str ( include the \n) 
void	ft_cp_map(char *buffer, char **map, int nbr_line, int len)
{
	int		i;
	char	*init;

	init = buffer; 
	while (*buffer != '\n')
	{
		buffer++;
	}
	buffer++;
	i = 0;
	while (i < nbr_line)
	{
		ft_strncpy(map[i], buffer, len);
		buffer += len;
		i++;
	}
	buffer = init;
}

//verify if it's only  map_char char in the map and \n
int	ft_is_valid_3(char **map, char *map_char, int nbr_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nbr_line)
	{
		while (map[i][j] != '\n')
		{
			if (map[i][j] == '\0')
			{
				return (0);
			}
			if (ft_present(map_char, map[i][j]) == -1)
			{
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
