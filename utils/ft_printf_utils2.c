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
