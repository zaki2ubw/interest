/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase05.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:56:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/31 17:55:30 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ============================================================
// DFS Practice Phases (Problem List)
// ============================================================
//
// Phase 5: Lake Counting (Connected Components)
// ---------------------------------------------
// Given an H x W map:
//   'W' : water
//   '.' : land
// Water cells connected by up/down/left/right form one lake.
// Count how many lakes exist in the map.
// - Each DFS call starting point represents one lake.
// - Replace visited 'W' with '.'.
//
// Example:
//   Input:
//     W.W
//     .W.
//     W.W
//
//   Output:
//     5
//
// ============================================================

#include "dfs.h"
#include <stdlib.h>

static int	count_lake(t_board *board, int length_x, int length_y);
static void	floodfill(t_board *board, int origin_x, int origin_y);

void	phase5_run(void)
{
	//char	grid0[] = "WW.WW.W.";
	//char	grid1[] = "...WW.W.";
	//char	grid2[] = "W..W..WW";
	//char	grid3[] = "W.......";
	//char	grid4[] = "W.......";
	//char	grid5[] = "...WW.W.";
	//char	grid6[] = "W..WW.WW";
	//char	grid7[] = "WW.WW..W";
	char	grid0[] = "W.......";
	char	grid1[] = ".W......";
	char	grid2[] = "..W.....";
	char	grid3[] = "...W....";
	char	grid4[] = "....W...";
	char	grid5[] = ".....W..";
	char	grid6[] = "......W.";
	char	grid7[] = ".......W";
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
	int	lake;
	int	i;
	t_board	*board;

	i = 0;
	while(i < 8)
	{
		printf("input: %s\n", input[i]);
		i++;
	}
	board = (t_board *)calloc(1, sizeof(t_board));
	board->input= input;
	board->length_x = 8;
	board->length_y = 8;
	lake = count_lake(board, board->length_x, board->length_y);
	i = 0;
	while(i < 8)
	{
		printf("output: %s\n", input[i]);
		i++;
	}
	//printf("Expect: 7\nResult: %d\n", lake);
	//printf("Expect: 1\nResult: %d\n", lake);
	printf("Expect: 8\nResult: %d\n", lake);
	free(board);
	return ;
}

static int	count_lake(t_board *board, int length_x, int length_y)
{
	int		y;
	int		x;
	int		lake;
	char	water;

	water = 'W';
	y = 0;
	lake = 0;
	while (y < length_y)
	{
		x = 0;
		while (x < length_x)
		{
			if (board->input[y][x] == water)
			{
				lake++;
				floodfill(board, x, y);
			}
			x++;
		}
		y++;
	}
	return (lake);
}

static void	floodfill(t_board *board, int origin_x, int origin_y)
{
	//int	direct_x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	//int	direct_y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int	direct_x[] = {-1, 0, 0, 1};
	int	direct_y[] = {0, -1, 1, 0};
	int	i;
	int	target_x;
	int	target_y;

	if (board == NULL || board->input == NULL)
		return ;
	if (origin_x < 0 || origin_x >= board->length_x)
		return ;
	else if (origin_y < 0 || origin_y >= board->length_y)
		return ;
	if (board->input[origin_y][origin_x] != 'W')
		return ;
	board->input[origin_y][origin_x] = '.';
	i = 0;
	//while (i < 8)
	while (i < 4)
	{
		target_x = origin_x + direct_x[i];
		target_y = origin_y + direct_y[i];
		floodfill(board, target_x, target_y);
		i++;
	}
}
