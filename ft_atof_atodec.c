/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_atodec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:17:54 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 19:05:11 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_atof.h"

static int		atodec_atoi(const char *str)
{
	int				sign;
	unsigned long	abs;

	sign = 1;
	abs = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		abs = abs * 10 + *(str++) - '0';
	return ((int)(sign * abs));
}

static const char	*atodec_findhead(const char *s, t_float *iflt)
{
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		iflt->sign = *s++ == '-' ? 1 : 0;
	while (*s == '0')
		s++;
	return (s);
}

static const char	*atodec_store_int(const char *s, t_float *iflt, int *digit)
{
	while (ft_isdigit(*s))
	{
		if (++(*digit) <= 18)
			iflt->frac_d.lsb = iflt->frac_d.lsb * 10 + *s - '0';
		else
			iflt->exp_d++;
		s++;
	}
	return (s);
}

static const char	*atodec_store(const char *s, t_float *iflt)
{
	int		digit;
	int		flag_expminus;

	digit = 0;
	s = atodec_store_int(s, iflt, &digit);
	flag_expminus = (digit <= 18);
	if (*s != 'e' && *s != 'E' && *s != '.')
		return (s);
	if (*s == '.')
		s++;
	while (ft_isdigit(*s))
	{
		if (++digit <= 18)
			iflt->frac_d.lsb = iflt->frac_d.lsb * 10 + *s - '0';
		if (flag_expminus && iflt->exp_d)
			iflt->exp_d--;
		s++;
	}
	return (s);
}

void				ft_atof_atodec(const char *s, t_float *iflt)
{
	s = atodec_findhead(s, iflt);
	s = atodec_store(s, iflt);
	printf("iflt.exp_d      = %d\n", iflt->exp_d);
	if (*s == 'e' || *s == 'E')
		iflt->exp_d += atodec_atoi(++s);
}
