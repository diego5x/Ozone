#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int main() {
    unsigned long long prev_idle, prev_total;
    get_cpu_times(&prev_idle, &prev_total);

    while (1) {
        sleep(1);
        unsigned long long idle, total;
        get_cpu_times(&idle, &total);

        unsigned long long diff_idle = idle - prev_idle;
        unsigned long long diff_total = total - prev_total;
        float cpu_usage = 100.0 * (1.0 - (float)diff_idle / diff_total);

        printf("\033[2J\033[H"); 
        printf("Uso da CPU:\n");
        print_usage_bar(cpu_usage);

        prev_idle = idle;
        prev_total = total;
    }

    return 0;
}

