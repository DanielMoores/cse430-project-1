//==================================================================
//  Authors:
//      Man Do
//      Tyler Brockett
//  Assignment:
//      Homework 3
//  Due Date:
//      11-16-2015
//==================================================================


//------------------------------
// 	Problem 1A
//------------------------------

void shift(int *A, int *B){
    *B = *A;
    *A = 0;
}

typedef struct Semaphore
{
    int value, lock;	//value act as a counter
} Semaphore;

void P(Semaphore *S) {
    while () {        //lock, atomic
        shift();    //lock, atomic
    }
    while (S->value == 0) {
        S->lock = 0;    //unlock
        while () {        //lock, atomic
            shift();    //lock, atomic
        }
    }
    S->value--;
    S->lock = 0;    //unlock
}

void V(Semaphore *S) {
    while () {        //lock, atomic
        shift();    //lock, atomic
    }
    S->value++;
    S->lock = 0;  //unlock
}



//------------------------------
// 	Problem 1B
//------------------------------

typedef struct Semaphore
{
    int value, lock;
    Queue * tcb_queue;
} Semaphore;

P(Semaphore *S):	//aka Down or Wait
	while(){		//lock, atomic
		shift();	//lock, atomic
	}
	S->value--;
	if (S->value < 0){
		addQ(S->tcb_queue, delQ(RunQ));
		S->lock = 0;  		//unlock
		swapcontext()		//block()? maybe?
	}

V(Semaphore *S):	//aka Up or Signal
	while(){		//lock, atomic
		shift();	//lock, atomic
	}
	S->value++
	if (S->value <= 0){
		AddQ(RunQ, delQ(S->tcb_queue));
	}
	//yeild();
	S->lock = 0;  //unlock



//------------------------------
// 	Problem 3
//------------------------------

Enq(r):
	while(){		//lock, atomic
		shift();	//lock, atomic
	}
	if ()



//------------------------------
// 	Problem 2
//------------------------------

int x = 0;
int s1 = 1;
int s2 = 0;

P0:
	p(s1);
	x++;
	v(s2);

P1:
	P(s2);
	if(x%1==0)
		print(x);
	V(s1);

P2:
	P(s2);
	if(x%2==0)
		print(x);
	V(s1);

P3:
	P(s2);
	if(x%3==0)
		print(x);
	V(s1);
