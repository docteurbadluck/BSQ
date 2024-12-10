/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:11:06 by jholterh          #+#    #+#             */
/*   Updated: 2024/10/23 20:32:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	create_helper_map(int i, int j, int **grid, t_field *context)
{
	int	top;

	top = 0;
	if (context->map[i][j] == context->obstacle)
		return (0);
	if (i - 1 < 0 || j - 1 < 0)
		return (1);
	else
	{
		top = grid[i - 1][j];
		if (grid[i][j - 1] < top)
			top = grid[i][j - 1];
		if (grid[i - 1][j - 1] < top)
			top = grid[i - 1][j - 1];
	}
	return (top + 1);
}

void	loop_helper_map(t_field *context, int **grid)
{
	int		i;
	int		j;

	i = -1;
	while (++i < context->nbr_lines)
	{
		j = -1;
		while (++j < context->len_line)
		{
			grid[i][j] = create_helper_map(i, j, grid, context);
		}
	}
}

int	**allocate_grid(t_field *context)
{
	int	**grid;
	int	i;
	int	j;

	grid = (int **)malloc(context->nbr_lines * sizeof(int *));
	if (grid == NULL)
	{
		return (NULL);
	}
	i = -1;
	while (++i < context->nbr_lines)
	{
		grid[i] = (int *)malloc(context->len_line * sizeof(int));
		if (grid[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}
	return (grid);
}

void	print_map(t_field *context)
{
	int	i;
	int	j;

	i = -1;
	while (++i < context->nbr_lines)
	{
		j = -1;
		while (++j < context->len_line)
		{
			write(1, &context->map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

void	ft_highest_nbr(t_field *context, int **grid,
		int *heighest_pos_i, int *heighest_pos_j)
{
	int	heighest_nb;
	int	i;
	int	j;

	heighest_nb = -1;
	i = -1;
	while (++i < context->nbr_lines)
	{
		j = -1;
		while (++j < context->len_line)
		{
			if (grid[i][j] > heighest_nb)
			{
				heighest_nb = grid[i][j];
				*heighest_pos_i = i;
				*heighest_pos_j = j;
			}
		}
	}
}
