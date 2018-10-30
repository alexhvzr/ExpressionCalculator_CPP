//
// Created by Alex on 10/28/2018.
//

#ifndef ASSIGNMENT3_STACKARRAY_H
#define ASSIGNMENT3_STACKARRAY_H

#include "StackADT.h"
#include <iostream>
#include <assert.h>

using namespace std;

int DEFAULT_STACK_SIZE =100;

template <class T>
class StackArray : public StackADT<T>{
    //private data members
    T* data;
    int sTop, size;
public:
    //default constructor
    StackArray(int _size = DEFAULT_STACK_SIZE){
        size = _size;
        data = new T[size];
        sTop = 0;
    }

    int getFilledSize() const {
        return sTop;
    }

//    StackArray(){
//        cout << "initiallized 2" << endl;
//        size = DEFAULT_STACK_SIZE;
//        data = new T[size];
//        sTop = 0;
//    }
    void initialize(){
        sTop = 0;
    }
    bool isEmpty(){
        return sTop == 0;
    }
    bool isFull(){
        return sTop == size;
    }
    T top(){
        return data[sTop-1];
    }
    void pop(){
        assert(!isEmpty());
        sTop--;
    }
    void push(T& item){
        assert(!isFull());
        data[sTop] = item;
        sTop++;
    }
    void copyStack(const StackArray& other){
        //delete all the old data so that you have no memory leak
        delete[] data;
        //increment size to match other stack
        size = other.size;
        //create the new stack array
        data = new T[size];
        //make sure you access the same element at the top of the stack
        sTop = other.sTop;
        //Loop through elelments and add it to the new stack
        for (int i =0; i < sTop; i++){
            data[1] = other.data[i];
        }

    }
    friend ostream& operator<<(ostream& os, StackArray& stack){
        os << "<";
        if(stack.isEmpty()){

        }else {
            for (int i = 0; i < stack.sTop-1; i++) {
                os << stack.data[i] << ", ";
            }
           os << stack.data[stack.sTop-1];
        }
        os <<">" <<endl;
        return os;
    }

    //Assignment operator
    StackArray operator=(const StackArray& other){
        if (this != other){
            copyStack(other);
        }
        return *this;
    }
    //Copy constructor
     StackArray(const StackArray& other){
            copyStack(other);
    }
    //Destructor
    ~StackArray(){
        delete[] data;
    }


};










#endif //ASSIGNMENT3_STACKARRAY_H
