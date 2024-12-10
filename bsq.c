/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:26:59 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 22:05:53 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	handle_no_args(char *str_map, t_field *my_field)
{
	read_from_stdin_and_write_to_file();
	if (!is_first_line_at_least_four_chars("temp.txt"))
	{
		ft_print_map_error();
		return (0);
	}
	if (!valid_and_init("temp.txt", str_map, my_field))
		return (-1);
	process(my_field);
	return (0);
}

void	handle_args(int argc, char **argv, char *str_map, t_field *my_field)
{
	char	file_name[128];
	int		j;

	j = 0;
	while (++j < argc)
	{
		ft_strcpy(file_name, argv[j]);
		if (valid_and_init(file_name, str_map, my_field))
			process(my_field);
		if (argc != 2 && j != (argc - 1))
			write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_field	my_field;
	char	str_map[12000];

	if (argc == 1)
		return (handle_no_args(str_map, &my_field));
	handle_args(argc, argv, str_map, &my_field);
	return (0);
}
