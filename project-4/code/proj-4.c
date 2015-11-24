


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

#include <stdio.h>
#include <unistd.h> // Used for sleep()
#include <time.h>
#include "sem.h"


#define METHOD_2 2

#define NUM_READER 3
#define NUM_WRITER 2

#define NUM_RESOURCES 1 // Should be LESS than the number of threads running, to create "competition"

#define SLEEP_TIME 1 // in seconds

int global = 0;
Semaphore * s;

void reader();
void writer();

int wwc, wc, rwc, rc = 0;	//waiting write count, waiting count, reader waiting count, reader count

Semaphore *mutex = NULL;
Semaphore *rsem = NULL;
Semaphore *wsem = NULL;

void reader();
void writer();

// Other method forward declarations
void printQ();

int main()
{
    runQ = InitQueue();

    printf("Project 4");
    mutex = InitSem(1);
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

void reader(){
	while(1){
		//Reader Entry
		printf("\n[reader #%p]\tentering CS\n", runQ);
		P(mutex);
		if(wwc>0 || wc>0){
			printf("\n[reader #%p]\tneed to wait for a writer to finish.", runQ);
			rwc++;
			V(mutex);
			P(rsem);
			printf("\n[reader #%p]\twaking up.", runQ);
			rwc--;
		}
		rc++;
		if(rwc>0)
			V(rsem);
		else
			V(mutex);
		printf("\n[reader #%p]\tgoing into CS.", runQ);

		//Reader Exit
		printf("\n[reader #%p]\texiting, get mutex", runQ);
		P(mutex);
		rc--;
		printf("\n[reader #%p]\tleaving", runQ);
		if(rc==0 && wwc>0)
			V(wsem);
		else
			V(mutex);
	}
}

void writer(){
	while(1){
		//Writer Entry
		printf("\n[writer #%p]\tentering CS\n", runQ);
		P(mutex);
		if(rc>0 || wc>0){
			printf("\n[writer #%p]\tincreasing 1 to wwc.", runQ);
			wwc++;
			V(mutex);
			P(wsem);
			printf("\n[writer #%p]\twaking up.", runQ);
			wwc--;
		}
		wc++;
		V(mutex);
		printf("\n[writer #%p]\tgoing into CS.", runQ);
		//Writer Exit
		printf("\n[writer #%p]\texiting", runQ);
		P(mutex);
		wc--;
		if(rwc>0){
			printf("\n[writer #%p]\tremoving a reader.", runQ);
			V(rsem);
		}
		else if(wwc>0){
			printf("\n[writer #%p]\tremoving a writer", runQ);
			V(wsem);
		}
		else{
			printf("\n[writer #%p]\treleasing the resource.", runQ);
			V(mutex);
		}
	}
}

/*void printQ()
{
	int i = 0;
    printf("\n[program state]\t\twwc:%d wrc:%d wc:%d rc:%d\n", wwc, rwc,
	   wc, rc);
    if (i < NUM_READER + NUM_WRITER) {
	printf("  running process is ");
	if (runQ >= 50)
	    printf("a writer, ");
	else
	    printf("a reader, ");
	printf("#%p\n", runQ);
    }
    i++;
}*/
