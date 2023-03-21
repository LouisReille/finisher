/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:13:44 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 21:55:55 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	ft_mlx1(t_item *data)
{
	int	endian;

	data->mlx.mlx_ptr = mlx_init();
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr,
			data->rsl.width, data->rsl.height);
	data->mlx.img_data = (int *)mlx_get_data_addr(data->mlx.img_ptr,
			&data->mlx.bpp, &data->mlx.size_line, &endian);
}

void	ft_mlx2(t_item *data)
{
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			data->rsl.width, data->rsl.height, "MicroRayTracing");
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img_ptr, 0, 0);
	mlx_hook(data->mlx.win_ptr, 2, 0, ft_key_press, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, ft_close, data);
	mlx_loop(data->mlx.mlx_ptr);
}
