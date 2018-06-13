/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:02:37 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/05 11:59:56 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_all(t_env *env)
{
	int		i;

	i = 0;
	free(env->list);
	free(env->lst);
	free(env->old);
	ft_strdel(&env->image);
	free(env->mlx_ptr);
	free(env->win_ptr);
	free(env->img_ptr);
	free(env);
	env = NULL;
}
