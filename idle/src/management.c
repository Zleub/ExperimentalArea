/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 05:49:59 by adebray           #+#    #+#             */
/*   Updated: 2014/01/28 15:13:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>


char					*trim_save(char *save_name)
{
	int					i;

	i = ft_strlen(save_name);
	while (save_name[i] != '.')
	{
		save_name[i] = '\0';
		i = i - 1;
	}
	save_name[i] = '\0';
	return (save_name);
}

char					*get_name(void)
{
	int					i;
	char				*str;

	write(1, "Enter name : ", 13);
	get_next_line(0, &str);
	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i = i + 1;
	}
	return (str);
}

int						get_rand(int modulo)
{
	int					fd;
	unsigned char		*test;
	int					tmp;

	test = ft_memalloc(1);
	fd = open("/dev/urandom", O_RDONLY);
	read(fd, test, 1);
	tmp = test[0] % modulo;
	close(fd);
	free(test);
	return (tmp);
}

t_heros					*create_monster(void)
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
		str_array = malloc(sizeof(char*) * 25);
		fd = open("./res/monsters.txt", O_RDONLY);
		while (get_next_line(fd, &str_array[i]) > 0)
			i = i + 1;
		close(fd);
	}
	ft_printf("TEST\n");
	ft_printf("1.errno : %d\n", errno);
	monster = malloc(sizeof(t_heros));
	ft_printf("2.errno : %d\n", errno);
	monster->name = str_array[get_rand(20)];
	ft_printf("3.errno : %d\n", errno);
	hash = hashich(monster->name);
	ft_printf("4.errno : %d\n", errno);
	monster->strengh = hash % 21;
	ft_printf("5.errno : %d\n", errno);
	monster->defense = hash / 21 % 21;
	ft_printf("6.errno : %d\n", errno);
	return (monster);
}
