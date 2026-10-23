/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:53:27 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 16:18:10 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_ptr_hex(int fd,unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_ptr_hex(fd,n / 16);
	count += print_char(fd,base[n % 16]);
	return (count);
}

int	print_ptr(int fd,void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (print_str(fd,"(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += print_str(fd,"0x");
	count += print_ptr_hex(fd,address);
	return (count);
}
