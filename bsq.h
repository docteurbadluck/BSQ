/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:30:38 by tdeliot           #+#    #+#             */
/*   Updated: 2024/10/23 23:30:54 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_field{
	int		nbr_lines;
	int		len_line;
	char	free_space;
	char	obstacle;
	char	fill;
	char	**map;
	char	map_char[4];
}t_field;

// map_handling.c 
char	*ft_file_to_str(char *file_name, char *buffer);
void	read_file_content(int fd, char *buffer);
int		ft_is_valid(char *buffer, int nbr_line, int *len_line_main);
int		ft_count_line(char *buffer);

//map_handling_2.c
int		handle_map_char(char *buffer, char *map_char, int *nbr_line);
void	ft_cp_map(char *buffer, char **map, int nbr_line, int len);
int		ft_is_valid_3(char **map, char *map_char, int nbr_line);
int		ft_is_valid_2(char *map_char);
//str_manip.c
int		ft_str_len_line(char *str);
int		ft_present(char *str, char c);
int		ft_char_is_double(char *str, char c);
int		ft_str_is_printable(char *str);
int		ft_strlen(char *str);

// str_manip_2.c
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

//allocate_manager.c
void	allocate_string(char ***ptr_to_arr_str, int nbr_of_line, int str_size);
char	**ft_allocate(int nbr_of_line);
void	ft_free_allocate(t_field *my_field);
void	write_to_file(int fd, char *buffer, ssize_t bytes_read);

//input_manager.c
void	one_arg(char *arg, char *file_name);
void	no_arg(char *file_name);
void	read_from_stdin_and_write_to_file(void);
int		count_first_line(int fd, char *buffer);

//error_manager.c
void	ft_print_map_error(void);

//process_manager.c
int		upload_valid_map(char *str_map, char *buffer);
int		initiate_struct(t_field *my_field, char *str_map);
int		valid_and_init(char *file_name, char *str_map, t_field *my_field);

//algo.c
int		create_helper_map(int i, int j, int **grid, t_field *context);
void	loop_helper_map(t_field *context, int **grid);
int		**allocate_grid(t_field *context);
void	print_map(t_field *context);
void	ft_highest_nbr(t_field *context, int **grid,
			int *heighest_pos_i, int *heighest_pos_j);
void	solve_map(int *heighest_pos_i, int *heighest_pos_j,
			int **grid, t_field *context);
void	free_grid(int **grid, t_field *context);
void	free_map(t_field *context);
void	process(t_field *context);

int		is_first_line_at_least_four_chars(const char *filename);
int		check_first_line_length(char *buffer, ssize_t bytesRead);
ssize_t	read_file(int fd, char *buffer);
char	*allocate_buffer(void);
int		open_file(const char *filename);
void	handle_error(void);

int		handle_no_args(char *str_map, t_field *my_field);
void	handle_args(int argc, char **argv, char *str_map, t_field *my_field);
