/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 00:03:37 by adebray           #+#    #+#             */
/*   Updated: 2013/12/01 07:34:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#include <stdio.h>

#define LENGTH_SIZE 1400
#define HEIGHT_SIZE 900

typedef struct 	s_draw_data
{
	int 	x_start;
	int 	y_start;
	int 	z_start;
	int 	x;
	int 	y;
	int 	z;
}				t_draw_data;

//void	get_key(int keycode, void param);

int 	get_key(int keycode, void *param)
{
	param = param;
	if (keycode == 65307)
		exit(0);
	printf("%d\n", keycode);
	return (0);
}

int 	do_the_cheat(int y)
{
	y = (HEIGHT_SIZE - y);
	return (y);
}

int 	do_some_math_x(t_draw_data 	*data, int cst)
{
	int x;

	x = (data->x + data->x_start) + (cst * data->z);
	return (data->x);
}

int 	do_some_math_y(t_draw_data 	*data, int cst)
{
	data->y = data->y + (cst / 2) * data->z;
	return (data->y);
}

int 	ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i <= nb)
	{
		if(nb == i * i)
			return(i);
		i++;
	}
	return (0);
}

//void	draw_vert_line(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)

	int 	main(void)
	{
		int 	color;
		void	*init_mlx;
		void	*window_mlx;
		t_draw_data 	*matrification;
		t_draw_data 	*pix_cursor;
//		s_col_name  	*test;
//		s_mlx_col_name	*test2;

		if ((init_mlx = mlx_init()) == NULL)
			return (0);
		if ((window_mlx = mlx_new_window(init_mlx, LENGTH_SIZE, HEIGHT_SIZE, "test")) == NULL)
			return (0);
	//mlx_string_put(init_mlx, window_mlx, 200, 200, 0077077077, "Hello String");

	pix_cursor = malloc(sizeof(t_draw_data));

//	test2 = malloc(sizeof(s_mlx_col_name));


	//color = 0xffffab;
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
	// 	mlx_pixel_put(init_mlx, window_mlx, pix_cursor->x, pix_cursor->y, 0255255255);
	// 	pix_cursor->x += 1;
	// 	pix_cursor->y += 1;
	// }

	// MATRIFICATION X Y Z
	int 	cst = 0.82;
	matrification = malloc(sizeof(t_draw_data));
	matrification->x = 0;
	matrification->y = 0;
	matrification->z = 0;
	printf("matrifie : x =: %d | y =: %d | z : %d.\n", matrification->x, matrification->y, matrification->z);


	matrification->x_start = 200;
	matrification->y_start = 200;
	matrification->z_start = 200;
	matrification->x = 0;
	matrification->y = 0;
	matrification->z = 0;
	while (matrification->x < 100)
	{
		mlx_pixel_put(init_mlx, window_mlx, do_some_math_x(matrification, cst), do_some_math_y(matrification, cst), color);
		printf("01x : %d\n", do_some_math_x(matrification, cst));
		printf("01y : %d\n", do_some_math_y(matrification, cst));
		matrification->x += 1;
	}
	matrification->x = 0;
	matrification->y = 0;
	matrification->z = 0;
	matrification->x_start = 200;
	matrification->y_start = 300;
	matrification->z_start = 200;
	while (matrification->x < 100)
	{
		mlx_pixel_put(init_mlx, window_mlx, do_some_math_x(matrification, cst), (matrification->y_start + matrification->y), color);
		matrification->x += 1;
	}
	matrification->x_start = 200;
	matrification->y_start = 200;
	matrification->z_start = 200;
	matrification->x = 0;
	matrification->y = 0;
	matrification->z = 0;
	while (matrification->y < 100)
	{
		mlx_pixel_put(init_mlx, window_mlx, (matrification->x_start + matrification->x), (matrification->y_start + matrification->y), color);
		matrification->y += 1;
	}
	matrification->x_start = 300;
	matrification->y_start = 200;
	matrification->z_start = 200;
	matrification->x = 0;
	matrification->y = 0;
	matrification->z = 0;
	while (matrification->y < 100)
	{
		mlx_pixel_put(init_mlx, window_mlx, (matrification->x_start + matrification->x), (matrification->y_start + matrification->y), color);
		matrification->y += 1;
	}

//	matrification->x = 0.7071 * (matrification->x - matrification->y);
//	matrification->y = 0.8164 * matrification->z - 0.4082 * (matrification->x + matrification->y);
	printf("matrifie : x =: %d | y =: %d | z : %d.\n", matrification->x, matrification->y, matrification->z);

	// // HORITONZALE MULTI-LINEAGE
	// color = 0xff00ff;
	// pix_cursor->x_start = 250;
	// pix_cursor->x = 0;
	// while (pix_cursor->x <= 256)
	// {
	// 	pix_cursor->y_start = 250;
	// 	pix_cursor->y = 0;
	// 	while (pix_cursor->y <= 256)
	// 	{
	// 		mlx_pixel_put(init_mlx, window_mlx, (pix_cursor->x_start + pix_cursor->x), (pix_cursor->y_start + pix_cursor->y), color);
	// 		// printf("y + y_start : %d\n", (pix_cursor->y_start + pix_cursor->y));
	// 		// printf("x + x_start : %d\n", (pix_cursor->x_start + pix_cursor->x));
	// 		pix_cursor->y += 32;
	// 	}
	// 	pix_cursor->x += 10;
	// }

	// // VERTICALE MULTI-LINEAGE
	// color = 0xffff00;
	// pix_cursor->x_start = 250;
	// pix_cursor->x = 0;
	// while (pix_cursor->x <= 256)
	// {
	// 	pix_cursor->y_start = 250;
	// 	pix_cursor->y = 0;
	// 	while (pix_cursor->y <= 256)
	// 	{
	// 		mlx_pixel_put(init_mlx, window_mlx, (pix_cursor->x_start + pix_cursor->x), (pix_cursor->y_start + pix_cursor->y), color);
	// 		// printf("y + y_start : %d\n", (pix_cursor->y_start + pix_cursor->y));
	// 		// printf("x + x_start : %d\n", (pix_cursor->x_start + pix_cursor->x));
	// 		pix_cursor->y += 10;
	// 	}
	// 	pix_cursor->x += 32;
	// }

	mlx_key_hook (window_mlx, &get_key, NULL);
	mlx_loop (init_mlx);
	return (0);
}
