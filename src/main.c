/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:56:14 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 21:13:03 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_color	ft_color(t_item *data)
{
	double		t1;
	t_objet		*tmp;
	t_color		black;
	t_color		render_s;
	t_color		shadow1;

	t1 = FLT_MAX;
	tmp = data->objet;
	black = make_number(0);
	hit_objet(data, &t1);
	if (data->tool.intersect == 1)
	{
		shadow1 = shadows(data, tmp);
		render_s = render(data, shadow1);
		data->objet = tmp;
		return (render_s);
	}
	else
		return (black);
}

void	ft_minirt(t_item *data)
{
	int			i;
	t_color		color;

	i = 0;
	data->rsl.x = 0;
	data->rsl.y = 0;
	camera_setting(data);
	while (data->rsl.y < data->rsl.height)
	{
		data->rsl.x = 0;
		while (data->rsl.x < data->rsl.width)
		{
			ray(data);
			color = ft_color(data);
			data->color.r = (int)color.r;
			data->color.g = (int)color.g;
			data->color.b = (int)color.b;
			data->mlx.img_data[i] = merge(&data->color);
			data->rsl.x++;
			i++;
		}
		data->rsl.y++;
	}
}

int	ft_key_press(int keycode, t_item *data)
{
	if (keycode == 53)
		free_exit(data);
	return (0);
}

void	ft_init_resolution(t_item *data)
{
	int	a;
	int	b;

	mlx_get_screen_size(data->mlx.mlx_ptr, &a, &b);
	data->rsl.width = RX;
	data->rsl.height = RY;
	data->parsing.r = 1;
}

int	main(int argc, char **argv)
{
	t_item	data;

	ft_bzero(&data, sizeof(t_item));
	data.nb_cam = 0;
	data.nb_amb = 0;
	data.nb_spt = 0;
	parsing(&data, argv, argc);
	ft_mlx1(&data);
	ft_minirt(&data);
	ft_mlx2(&data);
	return (0);
}
