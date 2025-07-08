#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "process.h"

void get_cpu_times(unsigned long long *idle_time, unsigned long long *total_time) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Erro ao abrir /proc/stat");
        exit(1);
    }

    char line[256];
    fgets(line, sizeof(line), fp);
    fclose(fp);

    char cpu[5];
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;
    sscanf(line, "%s %llu %llu %llu %llu %llu %llu %llu %llu",
           cpu, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

    *idle_time = idle + iowait;
    *total_time = user + nice + system + idle + iowait + irq + softirq + steal;
}

void print_usage_bar(float usage) {
    int width = 50;
    int filled = (int)(usage / 100.0 * width);

    printf("[");
    for (int i = 0; i < width; ++i) {
        if (i < filled)
            printf("#");
        else
            printf(" ");
    }
    printf("] %.2f%%\n", usage);
}

