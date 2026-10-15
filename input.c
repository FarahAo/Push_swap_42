/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabo-ome <fabo-ome@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:29:10 by fabo-ome          #+#    #+#             */
/*   Updated: 2026/10/15 18:12:38 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	is_valid_number(char *number)
{
	int	i;

	if (!number || !number[0])
		return (0);
	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (!number[i])
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}	
	return (1);
}

void    parse_args(int argc, char **argv)
{
    char    **numbers;
    int i;
    int     j;

    i = 1;
    while (i < argc)
    {
        numbers = ft_split(argv[i], ' ');
        if (!numbers)
            return ;
        j = 0;
	//loop just for test
        while (numbers[j])
        {
		printf("%s\n", numbers[j]);//validate numbers and add them to the stack
		if (is_valid_number(numbers[j]))
			printf("Valid\n");
		else
			printf("Not Valid\n");      
            j++;
        }
        //free_split(numbers);
        i++;
    }
}
int	main(int argc, char **argv)
{
	if (argc > 1)
		parse_args(argc,argv);
	return(0);
}
