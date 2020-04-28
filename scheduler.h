#ifndef _SCHEDULING_H_
#define _SCHEDULING_H_

#include "util.h"

class Scheduler {
    virtual int next_process(struct process *proc, int nproc) = 0;
public:
    int scheduling(struct process *proc, int nproc);
};

class PSJF_Scheduler: public Scheduler {
    int next_process(struct process *proc, int nproc);
};

class SJF_Scheduler: public Scheduler {
    int next_process(struct process *proc, int nproc);
};

class FIFO_Scheduler: public Scheduler {
    int next_process(struct process *proc, int nproc);
};

class RR_Scheduler: public Scheduler {
    int next_process(struct process *proc, int nproc);
};

#endif
