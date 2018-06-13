/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:57:39 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/14 18:19:30 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env	*ft_add_pix(t_env *env, t_rgb clri, t_rgb clrf, double rat)
{
	long	j;

	j = 0;
	if (env->seg.x >= 0 && env->seg.y >= 0 && env->seg.x < WIDTH && env->seg.y \
		< LENGTH)
	{
		j = (WIDTH * env->seg.y + env->seg.x) * 4;
		env->image[j] = clri.blue + rat * (clrf.blue - clri.blue);
		env->image[j + 1] = clri.green + rat * (clrf.green - clri.green);
		env->image[j + 2] = clri.red + rat * (clrf.red - clri.red);
	}
	return (env);
}

t_env	*ft_clear_image(t_env *env)
{
	int		i;

	i = 0;
	while (i < (WIDTH * LENGTH * 4))
	{
		env->image[i] = 0;
		i++;
	}
	return (env);
}
