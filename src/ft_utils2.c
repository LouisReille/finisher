/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:49 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 23:09:10 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_color	r_g_b(char *r, char *g, char *b)
{
	t_color	extr;

	extr.r = ft_atod(r);
	extr.g = ft_atod(g);
	extr.b = ft_atod(b);
	return (extr);
}

t_color	make_number(double nb)
{
	t_color	result;

	result.r = nb;
	result.g = nb;
	result.b = nb;
	return (result);
}

t_vector	x_y_z(char *x, char *y, char *z)
{
	t_vector	extr;

	extr.x = ft_atod(x);
	extr.y = ft_atod(y);
	extr.z = ft_atod(z);
	return (extr);
}

static void	free_light(t_item *data)
{
	t_light	*tmp_l;

	while (data->light != NULL)
	{
		tmp_l = data->light->next;
		free(data->light);
		data->light = NULL;
		data->light = tmp_l;
	}
}

int	free_exit(t_item *data)
{
	t_objet		*tmp_o;
	t_camera	*tmp_c;

	while (data->objet != NULL)
	{
		tmp_o = data->objet->next;
		free(data->objet);
		data->objet = NULL;
		data->objet = tmp_o;
	}
	while (data->camera != NULL)
	{
		tmp_c = data->camera->next;
		free(data->camera);
		data->camera = NULL;
		data->camera = tmp_c;
	}
	free_light(data);
	exit(1);
}
