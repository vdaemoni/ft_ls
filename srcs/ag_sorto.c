/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ag_sorto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:44:31 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 17:23:21 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rt_sort(int argc, char **argv)
{
	int			i;
	int			j;
	char		*tmp;
	struct stat	buf1;
	struct stat	buf2;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[++i])
		{
			stat(argv[i], &buf1);
			stat(argv[i - 1], &buf2);
			if (buf1.st_mtimespec.tv_sec < buf2.st_mtimespec.tv_sec)
			{
				tmp = ft_strjoin(argv[i - 1], "");
				ft_strdel(&argv[i - 1]);
				argv[i - 1] = ft_strjoin(argv[i], "");
				ft_strdel(&argv[i]);
				argv[i] = tmp;
			}
		}
	}
}

void	t_sort(int argc, char **argv)
{
	int			i;
	int			j;
	char		*tmp;
	struct stat	buf1;
	struct stat	buf2;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[++i])
		{
			stat(argv[i], &buf1);
			stat(argv[i - 1], &buf2);
			if (buf1.st_mtimespec.tv_sec > buf2.st_mtimespec.tv_sec)
			{
				tmp = ft_strjoin(argv[i - 1], "");
				ft_strdel(&argv[i - 1]);
				argv[i - 1] = ft_strjoin(argv[i], "");
				ft_strdel(&argv[i]);
				argv[i] = tmp;
			}
		}
	}
}

void	r_sort(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[++i])
		{
			if (g_fl.r * ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				tmp = ft_strjoin(argv[i - 1], "");
				ft_strdel(&argv[i - 1]);
				argv[i - 1] = ft_strjoin(argv[i], "");
				ft_strdel(&argv[i]);
				argv[i] = tmp;
			}
		}
	}
}
