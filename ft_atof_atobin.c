/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_atobin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:34:47 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 19:04:22 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  
#include "ft_atof.h"

static void	init_ifloat(t_float *iflt)
{
	iflt->sign = 0;
	iflt->exp = 0;
	iflt->frac = 0;
	iflt->exp_d = 0;
	uint128_bzero(&(iflt->frac_d));
}

void		ft_atof_atobin(const char *s, t_float *iflt)
{
	init_ifloat(iflt);
	// printf("iflt.exp        = %d\n", iflt->exp);
	ft_atof_atodec(s, iflt);
	// printf("iflt.sign       = %d\n", iflt->sign);
	// printf("iflt.frac_d.lsb = %llu\n", iflt->frac_d.lsb);
	printf("iflt.exp_d      = %d\n", iflt->exp_d);
	ft_atof_dectobin_exp(iflt);
	// printf("iflt.exp        = %d\n", iflt->exp);
	ft_atof_dectobin_frac(iflt);
}
