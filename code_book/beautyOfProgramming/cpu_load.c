#include <stdio.h>
#include <math.h>

#include <unistd.h>
#include <sys/times.h>
#define __USE_GNU
#include <sched.h>


// 设置进程在哪个cpu上运行
void set_cpu(int id)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(id, &mask);
    if (sched_setaffinity(0, sizeof(mask), &mask) == -1) {
        fprintf(stderr, "warning: could not set CPU affinity\n");
    }
}

clock_t Hz; // 时钟中断频率

void draw_line(int cpu_id)
{
    set_cpu(cpu_id);
    
    clock_t busy = Hz / 50; // 20ms
    clock_t idle = busy;
    clock_t start;
    while (1) {
        start = times(NULL);
        // busy loop
        while (times(NULL) - start <= busy)
            ;

        // idle loop
        usleep(idle * 1000 * 1000 / Hz);
    }
}

#define COUNT 200 // 分成200个小区间
void draw_sin(int cpu_id)
{
    set_cpu(cpu_id);

    int i;
    const double PI = 3.1415926;
    const clock_t INTERVAL = Hz * 2;
    clock_t busy_span[COUNT];
    clock_t idle_span[COUNT];
 
    clock_t half = INTERVAL / 2;
    double radian = 0.0;
    for (i=0; i < COUNT; ++i) { // 预计算
        busy_span[i] = half * (1 + sin(PI * radian));
        idle_span[i] = INTERVAL - busy_span[i];
        radian += (2 / COUNT);
    }

    clock_t start;
    for (i = 0; 1; ++i) {
        i %= COUNT;
        start = times(NULL);
        while (times(NULL) - start <= busy_span[i])
            ;
        usleep(idle_span[i] * 1000 * 1000 / Hz);
    }
}

int main()
{
    Hz = sysconf(_SC_CLK_TCK);

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        draw_line(0);
    } else {
        draw_sin(1);
    }
    return 0;
}