/*===========================================
 *  Authors:
 *      Tyler Brockett
 *      Man Do
 *  Project:
 *      Project 2
 *  Description:
 *      Using the queuing routines (not all will be used)
 *      this project will implement the ability to run
 *      multiple functions as threads, using non-preemptive
 *      scheduling.
 *  Class:
 *      CSE 430 Operating Systems - Partha Dasgupta
 *  Organization:
 *      Arizona State University
 ============================================*/

#ifndef CSE430_PROJECT_2_TCB_H
#define CSE430_PROJECT_2_TCB_H

#include <ucontext.h>
#include <string.h>

typedef struct TCB_t {
    struct TCB_t *next;
    struct TCB_t *prev;
    ucontext_t context;
} TCB_t;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
}

#endif //CSE430_PROJECT_2_TCB_H
