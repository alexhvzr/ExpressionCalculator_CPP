//
// Created by Alex on 10/28/2018.
//

#ifndef ASSIGNMENT3_STACKADT_H
#define ASSIGNMENT3_STACKADT_H

template <class T>
class StackADT{
    virtual void pop()=0;
    virtual void push(T&)=0;
    virtual T top()=0;
    virtual void initialize()=0;
    virtual bool isFull()=0;
    virtual bool isEmpty()=0;
};





#endif //ASSIGNMENT3_STACKADT_H
