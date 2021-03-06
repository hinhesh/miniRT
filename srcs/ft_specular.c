/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specular.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: how-choongines <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:03:39 by how-choongi       #+#    #+#             */
/*   Updated: 2021/04/07 19:03:39 by how-choongi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_ray_reflect(t_coord *normal, t_coord *light, t_coord *reflect)
{
	double	coeff;

	coeff = ft_scal_produce(normal, light) * 2;
	ft_vectors_mult(normal, coeff, reflect);
	ft_vectors_substract(light, reflect, reflect);
}

double	ft_specular(t_point *base, t_coord *light, t_camera *cam)
{
	t_coord	reflect;
	t_coord	v;
	double	specular;

	ft_vectors_mult(light, -1, light);
	ft_ray_reflect(&base->normal, light, &reflect);
	ft_vectors_substract(&cam->ray.origin, &base->pos, &v);
	ft_normalize(&reflect);
	ft_normalize(&v);
	specular = ft_scal_produce(&v, &reflect);
	ft_vectors_mult(light, -1, light);
	if (specular > 0)
	{
		specular = pow(specular, 2);
		return (specular);
	}
	return (0);
}
