/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:07:11 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/15 14:54:53 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env		*ft_xyd(t_env *env)
{
	int		i;

	i = 0;
	while (env->list[i].indice)
	{
		env->lst[i].coord.xd = \
		env->lst[i].coord.x * (env->display.zoom / 10) + env->display.deca_x;
		env->lst[i].coord.yd = \
		env->lst[i].coord.y * (env->display.zoom / 10) + env->display.deca_y;
		i++;
	}
	return (env);
}

t_env		*ft_reload_display(t_env *env, int key)
{
	if (key == 0)
		env->display.deca_x = env->display.deca_x - 2;
	if (key == 2)
		env->display.deca_x = env->display.deca_x + 2;
	if (key == 13)
		env->display.deca_y = env->display.deca_y - 2;
	if (key == 1)
		env->display.deca_y = env->display.deca_y + 2;
	if (key == 27 && env->display.zoom > 20)
		env->display.zoom = env->display.zoom - 5;
	if (key == 24)
		env->display.zoom = env->display.zoom + 5;
	env = ft_xyd(env);
	return (env);
}

t_env		*ft_init_display(t_env *env)
{
	env->display.zoom = 100;
	env->display.deca_x = (LENGTH / 2) - 66;
	env->display.deca_y = (WIDTH / 2) - 150;
	env = ft_xyd(env);
	return (env);
}
