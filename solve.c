/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:19:09 by mnakar            #+#    #+#             */
/*   Updated: 2018/07/01 10:05:22 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"
#include "libft/libft.h"

char	**alloc_map(int dim)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * dim);
	if (!map)
		panic();
	i = 0;
	while (i < dim)
	{
		map[i] = (char *)malloc(sizeof(char) * dim);
		if (!map[i])
			panic();
		j = -1;
		while (++j < dim)
			map[i][j] = 0;
		i++;
	}
	return (map);
}

void	print(char **map, int dim)
{
	int	i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			(!map[i][j]) ? ft_putchar('.') : ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	exit(0);
}

void	free_map(char **map, int dim)
{
	int	i;

	i = 0;
	while (i < dim)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		min_dim(int blocks)
{
	int	i;

	i = 0;
	while (i * i <= blocks)
		i++;
	return ((i - 1) * (i - 1) == blocks ? i - 1 : i);
}

void	solve(t_list *head, int dim)
{
	t_map	solution;

	dim = 0;
	solution.dim = min_dim(ft_lstcount(head));
	while (1)
	{
		solution.map = alloc_map(solution.dim);
		solver(solution, head);
		free_map(solution.map, solution.dim);
		solution.dim++;
	}
}
