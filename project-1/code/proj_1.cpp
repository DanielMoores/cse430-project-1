#include <iostream>
#include <limits>
#include <stdio.h>
#include "q.h"

#define PRINT_MENU 0
#define NEW_QUEUE 1
#define NEW_ELEMENT 2
#define POP 3
#define COUNT 4
#define ITERATE 5
#define ROTATE 6
#define ROTATE_N 7
#define PRINT 8
#define QUIT 9

#define ERROR_QUEUE_NULL "Error: Queue does not exist. Please create it first."
#define ERROR_QUEUE_EMPTY "Error: Queue does not exist. Please create it first."
#define ERROR_INVALID_INPUT "Error: Invalid input. Please try again."


void printMenu();
void printQueue();
int getInput(std::string message);
void error(std::string errorMessage);

Queue * q;

int main()
{
    int command;
    printMenu();
    command = getInput("Please type a command (0 for menu): ");

    while(command != QUIT && command != EOF)
    {
        switch(command)
        {
            case PRINT_MENU:
            {
                printMenu();
                break;
            }
            case NEW_QUEUE:
            {
                delete q;
                q = new Queue();
                break;
            }
            case NEW_ELEMENT:
            {
                if(q != NULL)
                {
                    int payload = getInput("\nEnter payload: ");
                    QElement * e = new QElement(payload);
                    q->push(e);
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            case POP:
            {
                if(q != NULL)
                {
                    QElement * e = q->pop();
                    if(e != NULL)
                    {
                        printf("\nPopped Payload: ");
                        e->print();
                        printf("\n");
                    }
                    else
                    {
                        error(ERROR_QUEUE_EMPTY);
                    }
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            case COUNT:
            {
                if(q != NULL)
                {
                    printf("\nQueue Size: %d\n", q->getSize());
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            case ITERATE:
            {
                if(q != NULL)
                {
                    int n = getInput("\nHow many times? ");
                    q->iterate(n);
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            case ROTATE:
            {
                if(q != NULL)
                {
                    q->rotate();
                    printf("\nQueue has been rotated.\n");
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            case ROTATE_N:
            {
                if(q != NULL)
                {
                    int n = getInput("\nHow many times? \n");
                    q->rotate(n);
                    printf("Queue has been rotated %d time(s)\n", n);
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            case PRINT:
            {
                if(q != NULL)
                {
                    q->print();
                }
                else
                {
                    error(ERROR_QUEUE_NULL);
                }
                break;
            }
            default:
            {
                error(ERROR_INVALID_INPUT);
                break;
            }
        }
        printQueue();
        command = getInput("\nPlease type a command (0 for menu): ");
    }

    delete q;
    printf("\n\nProgram Terminated.\n");

    return 0;
}

int getInput(const std::string message)
{
    int command = -1;
    printf("%s", message.c_str());
    while (!(std::cin >> command))
    {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        printf("%s\n", ERROR_INVALID_INPUT);
    }
    return command;
}

void printQueue()
{
    printf("\n");
    if(q != NULL)
    {
        q->print();
    }
    else
    {
        error(ERROR_QUEUE_NULL);
    }
    printf("\n");
}

void printMenu()
{
    printf("============================================\n");
    printf("  DOUBLY LINKED, CIRCULAR QUEUE OPERATIONS  \n");
    printf("============================================\n");
    printf("0 - Print menu\n");
    printf("1 - Start new queue\n");
    printf("2 - Add new element to queue\n");
    printf("3 - Pop element from queue\n");
    printf("4 - Count number of elements in queue\n");
    printf("5 - Iterate through queue N number of times\n");
    printf("6 - Rotate queue\n");
    printf("7 - Rotate queue N number of times\n");
    printf("8 - Print queue\n");
    printf("9 - Quit\n");
    printf("\n");
}

void error(const std::string errorMessage)
{
    printf("%s\n", errorMessage.c_str());
}