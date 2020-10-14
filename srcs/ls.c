/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:50:48 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 17:19:06 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_ag(int argc, char **argv)
{
	int		i;

	i = -1;
	while (argv[++i])
		argv[i] = ft_strjoin(argv[i], "");
	if ((g_fl.t == 1) && (g_fl.r == -1))
		rt_sort(argc, argv);
	else if ((g_fl.t == 1) && (g_fl.r == 1))
		t_sort(argc, argv);
	else if ((g_fl.t == 0) && (g_fl.r == -1))
		r_sort(argc, argv);
}

static void	help_pars(char c)
{
	if (c == 'l')
		g_fl.l = 1;
	else if (c == 'a')
		g_fl.a = 1;
	else if (c == 'R')
		g_fl.bigr = 1;
	else if (c == 't')
		g_fl.t = 1;
	else if (c == 'r')
		g_fl.r = -1;
	else if (c == 'f')
	{
		g_fl.f = 1;
		g_fl.a = 1;
	}
	else if (c == 'u')
		g_fl.u = 1;
	else
		print_usage(c);
}

static int	raspars(char *s)
{
	int i;

	i = 0;
	if (s[i] != '-' || ft_strlen(s) == 1)
		return (0);
	if (s[i] == '-' && s[i + 1] == '-')
		return (2);
	while (s[++i])
		help_pars(s[i]);
	return (1);
}

static void	begino(int argc, char **argv)
{
	int i;

	i = 1;
	while (1)
		if (argc > 1 && argv[i] && raspars(argv[i]))
		{
			i++;
			if (raspars(argv[i - 1]) == 2)
				break ;
		}
		else
			break ;
	if (argc - i == 0)
	{
		algos_on("./");
		return ;
	}
	crutch(argc, &argv[i]);
	while (argv[i])
	{
		algos_on(argv[i]);
		if (argv[i + 1] != NULL && argv[i] != (char *)0x1)
			ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	defaulto();
	begino(argc, argv);
	return (0);
}
