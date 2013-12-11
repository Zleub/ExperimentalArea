/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 22:07:12 by adebray           #+#    #+#             */
/*   Updated: 2013/12/11 09:28:58 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define BUFF_SIZE 32

typedef struct	s_global
{
	int		l;
	int		a;
	int		nb_folds;
	char	**folders;
}				t_global;

# include <libft.h>
/* opendir / readdir */
#include <sys/types.h>
#include <dirent.h>

#endif
