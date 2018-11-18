/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 19:37:34 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/30 17:16:46 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"
#include "libft/libft.h"

char	obs_location(char *loc, char *buf)
{
	char	ch;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (buf[i] != '\n' && buf[i] != '.')
		{
			loc[j] = i;
			ch = buf[i];
			j++;
		}
		i++;
	}
	return (ch);
}

int		isplaceable(char *buf, t_map sol, t_point pt)
{
	int		i;
	char	loc[4];

	obs_location(loc, buf);
	i = 0;
	if (sol.map[pt.x][pt.y] != 0)
		return (0);
	while (++i < 4)
	{
		if (loc[i - 1] / 5 == loc[i] / 5)
		{
			pt.y += (loc[i] - loc[i - 1]);
			if (!(0 <= pt.y && pt.y < sol.dim) || (sol.map[pt.x][pt.y] != 0))
				return (0);
		}
		else if (loc[i - 1] / 5 != loc[i] / 5)
		{
			pt.x += 1;
			pt.y += (loc[i] - (loc[i - 1] + 5));
			if (!(0 <= pt.x && pt.x < sol.dim) ||
					!(0 <= pt.y && pt.y < sol.dim) || sol.map[pt.x][pt.y] != 0)
				return (0);
		}
	}
	return (1);
}

void	place(char *buf, char **map, t_point pt, char ch)
{
	char	loc[4];
	int		i;
	char	chr;

	chr = obs_location(loc, buf);
	if (ch != 0)
		ch = chr;
	i = 0;
	map[pt.x][pt.y] = ch;
	while (++i < 4)
	{
		if (loc[i - 1] / 5 == loc[i] / 5)
		{
			pt.y += (loc[i] - loc[i - 1]);
			map[pt.x][pt.y] = ch;
		}
		else if (loc[i - 1] / 5 != loc[i] / 5)
		{
			pt.x += 1;
			pt.y += (loc[i] - (loc[i - 1] + 5));
			map[pt.x][pt.y] = ch;
		}
	}
}

int		solver(t_map sol, t_list *head)
{
	t_point	pt;
	int		solved;

	if (!head)
		print(sol.map, sol.dim);
	pt.x = 0;
	while (pt.x < sol.dim)
	{
		pt.y = 0;
		while (pt.y < sol.dim)
		{
			if (isplaceable(head->content, sol, pt))
			{
				place(head->content, sol.map, pt, 1);
				solved = solver(sol, head->next);
				if (!solved)
					place(head->content, sol.map, pt, 0);
			}
			pt.y++;
		}
		pt.x++;
	}
	return (0);
}
