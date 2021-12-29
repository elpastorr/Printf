#ifndef PRINTF_H
# define PRINTF_H

#include <string.h>
#include <unistd.h>
#include <stdarg.h>


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
