/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:18:02 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 17:39:42 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_atof.h"

int		main(int argc, char **argv)
{
	char		*s;
	double		n_ft;
	double		n_st;

	if (argc != 2)
		return (0);
	s = argv[1];
	n_ft = ft_atof(s);
	n_st = atof(s);
	printf("std = %.10e\n", n_st);
	printf("ft  = %.10e\n", n_ft);
	return (0);
}
