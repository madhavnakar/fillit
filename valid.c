/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:57:05 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/29 12:13:52 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"
#include "libft/libft.h"

void	panic(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		near(int a, char *buf)
{
	int total;

	total = 0;
	if ((0 <= a - 1 && a - 1 <= 19) && buf[a - 1] == '#')
		total++;
	if ((0 <= a + 1 && a + 1 <= 19) && buf[a + 1] == '#')
		total++;
	if ((0 <= a - 5 && a - 5 <= 19) && buf[a - 5] == '#')
		total++;
	if ((0 <= a + 5 && a + 5 <= 19) && buf[a + 5] == '#')
		total++;
	return (total);
}

void	check1(char *buf)
{
	int		i;
	t_check	count;

	i = -1;
	count.hashcnt = 0;
	count.percnt = 0;
	while (++i < 20)
	{
		if ((buf[i] == '\n' && (i + 1) % 5 != 0) ||
				!(buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
			panic();
		if (buf[i] == '.')
			if (++count.percnt > 12)
				panic();
		if (buf[i] == '#')
			if (++count.hashcnt > 4)
				panic();
	}
}

void	check2(char *buf)
{
	int		i;
	int		connections;

	i = 0;
	connections = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			connections += near(i, buf);
		i++;
	}
	if (connections != 6 && connections != 8)
		panic();
}

int		valid(char *filename)
{
	int		fd;
	int		bufre;
	int		ret;
	char	ch;
	char	buf[20];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		panic();
	ret = 1;
	while ((bufre = read(fd, &buf, 5 * 4)) == 20 && ret == 1)
	{
		check1(buf);
		check2(buf);
		ret = read(fd, &ch, 1);
	}
	if (bufre != 0 || ret != 0)
		panic();
	close(fd);
	return (1);
}
