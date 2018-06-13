/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:57:39 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/08 10:37:39 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env	*ft_hor_seg(t_env *env, t_rgb clri, t_rgb clrf)
{
	int		i;

	env->seg.cumul = env->seg.dx / 2;
	i = 1;
	while (i <= env->seg.dx)
	{
		env->seg.x += env->seg.xinc;
		env->seg.cumul += env->seg.dy;
		if (env->seg.cumul >= env->seg.dx)
		{
			env->seg.cumul -= env->seg.dx;
			env->seg.y += env->seg.yinc;
		}
		env = ft_add_pix(env, clri, clrf, (i / env->seg.dx));
		i++;
	}
	return (env);
}

t_env	*ft_ver_seg(t_env *env, t_rgb clri, t_rgb clrf)
{
	int		i;

	env->seg.cumul = env->seg.dy / 2;
	i = 1;
	while (i <= env->seg.dy)
	{
		env->seg.y += env->seg.yinc;
		env->seg.cumul += env->seg.dx;
		if (env->seg.cumul >= env->seg.dy)
		{
			env->seg.cumul -= env->seg.dy;
			env->seg.x += env->seg.xinc;
		}
		env = ft_add_pix(env, clri, clrf, (i / env->seg.dy));
		i++;
	}
	return (env);
}

t_env	*ft_add_right_line(t_env *env, int xf, int yf, int i)
{
	env->seg.x = env->seg.xi;
	env->seg.y = env->seg.yi;
	env->seg.xf = xf;
	env->seg.yf = yf;
	env->seg.dx = xf - env->seg.xi;
	env->seg.dy = yf - env->seg.yi;
	env->seg.xinc = (env->seg.dx > 0) ? 1 : -1;
	env->seg.yinc = (env->seg.dy > 0) ? 1 : -1;
	env->seg.dx = ft_abs(env->seg.dx);
	env->seg.dy = ft_abs(env->seg.dy);
	env = ft_add_pix(env, env->lst[i].coord.clr, env->lst[i + 1].coord.clr, 0);
	if (env->seg.dx > env->seg.dy)
		env = ft_hor_seg(env, env->lst[i].coord.clr, env->lst[i + 1].coord.clr);
	else
		env = ft_ver_seg(env, env->lst[i].coord.clr, env->lst[i + 1].coord.clr);
	return (env);
}

t_env	*ft_add_down_line(t_env *env, int xf, int yf, int i)
{
	env->seg.x = env->seg.xi;
	env->seg.y = env->seg.yi;
	env->seg.xf = xf;
	env->seg.yf = yf;
	env->seg.dx = xf - env->seg.xi;
	env->seg.dy = yf - env->seg.yi;
	env->seg.xinc = (env->seg.dx > 0) ? 1 : -1;
	env->seg.yinc = (env->seg.dy > 0) ? 1 : -1;
	env->seg.dx = ft_abs(env->seg.dx);
	env->seg.dy = ft_abs(env->seg.dy);
	env = ft_add_pix(env, env->lst[i].coord.clr, env->lst[i + \
	env->s_l].coord.clr, 0);
	if (env->seg.dx > env->seg.dy)
		env = ft_hor_seg(env, env->lst[i].coord.clr, env->lst[i + \
		env->s_l].coord.clr);
	else
		env = ft_ver_seg(env, env->lst[i].coord.clr, env->lst[i + \
		env->s_l].coord.clr);
	return (env);
}

t_env	*ft_reload_image(t_env *env)
{
	int		i;

	i = 0;
	env = ft_clear_image(env);
	while (env->list[i].indice && env->list[i + 1].indice)
	{
		env->seg.xi = env->lst[i].coord.xd;
		env->seg.yi = env->lst[i].coord.yd;
		if (env->list[i].pos.x != env->s_l - 1)
			env = ft_add_right_line(env, env->lst[i + 1].coord.xd, \
			env->lst[i + 1].coord.yd, i);
		if (env->list[i].pos.y != env->s_c - 1)
			env = ft_add_down_line(env, env->lst[i + env->s_l].coord.xd, \
			env->lst[i + env->s_l].coord.yd, i);
		i++;
	}
	return (env);
}
