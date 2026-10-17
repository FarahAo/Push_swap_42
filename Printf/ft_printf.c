/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:05:45 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/30 13:52:48 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	printf_conversion(char c, va_list *args, int *counter)
{
	if (c == 'c')
		*counter += print_char(va_arg(*args, int));
	else if (c == 's')
		*counter += print_str(va_arg(*args, char *));
	else if (c == 'p')
		*counter += print_ptr(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		*counter += print_nbr(va_arg(*args, int));
	else if (c == 'u')
		*counter += print_unbr(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		*counter += print_hex(va_arg(*args, unsigned int), c);
	else if (c == '%')
		*counter += print_char('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printf_conversion(format[i + 1], &args, &counter);
			i ++;
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
