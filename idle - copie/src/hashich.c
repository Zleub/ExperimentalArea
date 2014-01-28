/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashich.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:44:00 by nsierra           #+#    #+#             */
/*   Updated: 2013/12/17 00:03:09 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		hashich(char *line)
{
	unsigned int	hashich;
	int				c;

	hashich = 5381;
	while ((c = *line++))
		hashich = ((hashich << 5) + hashich) ^ c;
	return (hashich);
}
