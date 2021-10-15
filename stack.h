/*
 * Daniel Cardin
 * Coding04
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    Stack();  //Constructor
    bool push(int, const string&);  //takes an ID and a pointer to a string
    bool pop(Data*);  //takes a pointer to a struct, which struct it will modify with the "return" data
    bool peek(Data*);  //same as pop but no decrement
    bool isEmpty();  //just checks to see pop is -1 or not, so no parameters
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H
