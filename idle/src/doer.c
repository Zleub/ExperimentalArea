/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 06:06:31 by adebray           #+#    #+#             */
/*   Updated: 2013/12/19 06:42:34 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <idle.h>
#include <gnl.h>
#include <libft.h>

int						playing(t_heros *heros, int h_life, int m_life)
{
	t_heros				*monster;
	int					damage;
	int					i;

	monster = create_monster();
	i = 1;
	while (h_life > 0 && m_life > 0)
	{
		damage = heros->strengh - (monster->defense / 2);
		if (damage < 0)
			damage = 0;
		m_life -= damage;
		damage = monster->strengh - (heros->defense / 2);
		if (damage < 0)
			damage = 0;
		h_life -= damage;
		give_info(heros, monster, i, h_life, m_life);
		i += 1;
		sleep(1);
	}
	free(monster);
	if (h_life > 0)
		return (1);
	return (0);
}
