/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 10:19:11 by adebray           #+#    #+#             */
/*   Updated: 2013/12/28 12:33:13 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_1_H
# define MINISHELL_1_H

typedef struct			s_binlist
{
	char				*name;
	struct s_binlist	*next;
}						t_binlist;

typedef struct			s_vars
{
	t_binlist			*binlist;
}						t_vars;

#endif
