/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:04:35 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 19:52:45 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//allocate space for the str of the array of string.
void	allocate_string(char ***ptr_to_arr_str, int nbr_of_line, int str_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbr_of_line)
	{
		(*ptr_to_arr_str)[i] = malloc((str_size + 1) * sizeof (char));
		if ((*ptr_to_arr_str)[i] == NULL)
		{
			write(1, "Wrong Allocate", 15);
			j = -1;
			while (++j < i)
				free(ptr_to_arr_str[j]);
			free(ptr_to_arr_str);
			return ;
		}
		i++;
	}
}

//allocate enough space for the char* in the arrray of string.
char	**ft_allocate(int nbr_of_line)
{
	char	**ptr_to_array_of_str;

	ptr_to_array_of_str = malloc(sizeof (char *) * nbr_of_line);
	if (ptr_to_array_of_str == NULL)
	{
		write(1, "error alloc", 11);
		return (NULL);
	}
	return (ptr_to_array_of_str);
}

void	ft_free_allocate(t_field *my_field)
{
	int	i;

	i = 0;
	while (i < my_field->nbr_lines)
	{
		free(my_field->map[i]);
		i++;
	}
	free(my_field->map);
}
