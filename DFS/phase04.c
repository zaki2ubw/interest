/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:05:07 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/25 19:31:01 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ============================================================
// DFS Practice Phases (Problem List)
// ============================================================
//
// Phase 4: Two-Dimensional DFS (4 Directions)
// -------------------------------------------
// Given an H x W grid:
//   '#' : walkable cell
//   '.' : blocked cell
// Starting from a given position,
// perform DFS in four directions (up, down, left, right).
// - Use direction arrays (dx, dy).
// - Replace visited '#' with '.'.
//
// Example:
//   Input:
//     ##
//     ##
//
//   After DFS:
//     ..
//     ..
//
// ============================================================

#include "dfs.h"

static void	dfs_phase04(char **input, int height, int width, int depth, int index);

void	phase4_run(void)
{
	char	grid0[] = "##.##.#.";
	char	grid1[] = ".#.##.#.";
	char	grid2[] = "#####.#.";
	char	grid3[] = "#.#####.";
	char	grid4[] = "#..#....";
	char	grid5[] = ".#.##.#.";
	char	grid6[] = "#..##.##";
	char	grid7[] = "##.#####";
	char	*input[] =
	{
		grid0,
		grid1,
		grid2,
		grid3,
		grid4,
		grid5,
		grid6,
		grid7
	};
	int	i;

	i = 0;
	while(i < 8)
	{
		printf("input: %s\n", input[i]);
		i++;
	}
	dfs_phase04(input, 8, 8, 0, 0);
	i = 0;
	while(i < 8)
	{
		printf("output: %s\n", input[i]);
		i++;
	}
	return ;
}

static void	dfs_phase04(char **input, int height, int width, int depth, int index)
{
	int	i;
	int	up;
	int	down;
	int	left;
	int	right;

	if (input == NULL || height == 0 || width == 0)
	{
		printf("Error: invalid arguments\n");
		return ;
	}
	if (depth < 0 || depth >= height)
		return ;
	if (index < 0 || index >= width)
		return ;
	if (input[depth][index] != '#')
		return ;
	input[depth][index] = '.';
	i = 0;
	up = depth - 1;
	down = depth + 1;
	left = index - 1;
	right = index + 1;
	while(i < 8)
	{
		printf("draw: %s\n", input[i]);
		i++;
	}
	dfs_phase04(input, height, width, up, index);
	dfs_phase04(input, height, width, down, index);
	dfs_phase04(input, height, width, depth, left);
	dfs_phase04(input, height, width, depth, right);
}

//static void	dfs_phase04(char **input, int height, int width, int depth, int index)
//{
//	int	i;
//
//	if (*input == NULL || height == 0 || width == 0)
//	{
//		printf("Error: invalid arguments\n");
//		return ;
//	}
//	if (index >= width)
//	{
//		index = 0;
//		depth++;
//	}
//	if (height <= depth)
//		return ;
//	if (input[depth][index] == '#')
//		input[depth][index] = '.';
//	i = 0;
//	while(i < 8)
//	{
//		printf("draw: %s\n", input[i]);
//		i++;
//	}
//	dfs_phase04(input, height, width, depth, index + 1);
//}
