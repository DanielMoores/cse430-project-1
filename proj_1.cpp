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

    // Rotations
    q->rotate();
    q->rotate();
    q->rotate();
    q->rotate();
    q->rotate();
    q->rotate();
    // starts over at this point
    q->rotate();
    q->rotate();

    std::cout << "\nPrint\n";
    q->print();

    std::cout << "\n\nPOPS: ";
    std::cout << "\n1" << std::endl;
    q->pop()->print();
    std::cout << "\n2" << std::endl;
    q->pop()->print();
    std::cout << "\n3" << std::endl;
    q->pop()->print();
    std::cout << "\n4" << std::endl;
    q->pop()->print();
    std::cout << "\n5" << std::endl;
    q->pop()->print();
    std::cout << "\n6" << std::endl;
    q->pop()->print();
    /* calling print on null (since queue is empty and therefore the object is null) causes seg fault. */
    //std::cout << "\n7" << std::endl;
    //q->pop()->print();

    QElement * e7 = new QElement(7);
    QElement * e8 = new QElement(8);
    QElement * e9 = new QElement(9);
    q->push(e7);
    q->push(e8);
    q->push(e9);

    q->rotate(5);

    std::cout << "\n\nIteration\n";
    q->iterate(3);

    std::cout << "\n\n\nStart Printing." << std::endl;
    q->print();
    std::cout << "End printing." << std::endl;

    std::cout << std::endl << std::endl << "Finish";

    return 0;
}