/*===========================================
 *  Authors:
 *      Tyler Brockett
 *      Man Do
 *  Project:
 *      Project 4
 *  Description:
 *      Readers and Writers
 *  Class:
 *      CSE 430 Operating Systems - Partha Dasgupta
 *  Organization:
 *      Arizona State University
 ============================================*/

#include <stdio.h>
#include <unistd.h> // Used for sleep()
#include "sem.h"

int main()
{
    printf("Project 4");
    mutex = InitSem(0);
    rsem = InitSem(0);
    wsem = InitSem(0);

    start_thread(writer);
    start_thread(writer);
    start_thread(reader);
    start_thread(reader);
    start_thread(reader);

    run();

    return 0;
}