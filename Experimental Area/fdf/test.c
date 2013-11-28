/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 06:36:45 by adebray           #+#    #+#             */
/*   Updated: 2013/11/28 10:25:37 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>



int 	main(void)
{
	void	*init_mlx;
	void	*window_mlx;
	int 	ret_chelou;

	if ((init_mlx = mlx_init()) == NULL)
		return (0);
	if ((window_mlx = mlx_new_window(init_mlx, 1400, 900, "test")) == NULL)
		return (0);
	ret_chelou = mlx_string_put(init_mlx, window_mlx, 200, 200, \
								0077077077, "Hello String");
	ret_chelou = mlx_string_put(init_mlx, window_mlx, 200, 250, \
								0077077077, "Hello String");
	ret_chelou = mlx_string_put(init_mlx, window_mlx, 250, 200, \
								0077077077, "Hello String");
	ret_chelou = mlx_string_put(init_mlx, window_mlx, 250, 250, \
								0077077077, "Hello String");

	mlx_loop(init_mlx);
//	mlx_loop_hook (init_mlx+, int (*funct_ptr)(), void *param )
	return (0);
}
