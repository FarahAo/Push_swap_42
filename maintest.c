/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:07:12 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/19 17:16:18 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

typedef struct s_test
{
    int a;
} t_test;

int main(void)
{
    t_test obj;
    t_test *test = &obj;

    test->a = 5;

    printf("%d\n", test->a);
    printf("%d\n", (*test).a);

    return (0);
}	
