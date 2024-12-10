/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:17:38 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 19:54:40 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//lenght of line
int	ft_str_len_line(char *str)
{
	int	i;

	i = 0;
	while (*str != '\n')
	{
		if (*str == '\0')
		{
			return (0);
		}
		str++;
		i++;
	}
	return (i);
}

	//check if c is present in str return -1 otherwise 
int	ft_present(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	if (c == '\n')
	{
		return (1);
	}
	return (-1);
}

//verify if we can find 2 time a same char in a string. 
int	ft_char_is_double(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			count++; 
			if (count >= 2)
				return (0);
		}
		i++;
	}
	return (1);
}

//printable
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			if (str[i] == '\n')
			{
			}
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
