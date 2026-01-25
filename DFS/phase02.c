/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:58:04 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/25 12:42:26 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ============================================================
// DFS Practice Phases (Problem List)
// ============================================================
//
// Phase 2: Vertical DFS (Single Direction)
// ----------------------------------------
// Given a vertical line of cells represented by characters:
//   '#' : walkable cell
//   '.' : blocked cell
// Starting from the top,
// move ONLY downward using DFS.
// - Stop when reaching '.' or out of bounds.
// - Replace visited '#' with '.'.
//
// Example:
//   Input:
//     #
//     #
//     #
//     #
//     .
//
//   After DFS:
//     .
//     .
//     .
//     .
//     .
//
// ============================================================

#include "dfs.h"
#include <stdlib.h>
#include <string.h>

static void	dfs_phase2(char *input, size_t column, size_t depth);

void	phase2_run(void)
{
	char	input[] = "####.";
	size_t		column;

	printf("input: %s\n", input);
	column = strlen(input);
	dfs_phase2(input, column, 0);
	printf("output: %s\n", input);
	return ;
}

static void	dfs_phase2(char *input, size_t column, size_t depth)
{
	char	hashtag;
	char	period;

	hashtag = '#';
	period = '.';
	if (input == NULL || column == 0)
		return ;
	else if (input[depth] != period && input[depth] != hashtag)
		return ;
	if (input[depth] == period || column <= depth)
		return ;
	input[depth] = period;
	printf("current: %s\n", input);
	dfs_phase2(input, column, depth + 1);
}
