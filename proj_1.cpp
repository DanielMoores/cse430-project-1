#include <iostream>
#include "q.h"

int main() {

    //std::cout << "Start." << std::endl;

    //std::cout << "Create new queue." << std::endl;
    Queue * q = new Queue();
    //std::cout << "New Queue created." << std::endl;

    //std::cout << "Create element 1" << std::endl;
    QElement * e1 = new QElement(1);
    //std::cout << "Element 1 created." << std::endl;

    //std::cout << "Create element 2" << std::endl;
    QElement * e2 = new QElement(2);
    //std::cout << "Element 2 created." << std::endl;

    //std::cout << "Create element 3" << std::endl;
    QElement * e3 = new QElement(3);
    //std::cout << "Element 3 created." << std::endl;

    //std::cout << "Create element 4" << std::endl;
    QElement * e4 = new QElement(4);
    //std::cout << "Element 4 created." << std::endl;

    //std::cout << "Create element 5" << std::endl;
    QElement * e5 = new QElement(5);
    //std::cout << "Element 5 created." << std::endl;

    //std::cout << "Create element 6" << std::endl;
    QElement * e6 = new QElement(6);
    //std::cout << "Element 6 created." << std::endl;

    //std::cout << "Push e1 onto queue." << std::endl;
    q->push(e1);
    //std::cout << "e1 pushed onto queue." << std::endl;

    //std::cout << "Push e2 onto queue." << std::endl;
    q->push(e2);
    //std::cout << "e2 pushed onto queue." << std::endl;

    //std::cout << "Push e3 onto queue." << std::endl;
    q->push(e3);
    //std::cout << "e3 pushed onto queue." << std::endl;

    //std::cout << "Push e4 onto queue." << std::endl;
    q->push(e4);
    //std::cout << "e4 pushed onto queue." << std::endl;

    //std::cout << "Push e5 onto queue." << std::endl;
    q->push(e5);
    //std::cout << "e5 pushed onto queue." << std::endl;

    //std::cout << "Push e6 onto queue." << std::endl;
    q->push(e6);
    //std::cout << "e6 pushed onto queue." << std::endl;

    std::cout << "Count number of elements." << std::endl;
    std::cout << q->getSize() << std::endl;
    std::cout << "Elements counted." << std::endl;

    /*
    QElement * temp = q->peek();
    int i = 0;
    while(temp != NULL){
        temp = temp->getNext();
        i++;
        //std::cout << i << std::endl;
    }
    */

    int numRotations = 8;
    std::cout << std::endl << std::endl << "Perform " << numRotations << " rotations";
    /* Each set of n rotations, where n is the number of elements in the queue,
     * the order of the queue resets. In this case, there are 6 elements in the
     * queue, and 8 rotations, so it is the same as performing 2 rotations, so
     * the queue now starts with element #3, and #1 - #2 are at the end of the
     * queue. */
    q->rotate(numRotations);
    std::cout << std::endl << "Rotations complete" << std::endl;

    std::cout << std::endl << std::endl << "Print" << std::endl;
    q->print();

    std::cout << std::endl << "POPS ";
    std::cout << std::endl << "Pop 1:" << std::endl;
    q->pop()->print();
    std::cout << std::endl << "Pop 2:" << std::endl;
    q->pop()->print();
    std::cout << std::endl << "Pop 3:" << std::endl;
    q->pop()->print();
    std::cout << std::endl << "Pop 4:" << std::endl;
    q->pop()->print();
    std::cout << std::endl << "Pop 5:" << std::endl;
    q->pop()->print();
    std::cout << std::endl << "Pop 6:" << std::endl;
    q->pop()->print();
    /* calling print on null (since queue is empty and therefore the object is null) causes seg fault. */
    //std::cout << "\n7" << std::endl;
    //q->pop()->print();


    std::cout << std::endl << std::endl << std::endl << "Add 3 new elements to the empty queue, ";
    std::cout << std::endl << "Elements 7, 8, and 9." << std::endl;
    QElement * e7 = new QElement(7);
    QElement * e8 = new QElement(8);
    QElement * e9 = new QElement(9);
    q->push(e7);
    q->push(e8);
    q->push(e9);

    int rotations = 5;
    std::cout << std::endl << std::endl << "Rotate " << rotations << " times" << std::endl;
    q->rotate(5);

    int iterations = 3;
    std::cout << std::endl << std::endl << "Iterate " << iterations << " times to test the functionality " << std::endl;
    std::cout << "of the queue being circular" << std::endl;
    q->iterate(iterations);

    std::cout << std::endl << std::endl << std::endl << "Start Printing." << std::endl;
    q->print();
    std::cout << "End printing." << std::endl << std::endl;

    std::cout << "Freeing memory." << std::endl;

    delete q; // Free memory allocated to the queue and its elements.

    std::cout << std::endl << std::endl << "Finished";

    return 0;
}