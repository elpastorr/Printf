#include "ft_printf.h"

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
		count += put_nbrlen(va_arg(arg, int));
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
