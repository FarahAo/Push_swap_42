/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:05:45 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 16:16:43 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion(int fd, char c, va_list *args, int *counter)
{
	if (c == 'c')
		*counter += print_char(fd, va_arg(*args, int));
	else if (c == 's')
		*counter += print_str(fd, va_arg(*args, char *));
	else if (c == 'p')
		*counter += print_ptr(fd, va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		*counter += print_nbr(fd, va_arg(*args, int));
	else if (c == 'u')
		*counter += print_unbr(fd, va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		*counter += print_hex(fd, va_arg(*args, unsigned int), c);
	else if (c == '%')
		*counter += print_char(fd, '%');
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			printf_conversion(fd, format[++i], &args, &counter);
		}
		else if (format[i] != '%')
		{
			write(fd, &format[i], 1);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
