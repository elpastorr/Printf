#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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

	i = 0;
	while (s[i])
		i += put_charlen(s[i]);
	return (i);
}
int	put_ulllen(unsigned long long nb, char *base)
{
	int				count;

	count = 0;
	if (nb < ft_strlen(base))
		count += put_charlen(base[nb]);
	else
	{
		count += put_ulllen(nb / ft_strlen(base), base);
		count += put_charlen((base[nb % ft_strlen(base)]));
	}
	return (count);
}

int	put_voidlen(void *ad)
{
	int	count;

	count = 0;
	count += put_charlen('0');
	count += put_charlen('x');
	count += put_ulllen((unsigned long long)ad, "0123456789abcdef");
	return (count);
}

int	putu_nbrlen(unsigned int nb)
{
	int				count;

	count = 0;
	if (nb < 10)
		count += put_charlen(nb + '0');
	else
	{
		count += putu_nbrlen(nb / 10);
		count += put_charlen(nb % 10 + '0');
	}
	return (count);
}

int	put_nbrbaselen(int n, char *base)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += put_charlen('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb < ft_strlen(base))
		count += put_charlen(base[nb]);
	else
	{
		count += put_nbrbaselen(nb / ft_strlen(base), base);
		count += put_charlen((base[nb % ft_strlen(base)]));
	}
	return (count);
}

int	ft_conv(const char c, va_list arg)
{
	int	count;

	count = 0;
	if (!c)
		return (0);
	if (c == 'c')
		count += put_charlen(va_arg(arg, int));
	if (c == 's')
		count += put_strlen(va_arg(arg, char *));
	if (c == 'd' || c == 'i')
		count += put_nbrbaselen(va_arg(arg, int), "0123456789");
	if (c == 'u')
		count += putu_nbrlen(va_arg(arg, unsigned int));
	if (c == 'x')
		count += put_nbrbaselen(va_arg(arg, int), "0123456789abcdef");
	if (c == 'X')
		count += put_nbrbaselen(va_arg(arg, int), "0123456789ABCDEF");
	if (c == '%')
		count += put_charlen('%');
	if (c == 'p')
		count += put_voidlen(va_arg(arg, void *));
	return (count);
}

int ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			count += put_charlen(s[i]);
		}
		else
			count += ft_conv(s[++i], arg);
		i++;
	}
	va_end(arg);
	return (count);
}

int	main(int ac, char **av)
{
	char			*s = "ekip";
	void			*p = &s;
	int				d = -2147483648;
	char			c = 'O';
	int				x = 21;
	int				X = 42;
	int				o = 789;
	unsigned int	u = 2147483699;
	int	i = ft_printf("%p %% %c %s %d %i %u %x %X\n", p, c, s, d, o, u, x, X);
	int	j = printf("%p %% %c %s %d %i %u %x %X\n", p, c, s, d, o, u, x, X);
	printf("%d\n", i);
	printf("%d\n", j);
}
