#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>
#include "util.h"
#include "scheduler.h"

int main(int argc, char* argv[])
{

	char sched_policy[256];
	int nproc;
	struct process *proc;

	scanf("%s", sched_policy);
	scanf("%d", &nproc);
	
	proc = (struct process *)malloc(nproc * sizeof(struct process));

	for (int i = 0; i < nproc; i++) {
		scanf("%s%d%d", proc[i].name,
			&proc[i].t_ready, &proc[i].t_exec);
	}

	if (strcmp(sched_policy, "FIFO") == 0) {
		auto scheduler = FIFO_Scheduler();
		scheduler.scheduling(proc, nproc);
	}
	else if (strcmp(sched_policy, "RR") == 0) {
		auto scheduler = RR_Scheduler();
		scheduler.scheduling(proc, nproc);
	}
	else if (strcmp(sched_policy, "SJF") == 0) {
		auto scheduler = SJF_Scheduler();
		scheduler.scheduling(proc, nproc);
	}
	else if (strcmp(sched_policy, "PSJF") == 0) {
		auto scheduler = PSJF_Scheduler();
		scheduler.scheduling(proc, nproc);
	}
	else {
		fprintf(stderr, "Invalid policy: %s", sched_policy);
		exit(0);
	}

	exit(0);
}
