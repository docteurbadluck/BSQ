/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:17:19 by jholterh          #+#    #+#             */
/*   Updated: 2024/10/23 19:52:33 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_map(int *heighest_pos_i, int *heighest_pos_j,
		int **grid, t_field *context)
{
	int	i;
	int	j;
	int	size;

	size = grid[*heighest_pos_i][*heighest_pos_j];
	i = *heighest_pos_i;
	while (i > *heighest_pos_i - size && i >= 0)
	{
		j = *heighest_pos_j;
		while (j > *heighest_pos_j - size && j >= 0)
		{
			context->map[i][j] = context->fill;
			j--;
		}
		i--;
	}
}

void	free_grid(int **grid, t_field *context)
{
	int	i;

	i = -1;
	while (++i < context->nbr_lines)
		free(grid[i]);
	free(grid);
}

void	free_map(t_field *context)
{
	int	i;

	i = -1;
	while (++i < context->nbr_lines)
		free(context->map[i]);
	free(context->map);
}

void	process(t_field *context)
{
	int	**grid;
	int	heighest_pos_i;
	int	heighest_pos_j;

	heighest_pos_i = -1;
	heighest_pos_j = -1;
	grid = allocate_grid(context);
	if (grid == NULL)
		return ;
	loop_helper_map(context, grid);
	ft_highest_nbr(context, grid, &heighest_pos_i, &heighest_pos_j);
	solve_map(&heighest_pos_i, &heighest_pos_j, grid, context);
	print_map(context);
	free_grid(grid, context);
	free_map(context);
}
