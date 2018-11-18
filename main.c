/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:47:26 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/30 17:30:41 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_list	*lst;

	if (argc != 2)
	{
		write(1, "usage: ./fillit filename\n", 25);
		return (0);
	}
	valid(argv[1]);
	lst = parse(argv[1], 0, 'A');
	if (!(0 <= ft_lstcount(lst) && ft_lstcount(lst) <= 26))
	{
		ft_putstr("error\n");
		return (0);
	}
	solve(lst, 2);
	return (1);
}
