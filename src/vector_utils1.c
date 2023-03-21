/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:40:18 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 20:44:55 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

double	vector_length(t_vector v)
{
	double	result;

	result = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return (result);
}

t_vector	unit_vector(t_vector v)
{
	t_vector	result;

	result.x = v.x / vector_length(v);
	result.y = v.y / vector_length(v);
	result.z = v.z / vector_length(v);
	return (result);
}

t_vector	vector_cross(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_color	make_range(t_color rgb)
{
	t_color	result;

	result.r = rgb.r / 255;
	result.g = rgb.g / 255;
	result.b = rgb.b / 255;
	return (result);
}

t_vector	make_pos(double x, double y, double z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
