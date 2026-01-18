/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:44:51 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/18 20:33:23 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ============================================================
// DFS Practice Phases (Problem List)
// ============================================================
//
// Phase 0: Basic Recursion (DFS Shape)
// ------------------------------------
// Given an integer n,
// print numbers from n down to 1, one per line.
// - Use recursion only (no loops).
// - This phase is to understand how recursion stacks.
//
// Example:
//   Input: 5
//   Output:
//     5
//     4
//     3
//     2
//     1
//
// ============================================================

#include "dfs.h"

//This is review edition.
//void	phase0_run(int n)
//{
//	int	depth;
//
//	if (n < 0)
//		return ;
//	depth = n;
//	if (depth == 0)
//	{
//		printf("You reached the bottom\n");
//		return ;
//	}
//	printf("You have to down %d times to reach the bottom\n", depth);
//	phase0_run(depth - 1);
//	return ;
//}

void	phase0_run(int n)
{
	if (n <= 0)
		return ;
	printf("downside: %d\n", n);
	phase0_run(n - 1);
	printf("upside: %d\n", n);
}
