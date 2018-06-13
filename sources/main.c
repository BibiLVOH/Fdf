/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:10:15 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/14 18:19:38 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	proper_exit(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	ft_add_control(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, 16777215, "KEY CONTROL");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 40, 16777215, \
	"TRANSLATION : W / A / S / D");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 60, 16777215, \
	"ZOOM : - / +");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 80, 16777215, \
	"CHANGE HIGH : M / L");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 100, 16777215, \
	"INVERSE HIGH : I");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 120, 16777215, \
	"RESET POSITION : SPACE");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 140, 16777215, \
	"ESCAPE : ESC");
}

int		ft_key_hook(int key, t_env *env)
{
	if (key == 53)
	{
		ft_free_all(env);
		exit(0);
	}
	if (key == OLD)
	{
		env = ft_reset_high(env);
		env = ft_init_display(env);
	}
	if (key == INV)
		env = ft_inverse_high(env);
	if (key == MORE)
		env = ft_more_high(env);
	if (key == LESS)
		env = ft_less_high(env);
	if (key == 0 || key == 2 || key == 1 || key == 13 || key == 27 || key == 24)
		env = ft_reload_display(env, key);
	env = ft_convert_list(env);
	env = ft_reload_display(env, key);
	env = ft_reload_image(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_control(env);
	return (0);
}

int		ft_loop_env(t_env *env)
{
	env = ft_convert_list(env);
	env = ft_init_display(env);
	env = ft_reload_image(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_control(env);
	mlx_hook(env->win_ptr, 2, 3, ft_key_hook, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		bpp;
	int		s_l;
	int		endian;

	USAGE((ac != 2 || !(ft_strend(av[1], ".fdf"))));
	PROTEC((env = (t_env*)ft_memalloc(sizeof(t_env))));
	env = ft_parse_file(av[1], env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, LENGTH, av[1]);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, LENGTH);
	env->image = mlx_get_data_addr(env->img_ptr, &bpp, &s_l, &endian);
	env = ft_init_list(env);
	ft_loop_env(env);
	return (0);
}
