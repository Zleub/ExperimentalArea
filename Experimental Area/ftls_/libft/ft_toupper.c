/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2013/12/03 00:09:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_toupper(int c)
{
	if (96 < c && c < 123)
	{
		c = c - 32;
		return (c);
	}
	return (c);
}