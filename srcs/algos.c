/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:44:55 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 15:04:20 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	recurs(struct stat **buf, char **path_names, char *path)
{
	char	*new_p;
	int		i;

	i = -1;
	while (buf[++i])
		if (path_names[i][0] != '.' && S_ISDIR(buf[i]->st_mode))
		{
			new_p = add_path(path, path_names[i]);
			algos_on(new_p);
			ft_strdel(&new_p);
		}
}

static int	qua_elems(DIR *dir)
{
	int nmb;

	nmb = 0;
	while (readdir(dir))
		nmb++;
	closedir(dir);
	return (nmb);
}

static void	read_dir(DIR *dir, char *path)
{
	struct stat	**buf;
	char		**path_names;
	int			elemnmb;

	elemnmb = qua_elems(dir);
	g_fl.size = elemnmb;
	buf = malloc(sizeof(struct stat *) * (elemnmb + 1));
	path_names = malloc(sizeof(char *) * (elemnmb + 1));
	allo_buf(buf, path_names, path);
	sort_pls(buf, path_names);
	print_buf(buf, path_names, path);
	ft_putchar('\n');
	size_defaulto();
	if (g_fl.bigr == 1)
		recurs(buf, path_names, path);
	free_all(buf, path_names);
}

static int	if_file(char *path)
{
	struct stat	buf;
	char		c_buf[1024];
	int			the_link;

	if (path == (char *)0x1)
		return (1);
	lstat(path, &buf);
	if ((the_link = (int)readlink(path, c_buf, 1024)) < 0 &&
			!(S_ISREG(buf.st_mode)) && !(S_ISFIFO(buf.st_mode)))
		return (0);
	if (S_ISDIR(buf.st_mode) && !the_link)
		return (0);
	if (!g_fl.bigr)
	{
		if (g_fl.l)
			long_out(buf, path, NULL);
		else
		{
			ft_putstr(path);
			ft_putchar('\n');
		}
	}
	return (1);
}

void		algos_on(char *path)
{
	DIR *dir;

	if (if_file(path))
		return ;
	if (g_fl.bigr || g_fl.qua > 1)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	dir = opendir(path);
	if (dir == NULL)
	{
		perror(path);
		return ;
	}
	read_dir(dir, path);
}
