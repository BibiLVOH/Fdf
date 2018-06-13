/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:10:47 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/15 13:42:54 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env	*ft_reset_high(t_env *env)
{
	int		i;

	i = 0;
	while (env->list[i].indice)
	{
		env->list[i].pos.z = env->old[i].pos.z;
		i++;
	}
	return (env);
}

t_env	*ft_inverse_high(t_env *env)
{
	int		i;

	i = 0;
	while (env->list[i].indice)
	{
		env->list[i].pos.z = -1 * env->list[i].pos.z;
		i++;
	}
	return (env);
}

t_env	*ft_more_high(t_env *env)
{
	int		i;

	i = 0;
	while (env->list[i].indice)
	{
		if (env->list[i].loc != 0 && env->list[i].pos.z > 0)
			env->list[i].pos.z = env->list[i].pos.z * 1.1;
		else
			env->list[i].pos.z = env->list[i].pos.z * 0.9;
		i++;
	}
	return (env);
}

t_env	*ft_less_high(t_env *env)
{
	int		i;

	i = 0;
	while (env->list[i].indice)
	{
		if (env->list[i].loc != 0 && env->list[i].pos.z > 0)
			env->list[i].pos.z = env->list[i].pos.z * 0.9;
		else
			env->list[i].pos.z = env->list[i].pos.z * 1.1;
		i++;
	}
	return (env);
}
