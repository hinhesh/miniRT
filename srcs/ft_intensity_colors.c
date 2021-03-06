/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intensity_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: how-choongines <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:30:22 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 14:27:45 by how-choongi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_list	*ft_initialize_color_2(t_scene *scene
, double *t_min, t_list **min)
{
	*min = NULL;
	*t_min = -1;
	return (*(scene->list));
}

t_list	*ft_color_intensity_2(t_scene *scene, t_ray *ray, t_point *base)
{
	t_list	*tmp;
	double	t_min;
	t_list	*min;

	tmp = ft_initialize_color_2(scene, &t_min, &min);
	while (tmp != NULL)
	{
		if (tmp->type == 0 && intersection_sphere((t_sphere *)tmp->object,
				ray, base, &t_min) == 1)
			min = tmp;
		if (tmp->type == 1 && intersection_plan((t_plan *)tmp->object,
				ray, base, &t_min) == 1)
			min = tmp;
		if (tmp->type == 2 && intersection_square((t_square *)tmp->object,
				ray, base, &t_min) == 1)
			min = tmp;
		if (tmp->type == 3 && ft_intersection_triangle(
				(t_triangle *)tmp->object, ray, base, &t_min) == 1)
			min = tmp;
		if (tmp->type == 4 && ft_intersection_cylinder(
				(t_cylinder *)tmp->object, ray, base, &t_min) == 1)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_calculate_color(t_palette *color
, t_scene *scene, t_point base, t_light *tmp)
{
	double	red;
	double	green;
	double	blue;

	red = (base.rgb.r * 0.3) + (tmp->rgb.r * 0.7);
	red += (scene->amb_light.rgb.r * 0.1);
	color->rgb.r += red * (color->intensity * 0.9
			+ (scene->amb_light.ratio * 0.1));
	green = (base.rgb.g * 0.1) + (tmp->rgb.g * 0.9);
	green += (scene->amb_light.rgb.g * 0.1);
	color->rgb.g += green * (color->intensity * 0.9
			+ (scene->amb_light.ratio * 0.1));
	blue = ((base.rgb.b * 0.3) + (tmp->rgb.b * 0.7));
	blue += (scene->amb_light.rgb.b * 0.1);
	color->rgb.b += blue * (color->intensity * 0.9
			+ (scene->amb_light.ratio * 0.1));
}

static void	ft_color_intensity_3(t_palette *color
, t_scene *scene, t_point base, t_light *tmp)
{
	double	dist;
	t_coord	l;

	ft_vectors_substract(&base.pos, &tmp->pos, &l);
	dist = ft_norm2(&l);
	ft_normalize(&l);
	color->intensity += (ft_ombre(&base, dist, scene, tmp)
			* (ft_scal_produce(&l, &base.normal)
				+ ft_specular(&base, &l, *(scene->camera)))
			/ dist) * tmp->i * 1000;
	ft_calculate_color(color, scene, base, tmp);
}

double	ft_color_intensity(t_palette *color, t_scene *scene,
t_ray *ray)
{
	t_point	base;
	t_list	*obj;
	t_light	*tmp;

	obj = ft_color_intensity_2(scene, ray, &base);
	if (scene->nb_rebond != 0 && obj != NULL)
	{
		if (obj->magic == 1)
			ft_mirror(color, ray, &base, scene);
		else
		{
			tmp = *(scene->light);
			while (tmp != NULL)
			{
				ft_check_magic(obj, color);
				if (obj->type == 2 || obj->type == 3 || obj->type == 1)
					ft_color_intensity_4(color, scene, base, tmp);
				else
					ft_color_intensity_3(color, scene, base, tmp);
				tmp = tmp->next;
			}
			return (color->intensity);
		}
	}
	return (-1);
}
