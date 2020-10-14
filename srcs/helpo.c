/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:39:38 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 14:32:39 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add_path(char *path, char *add)
{
	char *res;
	char *tmp;

	if (ft_strcmp(path, "./"))
	{
		tmp = ft_strjoin(path, "/");
		res = ft_strjoin(tmp, add);
		ft_strdel(&tmp);
	}
	else
		res = ft_strjoin(path, add);
	return (res);
}

int		num_len(int nb)
{
	int res;

	res = 1;
	while (nb / 10 > 0)
	{
		res += 1;
		nb /= 10;
	}
	return (res);
}

void	free_all(struct stat **buf, char **path_names)
{
	int i;

	i = -1;
	while (buf[++i] != NULL)
	{
		ft_strdel(&path_names[i]);
		free(buf[i]);
	}
	free(buf);
	free(path_names);
}

void	size_defaulto(void)
{
	g_fl.sizes.group = 0;
	g_fl.sizes.link_size = 0;
	g_fl.sizes.major_size = 0;
	g_fl.sizes.minor_size = 0;
	g_fl.sizes.owner = 0;
	g_fl.sizes.size_size = 0;
	g_fl.sizes.total = 0;
}

void	defaulto(void)
{
	g_fl.l = 0;
	g_fl.a = 0;
	g_fl.bigr = 0;
	g_fl.r = 1;
	g_fl.t = 0;
	g_fl.f = 0;
	g_fl.u = 0;
	size_defaulto();
}
