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

#include <stdio.h>
#include <unistd.h> // Used for sleep()
#include "threads.h"

#define true 1
#define false 0
#define SLEEP_TIME 1 // in seconds

// Global variable to modify in the threads
int global = 0;

void func1();
void func2();
void func3();

int main()
{
    printf("Creating Queue\n");
    runQ = InitQueue();

    printf("Initializing Threads\n");
    start_thread(func1);
    start_thread(func2);
    start_thread(func3);

    printf("Start Program\n\n");
    run();

    // Will never reach code past this point.

    printf("Freeing memory");
    FreeQueue(runQ);

    printf("Finished\n\n");
    return 0;
}

void func1()
{
    int i = 0;
    while(true)
    {
        printf("Func1 -> i: %d\n", i);
        printf("Func1 -> global: %d\n\n", global);
        i++;
        global++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        yield();
    }
}

void func2()
{
    int j = 0;
    while(true)
    {
        printf("Func2 -> j: %d\n", j);
        printf("Func2 -> global: %d\n\n", global);
        j++;
        global++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        yield();
    }
};

void func3()
{
    int k = 0;
    while(true)
    {
        printf("Func3 -> k: %d\n", k);
        printf("Func3 -> global: %d\n\n", global);
        k++;
        global++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        yield();
    }
};
