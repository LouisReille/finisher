/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:41:35 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 22:01:07 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	sphere_p_n(t_item *data)
{
	t_vector	produit;

	produit = vector_scal(data->objet->t, data->ray.direction);
	data->objet->point = vector_add(data->ray.origin, produit);
	data->objet->normal = vector_sub(data->objet->point, data->objet->pos);
	data->objet->normal = unit_vector(data->objet->normal);
}

void	plane_p_n(t_item *data)
{
	double		a;
	t_vector	produit;

	a = vector_dot(data->ray.direction, data->objet->v);
	produit = vector_scal(data->objet->t, data->ray.direction);
	data->objet->point = vector_add(data->ray.origin, produit);
	data->objet->normal = data->objet->v;
	if (a > 0)
		data->objet->normal = vector_scal(-1, data->objet->normal);
}

void	cylinder_p_n(t_item *data)
{
	double		m;
	t_vector	x;
	t_vector	sub;
	t_vector	scal;
	t_vector	produit;

	data->objet->v = unit_vector(data->objet->v);
	produit = vector_scal(data->objet->t, data->ray.direction);
	data->objet->point = vector_add(data->ray.origin, produit);
	x = vector_sub(data->ray.origin, data->objet->pos);
	m = vector_dot(data->ray.direction, data->objet->v)
		* data->objet->t + vector_dot(x, data->objet->v);
	sub = vector_sub(data->objet->point, data->objet->pos);
	scal = vector_scal(m, data->objet->v);
	data->objet->normal = vector_sub(sub, scal);
	if (vector_dot(data->ray.direction, data->objet->normal) > 0.000)
		data->objet->normal = vector_scal(-1, data->objet->normal);
	data->objet->normal = unit_vector(data->objet->normal);
}

void	calcul_delta_cy(t_objet *objet, t_ray *ray, t_varcal *var)
{
	var->oc = vector_sub(ray->origin, objet->pos);
	var->a = vector_dot(ray->direction, ray->direction)
		- (vector_dot(ray->direction, objet->v)
			* vector_dot(ray->direction, objet->v));
	var->b = 2 * (vector_dot(ray->direction, var->oc)
			- (vector_dot(ray->direction, objet->v)
				* vector_dot(var->oc, objet->v)));
	var->c = vector_dot(var->oc, var->oc)
		- (vector_dot(var->oc, objet->v) * vector_dot(var->oc, objet->v))
		- (objet->radius * objet->radius);
	var->delta = var->b * var->b - 4 * var->a * var->c;
}
