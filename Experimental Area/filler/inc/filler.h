/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/01/26 01:10:08 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <ft_printf.h>
# include <gnl.h>
# include <libft.h>

# define ARRAY_CHAR array[cmp_array[2]][cmp_array[3]]
# define PIECE_CHAR piece[cmp_array[0]][cmp_array[1]]


typedef struct		s_gnl
{
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_dual
{
	int				*size;
	int				*piece;
}					t_dual;

typedef struct		s_result
{
	int				x;
	int				y;
	struct s_result	*next;
}					t_result;

t_gnl	*create(void);
int		*get_dual(t_gnl *head);
char	**get_piece(int *piece_size);
char	**get_plat(int *plateau_size);
int		*get_first(char **plateau);
int		*get_second(char **plateau, int *size);
int		*get_more(int *first_dual, char** plateau);
int		*get_less(int *first_dual, int *second_dual, int *size, char **plateau);
int		*get_insc(t_dual *dual, char **plateau);
char	**get_array(int *rectangle, char **plateau);
int		make_move(char **piece, char **array, int x, int y);
void	free_array(char **array);
void	give_answer(t_result *head, t_dual *duo, int *coor, int nbr);

#endif
