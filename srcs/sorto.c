/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:35:03 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/24 11:11:07 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	swappo(struct stat **buf, char **path_names, int i)
{
	char		*c_tmp;
	struct stat	tmp;

	tmp = *buf[i - 1];
	*buf[i - 1] = *buf[i];
	*buf[i] = tmp;
	c_tmp = ft_strjoin(path_names[i], "");
	ft_strdel(&path_names[i]);
	path_names[i] = ft_strjoin(path_names[i - 1], "");
	ft_strdel(&path_names[i - 1]);
	path_names[i - 1] = c_tmp;
}

static void	do_sort(struct stat **buf, char **path_names,
			int (*cmp_b)(struct stat *, struct stat *),
			int (*cmp_l)(char *, char *))
{
	int i;
	int j;

	j = 0;
	while (++j < g_fl.size)
	{
		i = 0;
		while (buf[++i])
			if ((cmp_l && cmp_l(path_names[i - 1], path_names[i]) > 0) ||
						(cmp_b && cmp_b(buf[i - 1], buf[i]) > 0))
				swappo(buf, path_names, i);
	}
}

void		sort_pls(struct stat **buf, char **path_names)
{
	if (g_fl.f == 1)
		return ;
	do_sort(buf, path_names, NULL, cmp_lex);
	if (g_fl.t == 1 && g_fl.u == 0)
		do_sort(buf, path_names, cmp_time, NULL);
	if (g_fl.u == 1 && g_fl.t == 1)
		do_sort(buf, path_names, cmp_u, NULL);
}
