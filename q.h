#ifndef CSE430_PROJECT_1_Q_H
#define CSE430_PROJECT_1_Q_H

#include <string>
#include <iostream>
#include <climits>  // For max values of ints

// QElement class is like a Node class
class QElement
{
    private:
        // Linked structures need a previous and next pointer
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

        // Print
        void print()
        {
            std::cout << "Payload: " << payload;
        }
};

// Doubly-Linked, Circular Queue
class Queue
{
    private:
        /* Doubly-Linked structures need reference to head and tail.
         * Size is needed because the structure is circular, we cannot
         * rely on iterating till the "end" of the queue or else we
         * would be stuck in an infinite loop. */
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
            while(temp != NULL)
            {
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

        // Adds element to back of Queue
        void push(QElement * element)
        {
            // No elements in Queue
            if(head == NULL)
            {
                // Both head and tail should point to the same object
                head = tail = element;

                // To make queue circular
                head->setPrevious(tail);
                tail->setNext(head);
            }
            // One or more elements in Queue
            else
            {
                /* Add the element to the end of the Queue,
                 * Set the new elements's previous pointer to the existing tail,
                 * Set the tail to it's next pointer, which is the new element. */
                tail->setNext(element);
                element->setPrevious(tail);
                tail = tail->getNext();

                // To make queue circular
                tail->setNext(head);
                head->setPrevious(tail);
            }
            size++;
        }

        // Removes and returns element at front of Queue
        QElement * pop()
        {
            // No elements in Queue
            if(head == NULL)
            {
                std::cout << "Error: Queue is empty" << std::endl;
                return NULL;
            }
            // One or more elements in Queue
            else
            {
                /* We will always return the head element,
                 * so grab it now */
                QElement * temp = head;

                /* Only one element in Queue.
                 * We cannot rely on head->getNext() == NULL
                 * because it is a circular Queue. */
                if(size == 1)
                {
                    head = NULL;
                }
                // Multiple elements in Queue
                else
                {
                    // Set head to the next element in Queue
                    head = head->getNext();
                    // head->setPrevious(NULL); // Normal Queue

                    // To make queue circular
                    head->setPrevious(tail);
                    tail->setNext(head);
                }
                size--;
                return temp;
            }
        }

        // Removes element from front of queue and puts at back
        bool rotate()
        {
            // No elements in Queue, error
            if(size == 0)
            {
                std::cout << "Error: Queue is empty" << std::endl;
                return false;
            }
            // One element in Queue, already in rotated state
            else if(size == 1)
            {
                std::cout << "Error: No need to rotate, only 1 element" << std::endl;
                return true;
            }
            // Multiple elements in Queue
            else
            {
                /* Could use the following code, but there are
                 * some redundancies that would make it a bit
                 * inefficient:
                 *
                 * QElement * temp = pop();
                 * push(temp);
                 *
                 * In the old code, I essentially popped() the
                 * element off and pushed() the element back on,
                 * with a few unnecessary steps cut out. However,
                 * after closer inspection, I realized the only
                 * steps necessary were to set the head equal to
                 * its next, and the tail equal to its next. Since
                 * the Queue is circular, things like circling back
                 * to the head just take care of themselves.
                 *
                 * Pretty neat!
                 * */
                head = head->getNext();
                tail = tail->getNext();
                return true;
            }
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return (size == 0);
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

                for(int i = 0; i < size; i++)
                {
                    temp->print();
                    std::cout << std::endl;
                    temp = temp->getNext();
                }
            }
        }

        /* Iterates through the Queue the specified
         * number of times. This helps to make sure
         * the Queue's "circularity" is working
         * properly, and all links are valid. */
        void iterate(int numTimes)
        {
            QElement * temp = head;
            for(int i = 0; i < size * numTimes; i++)
            {
                temp->print();
                std::cout << std::endl;
                temp = temp->getNext();
            }
        }

        /* Rotates the Queue the specified
         * number of times instead of needing
         * to call it manually that number of
         * times. */
        void rotate(int numTimes)
        {
            for(int i = 0; i < numTimes; i++)
            {
                rotate();
            }
        }
};

#endif //CSE430_PROJECT_1_Q_H
