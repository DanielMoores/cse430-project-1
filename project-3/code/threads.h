/*===========================================
 *  Authors:
 *      Tyler Brockett
 *      Man Do
 *  Project:
 *      Project 3
 *  Description:
 *      Implement semaphores.
 *  Class:
 *      CSE 430 Operating Systems - Partha Dasgupta
 *  Organization:
 *      Arizona State University
 ============================================*/

#ifndef CSE430_PROJECT_3_THREADS_H
#define CSE430_PROJECT_3_THREADS_H

#include <stdlib.h>
#include "q.h"

void start_thread(void (*function)(void))
{
    /* allocate a stack (via malloc) of a certain size
     * (choose 8192) */
    int stack_size = 8192;
    void * stackP = malloc(stack_size);

    // allocate a TCB (via malloc)
    TCB_t * tcb = NewItem();

    // call init_TCB with appropriate arguments
    init_TCB(tcb, function, stackP, stack_size);

    /* call addQ to add this TCB into the “RunQ” which is a
     * global header pointer */
    AddQueue(runQ, tcb);
}

void run()
{
    ucontext_t parent;  // Get a place to store the main context, for faking
    getcontext(&parent);    // Magic sauce
    swapcontext(&parent, &runQ->head->context); // Start the first thread.
}

void yield()
{
    ucontext_t current_context; // Variable to save current context to
    getcontext(&current_context);   // Get the current context
    runQ->head->context = current_context;  // Store current context to head node
    RotateQ(runQ);  // Rotate Queue
    ucontext_t new_context = runQ->head->context;   // Get the new context
    swapcontext(&current_context, &new_context);    // Perform context switch
}

#endif //CSE430_PROJECT_3_THREADS_H
