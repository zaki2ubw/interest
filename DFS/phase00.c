/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:44:51 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/18 20:14:10 by sohyamaz         ###   ########.fr       */
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

void	phase0_run(int n)
{
	int	depth;

	if (n < 0)
		return ;
	depth = n;
	if (depth == 0)
		return ;
	printf("Your standing depth is %d\n");
	phase0_run(depth - 1);
	return ;
}
