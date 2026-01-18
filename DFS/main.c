/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:22:47 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/01/18 20:15:47 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfs.h"

//This test is made by chappy

static void usage(const char *prog)
{
    printf("Usage:\n");
    printf("  %s <phase>\n", prog);
    printf("phase:\n");
    printf("  0..5   Run a single phase\n");
    printf("  all    Run all phases\n");
}

static int run_phase(int p)
{
    if (p == 0) phase0_run(5);
    else if (p == 1) phase1_run();
    else if (p == 2) phase2_run();
    else if (p == 3) phase3_run();
    else if (p == 4) phase4_run();
    else if (p == 5) phase5_run();
    else return 0;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "all") == 0) {
        for (int p = 0; p <= 5; p++)
            run_phase(p);
        return 0;
    }
    char *end = NULL;
    long p = strtol(argv[1], &end, 10);
    if (end == argv[1] || *end != '\0') {
        usage(argv[0]);
        return 1;
    }
    if (!run_phase((int)p)) {
        usage(argv[0]);
        return 1;
    }
    return 0;
}
