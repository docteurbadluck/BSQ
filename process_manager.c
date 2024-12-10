/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:35:36 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 23:30:34 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//str_map will store the map buffer is the name of the file that we open to copy
int	upload_valid_map(char *str_map, char *buffer)
{
	str_map = ft_file_to_str(buffer, str_map);
	if (str_map == NULL)
	{
		return (0);
	}
	return (1);
}

int	initiate_struct(t_field *my_field, char *str_map)
{
	if (!(handle_map_char(str_map, my_field->map_char, &my_field->nbr_lines)))
		return (0);
	if (ft_is_valid(str_map, my_field->nbr_lines, &my_field->len_line) == 0)
	{
		return (0);
	}
	if (ft_is_valid_2(my_field->map_char) == 0)
	{
		return (0);
	}
	my_field->map = ft_allocate(my_field->nbr_lines);
	allocate_string(&my_field->map, my_field->nbr_lines, 
		(my_field->len_line + 1));
	ft_cp_map(str_map, my_field->map, my_field->nbr_lines,
		(my_field->len_line + 1));
	my_field->obstacle = my_field->map_char[1];
	my_field->fill = my_field->map_char[2];
	return (1);
}

int	valid_and_init(char *file_name, char *str_map, t_field *my_field)
{
	if (upload_valid_map(str_map, file_name) == 0)
	{
		ft_print_map_error();
		return (0);
	}
	if (initiate_struct(my_field, str_map) == 0)
	{
		ft_print_map_error();
		return (0);
	}
	if (ft_is_valid_3(my_field->map,
			my_field->map_char, my_field->nbr_lines) == 0)
	{
		ft_free_allocate(my_field);
		ft_print_map_error();
		return (0);
	}
	return (1);
}
