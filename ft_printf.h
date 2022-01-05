/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:08:58 by elpastor          #+#    #+#             */
/*   Updated: 2022/01/04 16:10:00 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_conv(const char c, va_list arg);

int	put_ulllen(unsigned long long nb, char *base);
int	put_voidlen(void *ad);
int	put_nbrlen(int nb);
int	putu_nbrlen(unsigned int nb);
int	put_nbrbaselen(int n, char *base);

int	put_charlen(char c);
int	ft_strlen(char *s);
int	put_strlen(char *s);

#endif
