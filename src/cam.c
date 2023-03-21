/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:50:23 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 20:31:12 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	half_w_h(t_item *d)
{
	double	theta;
	double	ratio;

	theta = d->camera->fov * M_PI / 180;
	ratio = (double)d->rsl.width / (double)d->rsl.height;
	d->rsl.half_height = 2 * tan(theta / 2);
	d->rsl.half_width = ratio * d->rsl.half_height;
}

void	calcul_pixel(t_item *d)
{
	double		x;
	double		y;
	t_vector	pixel_x;
	t_vector	pixel_y;
	t_vector	pixel;

	x = (d->rsl.x + 0.5) * d->rsl.half_width / (double)d->rsl.width;
	y = (d->rsl.y + 0.5) * d->rsl.half_height / (double)d->rsl.height;
	pixel_x = vector_scal(x, d->camera->u);
	pixel_y = vector_scal(y, d->camera->v);
	pixel = vector_add(pixel_x, pixel_y);
	pixel = vector_sub(d->camera->l, pixel);
	d->camera->pixel = pixel;
}

void	mapper_pixel(t_item *d)
{
	t_vector	center;
	t_vector	l;

	center = vector_sub(d->camera->pos, d->camera->n);
	l.x = d->camera->u.x * d->rsl.half_width / 2 \
		+ d->camera->v.x * d->rsl.half_height / 2;
	l.y = d->camera->u.y * d->rsl.half_width / 2 \
		+ d->camera->v.y * d->rsl.half_height / 2;
	l.z = d->camera->u.z * d->rsl.half_width / 2 \
		+ d->camera->v.z * d->rsl.half_height / 2;
	d->camera->l = vector_add(center, l);
}

void	camera_setting(t_item *d)
{
	t_vector	vup;

	vup = make_pos(0, 1, 0);
	if (d->camera->ort_vec.y != 0 && (d->camera->ort_vec.z == 0 && \
		d->camera->ort_vec.x == 0))
		vup = make_pos(0, 0, 1);
	half_w_h(d);
	d->camera->n = vector_scal(-1, d->camera->ort_vec);
	d->camera->n = unit_vector(d->camera->n);
	d->camera->u = vector_cross(vup, d->camera->n);
	d->camera->u = unit_vector(d->camera->u);
	d->camera->v = vector_cross(d->camera->n, d->camera->u);
	mapper_pixel(d);
}

void	ray(t_item *d)
{
	calcul_pixel(d);
	d->ray.origin = d->camera->pos;
	d->ray.direction = vector_sub(d->camera->pixel, d->ray.origin);
	d->ray.direction = unit_vector(d->ray.direction);
}
