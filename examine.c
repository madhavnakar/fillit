/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:34:18 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/28 16:39:27 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"
#include "libft/libft.h"

void	examine(t_list *head)
{
	while (head)
	{
		write(1, head->content, 20);
		head = head->next;
		write(1, "\n", 1);
	}
}
