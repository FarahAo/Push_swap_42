/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuqa134 <tuqa134@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:29:54 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 10:41:56 by tuqa134          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(int fd, const char *format, ...);
void	printf_conversion(int fd, char c, va_list *args, int *counter);
int		print_char(int fd, char c);
int		print_str(int fd, char *str);
int		print_nbr(int fd, int n);
int		print_unbr(int fd, unsigned int n);
int		print_hex(int fd, unsigned int n, char c);
int		print_ptr(int fd, void *ptr);
#endif
