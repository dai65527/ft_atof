/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_dectobin_frac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:37:48 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 18:47:45 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  
#include "ft_atof.h"

static void	dectobin_frac_setunnorm(t_float *iflt)
{
	if ((!iflt->frac_d.msb && !iflt->frac_d.lsb) || iflt->exp < -1074)
	{
		iflt->frac = 0;
		iflt->exp = -1023;
		return ;
	}
	iflt->frac_d.msb >>= (-1023 - iflt->exp);
	iflt->frac = iflt->frac_d.msb >> 12;
}

static void	dectobin_frac_setnorm(t_float *iflt)
{
	iflt->frac_d.msb <<= 1;
	iflt->frac = iflt->frac_d.msb >> 12;
	// printf("iflt.exp        = %d\n", iflt->exp);
	// printf("iflt.frac_d.lsb = %llu\n", iflt->frac_d.lsb);
	// printf("iflt.frac_d.msb = %llu\n", iflt->frac_d.msb);
	// printf("iflt.frac       = %llu\n", iflt->frac);
}

void		ft_atof_dectobin_frac(t_float *iflt)
{
	if (iflt->exp > 1023)
	{
		iflt->exp = 2047;
		iflt->frac = 0;
		return ;
	}
	else if (iflt->exp < -1022)
		dectobin_frac_setunnorm(iflt);
	else
		dectobin_frac_setnorm(iflt);
	iflt->exp += 1023;
}
