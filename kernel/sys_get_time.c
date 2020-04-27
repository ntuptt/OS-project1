#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/timer.h>

asmlinkage int sys_get_time(unsigned long *now_sec, unsigned long *now_nsec){
    struct timespec t;
    getnstimeofday(&t);
    *now_sec = t.tv_sec;
    *now_nsec = t.tv_nsec;
    return 0;
}