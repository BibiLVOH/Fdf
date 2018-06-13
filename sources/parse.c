/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:10:39 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/09 15:00:24 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_env	*ft_add_list(t_env *env, char *line, int *i, int l)
{
	int		pos;
	int		j;

	j = 0;
	pos = 0;
	while (line[pos])
	{
		while (line[pos] == ' ')
			pos++;
		env->list[*i].indice = *i + 1;
		env->old[*i].indice = *i + 1;
		env->list[*i].pos.z = ft_atoi(line + pos);
		env->old[*i].pos.z = ft_atoi(line + pos);
		pos += ft_nbrlen(ft_atoi(line + pos));
		env->list[*i].pos.y = l;
		env->old[*i].pos.y = l;
		env->list[*i].pos.x = j;
		env->old[*i].pos.x = j;
		j++;
		*i = *i + 1;
	}
	return (env);
}

t_env	*ft_fill_list(int fd, t_env *env)
{
	int		ret;
	int		i;
	int		l;
	char	*line;

	ret = 1;
	i = 0;
	l = 0;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret)
		{
			env = ft_add_list(env, line, &i, l);
			l++;
		}
		ft_strdel(&line);
	}
	env->list[i].indice = 0;
	env->old[i].indice = 0;
	return (env);
}

int		ft_list_count(char *line)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i]) && line[i - 1] && !ft_isdigit(line[i - 1]))
		|| i == 0)
			cpt++;
		i++;
	}
	return (cpt);
}

t_env	*ft_get_list(int fd, char *source, t_env *env)
{
	int		rez;
	int		dot;
	int		fd2;
	char	*line;

	rez = 1;
	dot = 0;
	while (rez)
	{
		rez = get_next_line(fd, &line);
		if (rez > 0)
			dot = dot + ft_list_count(line);
		CHECK_READ(rez);
		ft_strdel(&line);
	}
	PROTEC((env->list = (t_dot*)ft_memalloc(sizeof(t_dot) * (dot + 1))));
	PROTEC((env->old = (t_dot*)ft_memalloc(sizeof(t_dot) * (dot + 1))));
	fd2 = open(source, O_RDONLY);
	env = ft_fill_list(fd2, env);
	CHECK_CLOSE(fd2);
	return (env);
}

t_env	*ft_parse_file(char *source, t_env *env)
{
	int		fd;

	fd = open(source, O_RDONLY);
	CHECK_OPEN(fd);
	env = ft_get_list(fd, source, env);
	CHECK_CLOSE(fd);
	return (env);
}
