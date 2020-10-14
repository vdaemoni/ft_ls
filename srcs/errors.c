/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:38:31 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 15:51:20 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_usage(char c)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ./ft_ls [-Raflrtu] [file ...]\n");
	exit(0);
}

static void	ch_ag_er(char **argv)
{
	int			i;
	struct stat	buf;

	i = -1;
	while (argv[++i])
		if (stat(argv[i], &buf) != 0)
		{
			perror(argv[i]);
			argv[i] = (char *)0x1;
		}
		else
			g_fl.qua++;
}

void		crutch(int argc, char **av)
{
	sort_ag(argc, av);
	ch_ag_er(av);
}
