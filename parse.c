/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:37:19 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/30 17:30:01 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"
#include "libft/libft.h"

char	*replace(char *buf, char alph)
{
	int		i;

	i = -1;
	while (++i < 20)
		if (buf[i] == '#')
			buf[i] = alph;
	return (buf);
}

t_list	*parse(char *filename, int fd, char curr)
{
	t_list	*head;
	t_list	*trav;
	int		done;
	char	ch;
	char	buf[20];

	fd = open(filename, O_RDONLY);
	read(fd, buf, 20);
	head = ft_lstnew((const void *)replace(buf, curr), 20);
	trav = head;
	while ((done = read(fd, &ch, 1)) == 1)
	{
		curr++;
		read(fd, buf, 20);
		trav->next = ft_lstnew((const void *)replace(buf, curr), 20);
		trav = trav->next;
	}
	return (head);
}
