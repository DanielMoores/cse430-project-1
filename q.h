//
// Created by tyler on 9/29/2015.
//

#ifndef CSE430_PROJECT_1_Q_H
#define CSE430_PROJECT_1_Q_H

#include <string>
#include <iostream>
#include <climits>  // For max values of ints

class QElement
{
    private:

        QElement * previous;
        QElement * next;
        int payload;

    public:

        // Default Constructor
        QElement()
        {
            payload = INT_MAX;
            previous = next = NULL;
        }

        // Constructor
        QElement(int p)
        {
            payload = p;
            previous = next = NULL;
        }

        // Destructor
        ~QElement()
        {
            // No memory allocated
            // Nothing to take care of
        }

        // Get previous element
        QElement * getPrevious()
        {
            return previous;
        }

        // Get next element
        QElement * getNext()
        {
            return next;
        }

        // Get payload
        int getPayload()
        {
            return payload;
        }

        // Set previous
        void setPrevious(QElement * p)
        {
            previous = p;
        }

        // Set next
        void setNext(QElement * n)
        {
            next = n;
        }

        // Set payload
        void setPayload(int p)
        {
            payload = p;
        }

        // ToString
        void print()
        {
            std::cout << "Payload: " << payload;
        }
};

class Queue
{
    private:

        QElement * head;
        QElement * tail;
        int size;

    public:

        // Default Constructor
        Queue()
        {
            head = tail = NULL;
            size = 0;
        }

        // Destructor
        ~Queue()
        {
            // Iterate through list and delete elements
            QElement * temp = head;
            while(temp != NULL){
                temp = head;
                head = head->getNext();
                delete temp;
                temp = NULL; // Not necessary
            }
        }

        // Returns head element without removing it
        QElement * peek()
        {
            return head;
        }

        // Get tail

        // Adds element to back of Queue
        bool push(QElement * element)
        {
            if(head == NULL)
            {
                head = tail = element;
                // To make queue circular
                head->setPrevious(tail);
                tail->setNext(head);
            }
            else
            {
                tail->setNext(element);
                element->setPrevious(tail);
                tail = tail->getNext();
                // To make queue circular
                tail->setNext(head);
                head->setPrevious(tail);
            }
            size++;
            return true;
        }

        // Removes and returns element at front of Queue
        QElement * pop()
        {
            if(head == NULL)
            {
                std::cout << "Error: Queue is empty" << std::endl;
                return NULL;
            }
            else
            {
                QElement * temp = head;

                // Only one element in Queue
                if(size == 1)
                {
                    head = NULL;
                }
                // Multiple elements in Queue
                else{
                    head = head->getNext();
                    // head->setPrevious(NULL); // Normal Queue
                    // To make queue circlular
                    head->setPrevious(tail);
                    tail->setNext(head);
                }
                size--;
                return temp;
            }
        }

        // Removes element from front of queue and puts at back
        bool rotate(){
            // No elements in Queue, error
            if(size == 0){
                std::cout << "Error: Queue is empty" << std::endl;
                return false;
            }
            // One element in Queue, already in rotated state
            else if(size == 1){
                std::cout << "Error: No need to rotate, only 1 element" << std::endl;
                return true;
            }
            // Multiple elements in Queue
            else{
                QElement * temp = head;
                head = head->getNext();
                tail->setNext(temp);
                temp->setPrevious(tail); // Not necessary I think, as previous is already set to tail
                tail = tail->getNext();
                // To make queue circular
                head->setPrevious(tail);
                tail->setNext(head); // Again, not necessary I think, as next is already set to head
                return true;
            }
        }

        int getSize()
        {
            return size;
        }

        void print()
        {
            if(head == NULL)
            {
                std::cout << "Empty queue" << std::endl;
            }
            else
            {
                QElement * temp = head;

                for(int i = 0; i < size; i++){
                    temp->print();
                    std::cout << std::endl;
                    temp = temp->getNext();
                }
            }
        }

    void iterate(int numTimes){
        QElement * temp = head;
        for(int i = 0; i < size * numTimes; i++)
        {
            temp->print();
            std::cout << std::endl;
            temp = temp->getNext();
        }
    }

    void rotate(int numTimes)
    {
        for(int i = 0; i < numTimes; i++)
        {
            rotate();
        }
    }

};

#endif //CSE430_PROJECT_1_Q_H
