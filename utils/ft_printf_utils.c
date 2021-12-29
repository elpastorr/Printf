#include "ft_printf.h"

int	put_ulllen(unsigned long long nb, char *base)
{
	int	count;

	count = 0;
	if (nb < (unsigned long long)ft_strlen(base))
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

	if (!ad)
		return (put_strlen("(nil)"));
	count = 0;
	count += put_charlen('0');
	count += put_charlen('x');
	count += put_ulllen((unsigned long long)ad, "0123456789abcdef");
	return (count);
}

int	put_nbrlen(int nb)
{
	int		count;
	unsigned int	n;

	count = 0;
	if (nb < 0)
	{
		count += put_charlen('-');
		n = -nb;
	}
	else
		n = nb;
	if (n < 10)
		count += put_charlen(n + '0');
	else
	{
		count += put_nbrlen(n / 10);
		count += put_charlen((n % 10) + '0');
	}
	return (count);
}

int	putu_nbrlen(unsigned int nb)
{
	int	count;

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
	int		count;

	count = 0;
	nb = n;
	if (nb < (unsigned int)ft_strlen(base))
		count += put_charlen(base[nb]);
	else
	{
		count += put_nbrbaselen(nb / ft_strlen(base), base);
		count += put_charlen((base[nb % ft_strlen(base)]));
	}
	return (count);
}
