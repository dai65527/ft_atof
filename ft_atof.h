/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:06:50 by dnakano           #+#    #+#             */
/*   Updated: 2020/10/30 17:09:02 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOF_H
# define FT_ATOF_H

# include <stdint.h>

# define FLT_FRACBIT	52
# define FLT_EXPBIAS	1023
# define FLT_EXPBIT		11

typedef struct	s_uint128
{
	u_int64_t	lsb;
	u_int64_t	msb;
}				t_uint128;

typedef union	u_float
{
	double		num;
	uint64_t	mem;
}				t_ufloat;

typedef struct	s_float
{
	u_int8_t	sign;
	int32_t		exp;
	u_int64_t	frac;
	int			exp_d;
	t_uint128	frac_d;
}				t_float;

# ifndef LIBFT_H
double		ft_atof(const char *s);
int			ft_isdigit(int c);
int			ft_isspace(int c);
# endif

void		ft_atof_atobin(const char *s, t_float *iflt);
void		ft_atof_atodec(const char *s, t_float *iflt);
void		ft_atof_dectobin(t_float *iflt);
void		ft_atof_dectobin_exp(t_float *iflt);
void		ft_atof_dectobin_frac(t_float *iflt);
double  	ft_atof_bintof(t_float iflt);

void		uint128_bzero(t_uint128 *n);
t_uint128	uint128_leftshift(t_uint128 n, unsigned int width);
t_uint128	uint128_rightshift(t_uint128 n, unsigned int width);
t_uint128	uint128_sum(t_uint128 a, t_uint128 b);
t_uint128	uint128_tenx(t_uint128 n);
t_uint128	uint128_tendiv(t_uint128 n);

#endif
