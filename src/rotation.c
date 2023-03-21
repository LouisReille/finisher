/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:51:13 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 20:50:37 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_vector	convert_to_radian(t_vector angle)
{
	angle.x = angle.x * (3.1416 / 180);
	angle.y = angle.y * (3.1416 / 180);
	angle.z = angle.z * (3.1416 / 180);
	return (angle);
}

t_vector	rot_vector(t_vector vect_ort, t_vector angle)
{
	t_vector	vect;

	vect = vect_ort;
	angle = convert_to_radian(angle);
	vect_ort.y = vect.y * cos(angle.x) - vect.z * sin(angle.x);
	vect_ort.z = vect.y * sin(angle.x) + vect.z * cos(angle.x);
	vect = vect_ort;
	vect_ort.z = vect.z * cos(angle.y) - vect.x * sin(angle.y);
	vect_ort.x = vect.z * sin(angle.y) + vect.x * cos(angle.y);
	vect = vect_ort;
	vect_ort.x = vect.x * cos(angle.z) - vect.y * sin(angle.z);
	vect_ort.y = vect.x * sin(angle.z) + vect.y * cos(angle.z);
	vect_ort = unit_vector(vect_ort);
	return (vect_ort);
}
