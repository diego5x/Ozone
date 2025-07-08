#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "process.h"

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

