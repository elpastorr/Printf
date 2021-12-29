#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
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
