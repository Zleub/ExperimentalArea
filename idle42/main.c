/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:25:00 by adebray           #+#    #+#             */
/*   Updated: 2013/12/19 03:08:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>
#include <gnl.h>
#include <libft.h>

int					ft_chest_0(void)
{
	char			**prout;
	int				i;
	int				fd;

	i = -1;
	prout = malloc(sizeof(char*) * 25);
	while (++i < 25)
		prout[i] = NULL;
	fd = open("./res/monsters.txt", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &prout[i]))
		i = i + 1;
	prout[i] = NULL;
	while(*prout)
		ft_putendl(*prout++);
	close (fd);
	return (0);
}

void				new_game(void)
{
	char			*str;
	unsigned int	hash;
	int				fd;
	int				i;

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

void	print_heros(t_heros *heros)
{
	ft_putendl(heros->name);
	ft_putstr("Has ");
	ft_putnbr(heros->strengh);
	ft_putendl(" strengh");
	ft_putstr("Has ");
	ft_putnbr(heros->defense);
	ft_putendl(" defense");
}

char	*trim_save(char *save_name)
{
	int		i;

	i = ft_strlen(save_name);
	while (save_name[i] != '.')
	{
		save_name[i] = '\0';
		i = i - 1;
	}
	save_name[i] = '\0';
	return (save_name);
}

t_heros				*load_game(t_heros *heros)
{
	char			*str;
	int				i;
	int				fd;

	if(!heros)
	{
		heros = malloc(sizeof(t_heros));
		write(1, "Enter name : ", 13);
		get_next_line(0, &str);
		i = 0;
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			i = i + 1;
		}
		fd = open(ft_strcat(str, ".sav"), O_RDONLY);
		free(str);
		get_next_line(fd, &str);
		heros->name = ft_strdup(trim_save(str));
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
	return (heros);
}

int					get_rand(int modulo)
{
	int				fd;
	unsigned char	*test;
	int				tmp;

	test = ft_memalloc(1);
	fd = open("/dev/urandom", O_RDONLY);
	read(fd, test, 1);
	// if (test[0] < 0)
	// 	test[0] *= -1;
	tmp = test[0] % modulo;
	close(fd);
	free(test);
	return (tmp);
}

#include <stdio.h>

t_heros				*create_monster(void)
{
	t_heros				*monster;
	static char			**str_array;
	int					fd;
	int					i;
	unsigned int		hash;

	i = 0;
	monster = NULL;
	if(!str_array)
	{
		str_array = malloc(sizeof(char*) * 21);
		fd = open("./res/monsters.txt", O_RDONLY);
		while (get_next_line(fd, &str_array[i]) > 0)
			i = i + 1;
		close(fd);
	}
	monster = malloc(sizeof(t_heros));
	monster->name = str_array[get_rand(20)];
	hash = hashich(monster->name);
	monster->strengh = hash % 21;
	monster->defense = hash / 21 % 21;
	return (monster);
}

// void				playing(t_heros)
// {
// 	create_monster
// }

int							menu()
{
	char					*str;
	static t_heros			*heros;

	str = NULL;
	write(1, "Hello\n", 6);
	write(1, "(N)ew game\n", 12);
	write(1, "(L)oad game\n", 13);
	write(1, "(R)egles\n", 9);
	write(1, "(E)xit\n", 8);
	get_next_line(0, &str);
	if (str[0] == 'N' || str[0] == 'n')
		new_game();
	if (str[0] == 'L' || str[0] == 'l')
	{
		heros = load_game(heros);
		ft_putendl("Playing with : ");
		print_heros(heros);
		print_heros(create_monster());
		write(1, "done", 4);
	}
//	if (str[0] == 'R' || str[0] == 'r')
//		write_file("");
	if (str[0] == 'E' || str[0] == 'e')
		return (0);
	write(1, "\n", 1);
	menu();
	return (0);
}

int							main(void)
{
	return (menu());
}
