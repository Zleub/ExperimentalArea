/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 22:07:12 by adebray           #+#    #+#             */
/*   Updated: 2013/12/12 06:24:41 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define BUFF_SIZE 32

typedef struct	s_global
{
	int				l;
	int				a;
	int				nb_folds;
	char			**folders;
	char			**files;
	struct dirent	**read;
}				t_global;

# include <libft.h>
/* opendir / readdir */
# include <sys/types.h>
# include <dirent.h>
/* perror() */
# include <errno.h>
# include <stdio.h>
#endif
