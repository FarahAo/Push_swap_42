/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhaleel <tkhaleel@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:01:00 by tkhaleel          #+#    #+#             */
/*   Updated: 2026/10/23 16:08:58 by tkhaleel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	show_stack(char *name, t_stack *stack)
{
	t_node	*current;

	ft_printf(2, "%s (size = %d): ", name, (int)stack->size);
	current = stack->head;
	while (current)
	{
		ft_printf(2, "%d ", current->value);
		current = current->next;
	}
	ft_printf(2, "\n");
}

static void	show_state(t_options *option)
{
	show_stack("A", &option->a);
	show_stack("B", &option->b);
	ft_printf(2, "-------------------------\n");
}

static void	test_swaps(t_options *option)
{
	ft_printf(2, "\n=== TEST SWAPS ===\n");
	swap_sa(option);
	show_state(option);
	swap_sb(option);
	show_state(option);
	swap_ss(option);
	show_state(option);
}

static void	test_pushes(t_options *option)
{
	ft_printf(2, "\n=== TEST PUSHES ===\n");
	pb(option);
	show_state(option);
	pb(option);
	show_state(option);
	pa(option);
	show_state(option);
}

static void	test_rotations(t_options *option)
{
	ft_printf(2, "\n=== TEST ROTATIONS ===\n");
	ra(option);
	show_state(option);
	rb(option);
	show_state(option);
	rr(option);
	show_state(option);
}

static void	test_reverse_rotations(t_options *option)
{
	ft_printf(2, "\n=== TEST REVERSE ROTATIONS ===\n");
	rra(option);
	show_state(option);
	rrb(option);
	show_state(option);
	rrr(option);
	show_state(option);
}

static void	add_test_numbers(t_options *option)
{
	add_node(&option->a, new_node(5));
	add_node(&option->a, new_node(2));
	add_node(&option->a, new_node(8));
	add_node(&option->a, new_node(1));
	add_node(&option->a, new_node(4));
}

static void	run_tests(t_options *option)
{
	ft_printf(2, "\n=== INITIAL STACKS ===\n");
	show_state(option);
	option->disorder = compute_disorder(&option->a);
	ft_printf(2, "Disorder (scaled x10000): %d\n",
		(int)(option->disorder * 10000 + 0.5));
	test_pushes(option);
	test_swaps(option);
	test_rotations(option);
	test_reverse_rotations(option);
	ft_printf(2, "\n=== FINAL STACKS ===\n");
	show_state(option);
}

int	main(int argc, char **argv)
{
	t_options	option;

	option = (t_options){0};
	option.strategy = ADAPTIVE;
	if (argc > 1)
		parse_args(argc, argv, &option);
	else
		add_test_numbers(&option);
	run_tests(&option);
	option.bench = 1;
	print_bench(&option);
	free_stack(&option.a);
	free_stack(&option.b);
	return (0);
}
