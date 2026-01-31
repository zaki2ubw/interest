/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:23:51 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/31 17:34:16 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DFS_H
# define DFS_H

#include <stdio.h>

typedef struct s_board	t_board;

struct s_board
{
	char	**input;
	int		length_x;
	int		length_y;
} ;

void    phase0_run(int depth);
void    phase1_run(void);
void    phase2_run(void);
void    phase3_run(void);
void    phase4_run(void);
void    phase5_run(void);

#endif
