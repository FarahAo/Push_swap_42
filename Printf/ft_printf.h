/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:29:54 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/09/29 17:44:57 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	printf_conversion(char c, va_list *args, int *counter);

int		print_char(char c);
int		print_str(char *str);
int		print_nbr(int n);
int		print_unbr(unsigned int n);
int		print_hex(unsigned int n, char c);
int		print_ptr(void *ptr);
#endif
