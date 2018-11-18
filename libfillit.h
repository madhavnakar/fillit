/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:51:31 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/30 17:30:22 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILLIT_H
# define LIBFILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_check
{
	int	hashcnt;
	int	percnt;
	int	newlncnt;
}				t_check;

typedef struct	s_map
{
	char	**map;
	int		dim;
}				t_map;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

int				valid(char *filename);
void			examine(t_list *head);
t_list			*parse(char *filename, int fd, char curr);
void			solve(t_list *head, int dim);
void			print(char **map, int dim);
void			panic(void);
int				solver(t_map sol, t_list *head);

#endif
