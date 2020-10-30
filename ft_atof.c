/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:42:08 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 15:45:49 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_atof.h"

double	ft_atof(const char *s)
{
	t_float		iflt;

	ft_atof_atobin(s, &iflt);
	return (ft_atof_bintof(iflt));
}

int		main(int argc, char **argv)
{
	char		*s;
	double		n;

	if (argc != 2)
		return (0);
	s = argv[1];
	n = ft_atof(s);
	return (0);
}
