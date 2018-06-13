/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:39:51 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/09 15:01:01 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_rgb		ft_get_color(int high)
{
	t_rgb	pix;

	if (high * 5 > 0)
	{
		pix.red = 255;
		pix.blue = high * 5 > 255 ? 0 : 255 - high * 5;
		pix.green = pix.blue;
	}
	else if (high * 5 < 0)
	{
		pix.blue = 255;
		pix.red = high * 5 < -255 ? 0 : 255 + high * 5;
		pix.green = pix.red;
	}
	else
	{
		pix.red = 255;
		pix.blue = 255;
		pix.green = 255;
	}
	return (pix);
}

t_pts		*ft_fill_pos(t_dot *list, t_pts *lst)
{
	int		i;

	i = 0;
	while (list[i].indice)
	{
		lst[i].coord.x = (list[i].pos.x - list[i].pos.y) * 2;
		lst[i].coord.y = list[i].pos.x + list[i].pos.y - list[i].pos.z;
		lst[i].coord.clr = ft_get_color(list[i].pos.z);
		i++;
	}
	return (lst);
}

t_env		*ft_convert_list(t_env *env)
{
	int		i;

	i = 0;
	while (env->list[i].indice != 0)
		i++;
	if (env->lst == NULL)
		PROTEC((env->lst = (t_pts *)ft_memalloc(sizeof(t_pts) * i)));
	env->lst = ft_fill_pos(env->list, env->lst);
	return (env);
}

t_env		*ft_init_list(t_env *env)
{
	int		i;

	i = 0;
	env->s_l = 0;
	env->s_c = 0;
	while (env->list[i].indice != 0)
	{
		if (env->list[i].pos.y == 0)
			env->s_l++;
		env->s_c = env->list[i].pos.y + 1;
		if (env->list[i].pos.z == 0)
			env->list[i].loc = 0;
		else
			env->list[i].loc = 1;
		i++;
	}
	return (env);
}
