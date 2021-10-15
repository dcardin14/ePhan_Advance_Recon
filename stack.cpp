/*
 * Daniel Cardin 
 * Coding04
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly!
#include "stack.h"

//---Constructor
Stack::Stack()
{
  top = -1; //Starts out empty
} //end of constructor

//---push()
bool Stack::push(int idInput, const string &input)  //takes an ID and a pointer to a 2d character array
{
  bool pushOK = false;
  if(idInput > 0 && input != "" && top < STACK_SIZE - 1)  //positive int, nonempty string and stack is not full already
  {
    top++;
    stack[top] = new Data; // allocating a dynamic struct data -- see 1:08 in the 6/18 lecture
    stack[top]->id = idInput; //set the value of the id property for the struct at the top to the stack to whatever the id paramter was
    stack[top]->information = input;
    pushOK = true;
  }//end of if 
  return pushOK;
} //end of push()

//---pop()
bool Stack::pop(Data *poppedStructData)  //takes a pointer to a struct, which struct it will modify with the "return" data
{
  bool popOK = false;
  if(top > -1)
  {
   poppedStructData->id = stack[top]->id ; //assign the value of the passed-By-Reference struct to the value of the struct data whose pointer resides currently on the top of the stack
   poppedStructData->information = stack[top]->information;
   delete stack[top]; //delete the allocated memory from the top of the stack
   top--; //decrement the top
   popOK = true;
  }
  else
  {
     poppedStructData->id = -1; //assign the value of the passedByReference struct to the value of the struct data whose pointer resides currently on the top of the stack
     poppedStructData->information = "";
  }
  
  return popOK;
} //end of pop()

//---peek()
bool Stack::peek(Data *peekedStructData)  //same as pop but no decrement
{
  bool peekOK = false;
  if(top > -1)
  {
    peekedStructData->id = stack[top]->id;
    peekedStructData->information = stack[top]->id;
    peekOK = true;
  }
  else
  {
    peekedStructData->id = -1;
    peekedStructData->information = "";
  }
  return peekOK;
} //end of peek

//---isEmpty()
bool Stack::isEmpty()  //just checks to see pop is -1 or not, so no parameters
{
  return top < 0;
} //end of isEmpty()
