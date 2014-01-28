/* *************************************************************************** */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   ft_fibonacci.c                                      :+:      :+:    :+:   */
/*                                                     +:+ +:+         +:+     */
/*   By: adebray <debray.arnaud@gmail.com>           +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/22 12:40:15 by adebray            #+#    #+#             */
/*   Updated: 2013/07/22 19:48:53 by adebray           ###   ########.fr       */
/*                                                                             */
/* *************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index > 46)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
