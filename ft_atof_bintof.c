/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bintof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:35:59 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 18:49:45 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>  
#include "ft_atof.h"

double	ft_atof_bintof(t_float iflt)
{
	t_ufloat	ufloat;

	printf("iflt.frac       = %llu\n", iflt.frac);
	printf("iflt.exp        = %d\n", iflt.exp);
	ufloat.mem = 0;
	ufloat.mem |= ((uint64_t)iflt.sign << 63);
	ufloat.mem |= ((uint64_t)iflt.exp << 52);
	ufloat.mem |= iflt.frac;
	return (ufloat.num);
}
