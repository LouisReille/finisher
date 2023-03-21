/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:49:25 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 21:37:29 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	witch_object(t_objet *objet, t_ray *ray, double *cross)
{
	if (objet->data == SPH)
		*cross = hit_sphere(objet, ray);
	else if (objet->data == PLA)
		*cross = hit_plane(objet, ray);
	else if (objet->data == CYL)
		*cross = hit_cylinder(objet, ray);
}

t_color	make_rrange(int rgb)
{
	t_color	result;

	result.r = rgb / 255;
	result.g = rgb / 255;
	result.b = rgb / 255;
	return (result);
}

double	max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}

double	min(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	merge(t_color *data)
{
	return ((data->r * 256 * 256) + (data->g * 256) + data->b);
}
