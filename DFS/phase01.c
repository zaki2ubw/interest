/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:48:07 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/18 21:09:22 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ============================================================
// DFS Practice Phases (Problem List)
// ============================================================
//
// Phase 1: One-Dimensional DFS
// ----------------------------
// Given an integer array of length N,
// traverse and print all elements from left to right using DFS.
// - Do not use for/while loops.
// - Pass the index as a state.
//
// Example:
//   Array: [1, 2, 3, 4, 5]
//   Output:
//     1
//     2
//     3
//     4
//     5
//
// ============================================================

#include "dfs.h"

static void	dfs(int *array, int size, int index);

void	phase1_run(void)
{
	int	array[] = {1, 2 ,3 ,4, 5};
	int	size;

	size = (int)(sizeof(array) / sizeof(array[0]));
	printf("[phase1] Test starting\n");
	dfs(array, size, 0);
	return ;
}

static void	dfs(int *array, int size, int index)
{
	if (array == NULL || size < 0 || index < 0)
		return ;
	if (index >= size)
		return ;
	printf("array[%d]: %d\n", index, array[index]);
	dfs(array, size, index + 1);
	printf("Now exit the process of index%d\n", index);
}
