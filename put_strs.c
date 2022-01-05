/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:26:30 by elpastor          #+#    #+#             */
/*   Updated: 2022/01/05 14:26:32 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_charlen(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	put_strlen(char *s)
{
	int	i;

	if (!s)
		return (put_strlen("(null)"));
	i = 0;
	while (s[i])
		i += put_charlen(s[i]);
	return (i);
}
