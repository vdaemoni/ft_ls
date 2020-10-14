/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:32:28 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/02/25 17:19:51 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>

typedef struct		s_sizes
{
	int				link_size;
	int				owner;
	int				group;
	int				size_size;
	int				minor_size;
	int				major_size;
	int				total;
}					t_sizes;

typedef struct		s_flagz
{
	int				l;
	int				a;
	int				bigr;
	int				r;
	int				t;
	int				u;
	int				f;
	int				qua;
	int				size;
	t_sizes			sizes;
}					t_flagz;

t_flagz				g_fl;

void				crutch(int argc, char **av);
void				sort_ag(int argc, char **argv);
void				r_sort(int argc, char **argv);
void				t_sort(int argc, char **argv);
void				rt_sort(int argc, char **argv);
void				algos_on(char *path);
char				*add_path(char *path, char *add);
int					num_len(int nb);
void				print_usage(char c);
void				free_all(struct stat **buf, char **path_names);
void				defaulto(void);
void				size_defaulto(void);
int					cmp_lex(char *a, char *b);
int					cmp_time(struct stat *a, struct stat *b);
int					cmp_u(struct stat *a, struct stat *b);
void				allo_buf(struct stat **buf, char **path_names, char *path);
void				print_buf(struct stat **buf, char **path_names, char *path);
void				sort_pls(struct stat **buf, char **path_names);
void				long_out(struct stat buf, char *filename, char *path);
void				print_usage(char c);
void				print_group(struct stat buf);
void				print_str(char *s, int out);
void				print_date(time_t date);
void				print_majmin(struct stat buf);
void				dopa(mode_t mode, int n);

#endif
