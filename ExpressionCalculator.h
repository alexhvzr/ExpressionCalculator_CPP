//
// Created by Alex on 10/28/2018.
//

#ifndef ASSIGNMENT3_EXPRESSIONCALCULATOR_H
#define ASSIGNMENT3_EXPRESSIONCALCULATOR_H

#include "StackArray.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class ExpressionCalculator {
    string input;
    int result = 0;
    StackArray<int> *stack;
public:
    void runCalculator() {
        cout << "Enter the expression: ";
        getline(cin, input);
        //making a stack array at the length of the input guarantee that the stack will have enough size
        stack = new StackArray<int>(input.length());
        //splits the string at the spaces to have individual expressions being passed
        istringstream iss(input);
        vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());

        //loop through vector of string inputs
        for (int i = 0; i < results.size();) {
            int found;
            string temp;
            while (temp != "\\") {
                //checks to see if the input was an integer, if it is, push it into the stack
                if (stringstream(temp) >> found) {
                    stack->push(found);
                }
                //adds the top two elements of the stack
                if (temp == "+" && stack->getFilledSize() >= 2) {
                    int a = stack->top();
                    stack->pop();
                    int b = stack->top();
                    stack->pop();
                    result = (a + b);
                    stack->push(result);
                } else if (temp == "+" && stack->getFilledSize() <= 2) {
                    cout << "Missing Operands" << endl;
                }
                //subtracts the top two elements of the stack
                if (temp == "-" && stack->getFilledSize() >= 2) {
                    int a = stack->top();
                    stack->pop();
                    int b = stack->top();
                    stack->pop();
                    result = (b-a);
                    stack->push(result);
                } else if (temp == "-" && stack->getFilledSize() <= 2) {
                    cout << "Missing Operands" << endl;
                }
                //multiplies the top two elements of the stack
                if (temp == "*" && stack->getFilledSize() >= 2) {
                    int a = stack->top();
                    stack->pop();
                    int b = stack->top();
                    stack->pop();
                    result = (a * b);
                    stack->push(result);
                } else if (temp == "*" && stack->getFilledSize() <= 2) {
                    cout << "Missing Operands" << endl;
                }
                //multiplies the top two elements of the stack
                if (temp == "/" && stack->getFilledSize() >= 2) {
                    int a = stack->top();
                    stack->pop();
                    int b = stack->top();
                    stack->pop();
                    result = (b/a);
                    stack->push(result);
                } else if (temp == "/" && stack->getFilledSize() <= 2) {
                    cout << "Missing Operands" << endl;
                }
                //prints the stack
                if (temp == "<<") {
                    cout << *stack;
                }
                //prints the top element of the stack and pops it
                if (temp == "^") {
                    cout << stack->top() << endl;
                    stack->pop();
                }
                //checks if the input is anything that begins with an ANSII character set
                if (isalpha(temp.front())) {
                    cout << "Invalid Input" << endl;
                }
                temp = results[i];
                i++;
            }
            break;
        }
        cout << "Result: " << result <<endl;
    }
};


#endif //ASSIGNMENT3_EXPRESSIONCALCULATOR_H
