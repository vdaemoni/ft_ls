/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:18:27 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 14:30:56 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_owner(struct stat buf)
{
	char *tmp;

	if (getpwuid(buf.st_uid))
		print_str(getpwuid(buf.st_uid)->pw_name, g_fl.sizes.owner);
	else
	{
		tmp = ft_itoa(buf.st_uid);
		print_str(tmp, g_fl.sizes.owner);
		ft_strdel(&tmp);
	}
	ft_putchar(' ');
}

static void	print_int(int n, int out)
{
	int i;

	i = 0;
	if (num_len(n) != out)
		while (i++ < out - num_len(n))
			ft_putchar(' ');
	ft_putnbr(n);
	ft_putchar(' ');
}

static void	access_first_param(mode_t mode)
{
	ft_putchar((S_ISDIR(mode)) ? 'd' : '\0');
	ft_putchar((S_ISLNK(mode)) ? 'l' : '\0');
	ft_putchar((S_ISFIFO(mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(mode)) ? 'c' : '\0');
	ft_putchar((S_ISBLK(mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(mode)) ? '-' : '\0');
	ft_putchar((S_ISSOCK(mode)) ? 's' : '\0');
}

static void	print_access(mode_t mode)
{
	access_first_param(mode);
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	dopa(mode, 3);
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	dopa(mode, 6);
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	dopa(mode, 9);
	ft_putstr("  ");
}

void		long_out(struct stat buf, char *filename, char *path)
{
	char c_buf[1024];
	char *tmp;

	print_access(buf.st_mode);
	print_int(buf.st_nlink, g_fl.sizes.link_size);
	print_owner(buf);
	print_group(buf);
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		print_majmin(buf);
	else
		print_int((int)buf.st_size, g_fl.sizes.size_size);
	g_fl.u == 1 ? print_date(buf.st_atimespec.tv_sec) :
		print_date(buf.st_mtimespec.tv_sec);
	ft_putstr(filename);
	path == NULL ? (tmp = ft_strjoin(filename, "")) :
		(tmp = add_path(path, filename));
	if (readlink(tmp, c_buf, 1024) != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(c_buf);
	}
	ft_strdel(&tmp);
	ft_putchar('\n');
}
