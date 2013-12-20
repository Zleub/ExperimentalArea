/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/19 07:14:50 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>
#include <gnl.h>
#include <libft.h>

void					new_game(void)
{
	char				*str;
	unsigned int		hash;
	int					fd;
	int					i;

	write(1, "Enter name : ", 13);
	get_next_line(0, &str);
	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i = i + 1;
	}
	hash = hashich(str);
	fd = open(ft_strcat(str, ".sav"), O_WRONLY|O_CREAT, 00760);
	ft_putendl_fd(str, fd);
	free(str);
	str = ft_itoa(hash % 21);
	ft_putendl_fd(str, fd);
	free(str);
	str = ft_itoa((hash / 21) % 21);
	ft_putendl_fd(str, fd);
	close(fd);
	free(str);
}

t_heros					*load_heros(t_heros *heros)
{
	char				*str;
	int					fd;

	if (heros)
	{
		free(heros->name);
	//	free(heros->strengh);
	//	free(heros->defense);
		free(heros);
	}
	ft_putendl("prout");
	heros = malloc(sizeof(t_heros));
	str = get_name();
	fd = open(ft_strcat(str, ".sav"), O_RDONLY);
	ft_putendl("002");
	free(str);
	get_next_line(fd, &str);
	heros->name = ft_strdup(trim_save(str));
	ft_putendl("003");
	free(str);
	get_next_line(fd, &str);
	heros->strengh = ft_atoi(str);
	free(str);
	get_next_line(fd, &str);
	heros->defense = ft_atoi(str);
	free(str);
	close(fd);
	return (heros);
}

t_heros					*load_game(t_heros *heros)
{
	int					vic;
	int					cmp;

	cmp = 0;
	vic = 0;
	while ((cmp = playing(heros, 20, 20)))
	{
		vic += cmp;
		ft_putstr("Victoires : ");
		ft_putnbr(vic);
		ft_putendl(NULL);
		ft_putendl(NULL);
	}
	ft_putstr("You died and made ");
	ft_putnbr(vic);
	ft_putendl(" victories.");
	return (heros);
}

int						menu(void)
{
	static t_heros		*heros;
	char				*str;

	str = NULL;
	write(1, "Hello\n", 6);
	write(1, "(N)ew game\n", 12);
	if (heros)
		write(1, "(P)lay game\n", 13);
	write(1, "(L)oad heros\n", 13);
	// write(1, "(R)egles\n", 9);
	write(1, "(E)xit\n", 8);
	get_next_line(0, &str);
	if (str[0] == 'N' || str[0] == 'n')
		new_game();
	if (str[0] == 'P' || str[0] == 'p')
		heros = load_game(heros);
	if (str[0] == 'L' || str[0] == 'l')
		heros = load_heros(heros);
//	if (str[0] == 'R' || str[0] == 'r')
//		load_file("");
	if (str[0] == 'E' || str[0] == 'e')
		return (0);
	write(1, "\n", 1);
	menu();
	return (0);
}

int						main(void)
{
	return (menu());
}
