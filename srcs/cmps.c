/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:09:31 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/23 16:36:43 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_lex(char *a, char *b)
{
	return (g_fl.r * ft_strcmp(a, b));
}

int	cmp_time(struct stat *a, struct stat *b)
{
	return (g_fl.r == 1 ? (a->st_mtimespec.tv_sec < b->st_mtimespec.tv_sec) :
			(a->st_mtimespec.tv_sec > b->st_mtimespec.tv_sec));
}

int	cmp_u(struct stat *a, struct stat *b)
{
	return (g_fl.r == 1 ? (a->st_atimespec.tv_sec < b->st_atimespec.tv_sec) :
			(a->st_atimespec.tv_sec > b->st_atimespec.tv_sec));
}
