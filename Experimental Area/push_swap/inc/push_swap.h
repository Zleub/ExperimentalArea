/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 04:36:24 by adebray           #+#    #+#             */
/*   Updated: 2013/12/26 06:50:58 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA str[0] == 's' && str[1] == 'a' && str[2] == '\0'
# define SB str[0] == 's' && str[1] == 'b' && str[2] == '\0'
# define SS str[0] == 's' && str[1] == 's' && str[2] == '\0'
# define PA str[0] == 'p' && str[1] == 'a' && str[2] == '\0'
# define PB str[0] == 'p' && str[1] == 'b' && str[2] == '\0'
# define RA str[0] == 'r' && str[1] == 'a' && str[2] == '\0'
# define RB str[0] == 'r' && str[1] == 'b' && str[2] == '\0'
# define RR str[0] == 'r' && str[1] == 'r' && str[2] == '\0'
# define RRA str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\0'
# define RRB str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\0'
# define RRR str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\0'
# define LA str[0] == 'l' && str[1] == 'a' && str[2] == '\0'
# define LB str[0] == 'l' && str[1] == 'b' && str[2] == '\0'
# define LL str[0] == 'l' && str[1] == 'l' && str[2] == '\0'


# include <stdlib.h>
# include <ft_printf.h>

typedef struct			s_list
{
	int					data;
	struct s_list		*next;
}						t_list;

typedef struct			s_this_is_glob_stuct
{
	int					i;
	int					max;
	t_list				**l_a;
	t_list				**l_b;
}						t_vars;

t_list					*ft_initshackle(void);
t_vars					*ft_initvars(void);
void					ft_buildlist(t_vars *vars, int argc, char **argv);
void					ft_printargv(int argc, char **argv);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_printshackle(t_list *shackle);
char					*ft_some_option(t_vars *vars, char **argv);
void					ft_interactive(t_vars *vars, char *str);
void					ft_isswap(t_vars *vars, char *str);
void					ft_ispush(t_vars *vars, char *str);
void					ft_isreverse(t_vars *vars, char *str);
void					ft_isrreverse(t_vars *vars, char *str);
void					ft_isprint(t_vars *vars, char *str);
void					ft_dumplist(t_list **head);
void					ft_print_la(t_vars *vars);
void					ft_print_lb(t_vars *vars);
void					ft_sa(t_vars *vars);
void					ft_sb(t_vars *vars);
void					ft_ss(t_vars *vars);
void					ft_pb(t_vars *vars);
void					ft_pa(t_vars *vars);
void					ft_ra(t_vars *vars);
void					ft_rb(t_vars *vars);
void					ft_rr(t_vars *vars);
void					ft_rra(t_vars *vars);
void					ft_rrb(t_vars *vars);
void					ft_rrr(t_vars *vars);

#endif
