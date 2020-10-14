/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:10:10 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 14:56:14 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_buf(struct stat **buf, char **path_names, char *path)
{
	int i;

	i = -1;
	g_fl.a ? g_fl.size++ : 0;
	if (g_fl.l && g_fl.size > 2)
	{
		ft_putstr("total ");
		ft_putnbr(g_fl.sizes.total);
		ft_putchar('\n');
	}
	while (buf[++i] != NULL)
		if (path_names[i][0] != '.' || g_fl.a == 1)
		{
			if (g_fl.l)
				long_out(*buf[i], path_names[i], path);
			else
			{
				ft_putstr(path_names[i]);
				ft_putchar('\n');
			}
		}
	g_fl.sizes.total = 0;
}

static void	check_sizes(struct stat buf)
{
	if (num_len(buf.st_nlink) > g_fl.sizes.link_size)
		g_fl.sizes.link_size = num_len(buf.st_nlink);
	if (getgrgid(buf.st_gid) &&
			(int)ft_strlen(getgrgid(buf.st_gid)->gr_name) > g_fl.sizes.group)
		g_fl.sizes.group = (int)ft_strlen(getgrgid(buf.st_gid)->gr_name);
	if (getpwuid(buf.st_uid) &&
			(int)ft_strlen(getpwuid(buf.st_uid)->pw_name) > g_fl.sizes.owner)
		g_fl.sizes.owner = (int)ft_strlen(getpwuid(buf.st_uid)->pw_name);
	if (num_len((int)buf.st_size) > g_fl.sizes.size_size)
		g_fl.sizes.size_size = num_len((int)buf.st_size);
	if (num_len(minor(buf.st_rdev)) > g_fl.sizes.minor_size)
		g_fl.sizes.minor_size = num_len(minor(buf.st_rdev));
	if (num_len(major(buf.st_rdev)) > g_fl.sizes.major_size)
		g_fl.sizes.major_size = num_len(major(buf.st_rdev));
	g_fl.sizes.total += buf.st_blocks;
}

void		allo_buf(struct stat **buf, char **path_names, char *path)
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;
	char			*new_p;

	i = 0;
	dir = opendir(path);
	while ((sd = readdir(dir)))
	{
		buf[i] = malloc(sizeof(struct stat));
		new_p = add_path(path, sd->d_name);
		stat(new_p, buf[i]);
		check_sizes(*buf[i]);
		ft_strdel(&new_p);
		path_names[i] = ft_strjoin(sd->d_name, "");
		i++;
	}
	buf[i] = NULL;
	path_names[i] = NULL;
	closedir(dir);
}
