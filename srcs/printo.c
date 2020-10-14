/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:09:17 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 16:27:07 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dopa(mode_t mode, int n)
{
	if (n == 3)
	{
		if (S_ISUID & mode)
			ft_putchar((S_IXUSR) ? 'S' : 's');
		else
			ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	}
	if (n == 6)
	{
		if (S_ISGID & mode)
			ft_putchar((S_IXGRP) ? 'S' : 's');
		else
			ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	}
	if (n == 9)
	{
		if (mode & S_ISVTX)
			ft_putchar((S_ISDIR(mode)) ? 't' : 'T');
		else
			ft_putchar((mode & S_IXOTH) ? 'x' : '-');
	}
}

void	print_str(char *s, int out)
{
	int i;
	int len;

	len = (int)ft_strlen(s);
	i = 0;
	if (len != out)
		while (i++ < out - len)
			ft_putchar(' ');
	ft_putstr(s);
	ft_putchar(' ');
}

void	print_group(struct stat buf)
{
	char *tmp;

	if (getgrgid(buf.st_gid))
		print_str(getgrgid(buf.st_gid)->gr_name, g_fl.sizes.group);
	else
	{
		tmp = ft_itoa(buf.st_gid);
		print_str(tmp, g_fl.sizes.group);
		ft_strdel(&tmp);
	}
	ft_putchar(' ');
}

void	print_date(time_t date)
{
	char *str_date;

	str_date = ctime(&date);
	write(STDOUT_FILENO, str_date + 4, 3);
	ft_putchar(' ');
	write(STDOUT_FILENO, str_date + 8, 2);
	ft_putchar(' ');
	write(STDOUT_FILENO, str_date + 11, 5);
	ft_putchar(' ');
}

void	print_majmin(struct stat buf)
{
	int i;
	int maj;
	int min;

	i = 0;
	min = num_len(minor(buf.st_rdev));
	maj = num_len(major(buf.st_rdev));
	if (num_len(maj) != g_fl.sizes.major_size)
		while (i++ < g_fl.sizes.major_size - maj)
			ft_putchar(' ');
	ft_putnbr(major(buf.st_rdev));
	ft_putchar(',');
	i = 0;
	if (num_len(min) != g_fl.sizes.minor_size)
		while (i++ < g_fl.sizes.minor_size - min)
			ft_putchar(' ');
	ft_putnbr(minor(buf.st_rdev));
	ft_putchar(' ');
}
