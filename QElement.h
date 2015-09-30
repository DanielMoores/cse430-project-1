//
// Created by tyler on 9/29/2015.
//

#ifndef CSE430_PROJECT_1_QELEMENT_H
#define CSE430_PROJECT_1_QELEMENT_H

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
        // Constructor/Destructor
        QElement();
        QElement(int p);
        ~QElement();

        // Getters
        QElement * getPrevious();
        QElement * getNext();
        int getPayload();

        // Setters
        void setPrevious(QElement * p);
        void setNext(QElement * n);
        void setPayload(int p);


    // Other functions
        std::string toString();
};

/* ============================
 *   Constructor/Destructor
 * ============================
 */
QElement::QElement()
{
    payload = INT_MAX;
}

QElement::QElement(int p)
{
    payload = p;
}

QElement::~QElement(){
    // No memory allocated
    // Nothing to take care of
}

/* ============================
 *          Getters
 * ============================
 */
QElement * QElement::getPrevious()
{
    return previous;
}

QElement * QElement::getNext()
{
    return next;
}

int QElement::getPayload()
{
    return payload;
}

/* ============================
 *          Setters
 * ============================
 */
void QElement::setPrevious(QElement * p)
{
    previous = p;
}

void QElement::setNext(QElement * n){
    next = n;
}

void QElement::setPayload(int p)
{
    payload = p;
}

/* ============================
 *      Other Functions
 * ============================
 */
std::string QElement::toString(){
    return "Payload: " + payload + '\n';
}

#endif //CSE430_PROJECT_1_QELEMENT_H
