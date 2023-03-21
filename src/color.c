/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:11:59 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 20:39:06 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

t_color	color_create(t_color v1)
{
	t_color	result;

	result.r = v1.r;
	result.g = v1.g;
	result.b = v1.b;
	return (result);
}

t_color	color_add(t_color v1, t_color v2)
{
	t_color	result;

	result.r = v1.r + v2.r;
	result.g = v1.g + v2.g;
	result.b = v1.b + v2.b;
	return (result);
}

t_color	color_scal(double nb, t_color rgb)
{
	t_color	result;

	result.r = rgb.r * nb;
	result.g = rgb.g * nb;
	result.b = rgb.b * nb;
	return (result);
}

t_color	color_prd(t_color col1, t_color col2)
{
	t_color	result;

	result.r = col1.r * col2.r;
	result.g = col1.g * col2.g;
	result.b = col1.b * col2.b;
	return (result);
}

t_color	min_max(t_color rgb)
{
	t_color	result;

	result.r = min(255, max(0, rgb.r));
	result.g = min(255, max(0, rgb.g));
	result.b = min(255, max(0, rgb.b));
	return (result);
}
