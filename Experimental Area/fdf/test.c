/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:14 by adebray           #+#    #+#             */
/*   Updated: 2013/11/29 08:15:32 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#include <stdio.h>

//void	get_key(int keycode, void param);

int 	get_key(keycode, param)
{
	if (keycode == 65307)
		exit(0);
	printf("%d\n", keycode);
	return (0);
}

	typedef struct 	s_draw_data
	{
		int 	x_start;
		int 	y_start;
		int 	x;
		int 	y;
	}				t_draw_data;

//void	draw_vert_line(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)

	int 	main(void)
	{
		int 	color;
		void	*init_mlx;
		void	*window_mlx;
		void	*deadzone;
		t_draw_data 	*pix_cursor;
//		s_col_name  	*test;
//		s_mlx_col_name	*test2;

		if ((init_mlx = mlx_init()) == NULL)
			return (0);
		if ((window_mlx = mlx_new_window(init_mlx, 1400, 900, "test")) == NULL)
			return (0);
	//mlx_string_put(init_mlx, window_mlx, 200, 200, 0077077077, "Hello String");

	pix_cursor = malloc(sizeof(t_draw_data));

//	test2 = malloc(sizeof(s_mlx_col_name));


	color = 0xffffab;
	// color = color >> 16;
	// printf("%x\n", color & 0xffffff);

	// color = 0xffffab;
	// color = color >> 8;
	// printf("%x\n", color & 0xffff);

	// color = 0xffffab;
	// color = color;
	// printf("%x\n", color & 0xff);

	// LINEAGE
	// while (pix_cursor->x < 250 || pix_cursor->y < 250)
	// {
	// 	mlx_pixel_put(init_mlx, window_mlx, pix_cursor->x, pix_cursor->y, \
	// 					0255255255);
	// 	pix_cursor->x += 1;
	// 	pix_cursor->y += 1;
	// }

	// HORITONZALE MULTI-LINEAGE
	color = 0xffffab;
	pix_cursor->x_start = 50;
	pix_cursor->x = 0;
	while (pix_cursor->x < 112)
	{
		pix_cursor->y_start = 50;
		pix_cursor->y = 0;
		while (pix_cursor->y < 112)
		{
			mlx_pixel_put(init_mlx, window_mlx, (pix_cursor->x_start + pix_cursor->x), (pix_cursor->y_start + pix_cursor->y), color);
			// printf("y + y_start : %d\n", (pix_cursor->y_start + pix_cursor->y));
			// printf("x + x_start : %d\n", (pix_cursor->x_start + pix_cursor->x));
			color += 0xa;
			pix_cursor->y += 16;
		}
		pix_cursor->x += 1;
	}

	// VERTICALE MULTI-LINEAGE
	color = 0xffffab;
	pix_cursor->x_start = 50;
	pix_cursor->x = 0;
	while (pix_cursor->x < 112)
	{
		pix_cursor->y_start = 50;
		pix_cursor->y = 0;
		while (pix_cursor->y < 112)
		{
			mlx_pixel_put(init_mlx, window_mlx, (pix_cursor->x_start + pix_cursor->x), (pix_cursor->y_start + pix_cursor->y), color);
			// printf("y + y_start : %d\n", (pix_cursor->y_start + pix_cursor->y));
			// printf("x + x_start : %d\n", (pix_cursor->x_start + pix_cursor->x));
			color += 0xa;
			pix_cursor->y += 1;
		}
		pix_cursor->x += 16;
	}

	// VERTICALE MULTI-LINEAGE
	// pix_cursor->x_start = 50;
	// pix_cursor->x = 0;
	// while (pix_cursor->x < 513)
	// {
	// 	pix_cursor->y_start = 50;
	// 	pix_cursor->y = 0;
	// 	while (pix_cursor->y < 513)
	// 	{
	// 		mlx_pixel_put(init_mlx, window_mlx, (pix_cursor->x_start + pix_cursor->x), (pix_cursor->y_start + pix_cursor->y), color);
	// 		// printf("x + x_start : %d\n", (pix_cursor->x_start + pix_cursor->x));
	// 		// printf("y + y_start : %d\n", (pix_cursor->y_start + pix_cursor->y));
	// 		pix_cursor->y += 1;
	// 	}
	// 	pix_cursor->x += 16;
	// }

	mlx_key_hook (window_mlx, &get_key, NULL);
	mlx_loop (init_mlx);
	return (0);
}
