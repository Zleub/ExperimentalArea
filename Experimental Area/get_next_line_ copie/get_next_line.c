

#include "get_next_line.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*tmp;
	char	*ptr;

	if (s1 != NULL && s2 != NULL)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
		if (!s2)
			return (NULL);
		ptr = tmp;
		while (*s1)
			*tmp++ = *s1++;
		while (n--)
			*tmp++ = *s2++;
		*tmp = '\0';
		return (ptr);
	}
	return (NULL);
}

int 		get_next_line(int const fd, char **line)
{
	static char	*array;
	char		*buffer;
	int 		check_up;
	int 		i;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if(!array)
		array = malloc(sizeof(char));
	check_up = read(fd, buffer, BUFF_SIZE);
	if (check_up == 0 && !array)
		return (0);
	i = 0;
	while (buffer[i] != '\n' && i <= BUFF_SIZE)
		i = i + 1;
	if (i == BUFF_SIZE + 1)
	{
		if (!array)
			array = ft_strsub(buffer, 0, BUFF_SIZE);
		else
			array = ft_strjoin(array, buffer);
		get_next_line(fd, line);
	}
	else
		array = ft_strnjoin(array, buffer, i);
	*line = array;
	free(buffer);
	return (1);
}
