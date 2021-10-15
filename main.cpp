/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
/*    std::string ths = "truly";
    stack.push(10,&mystring);
    Data repeat;
    stack.pop(&repeat);
    std::cout << "*****" <<  repeat.id << "-----" << repeat.information << std::endl;
    std::cin.get();
 */   
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    std::cout << "***************************************" << std::endl;
    std::cout << "The stack is empty and when I call isEmpty(), it returns:  " << stack.isEmpty() << std::endl;
    Data holder; // create a struct to pass-by-reference
    stack.peek(&holder);
    std::cout << "The stack is empty and when I call peek(), it returns:     " << holder.id << ":  " << holder.information << std::endl; 
    stack.pop(&holder);
    std::cout << "The stack is empty and when I call pop(), it returns:      " << holder.id << ":  " << holder.information << std::endl;

    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */

    std::cout << std::endl << "***************************************" << std::endl;
    std::cout << std::left << std::setw(23) << "ACTION:  " << std::setw(3) << std::right << "ID:    " << "INFORMATION:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for(int i=0; i < number_test_cases; i++)
    {
     if(stack.push(ids[i],data[i]))
      {
        cout << std::setw(10) << std::left << "PUSHTEST " << i + 1 << ":  SUCCEEDED PUSHING "  << std::setw(3) << std::left << ids[i] << ":  " << data[i] << std::endl;
      }
     else
     {
        cout << std::setw(10) << std::left << "PUSHTEST " << i + 1 << ": FAILED to PUSH    " << std::setw(3) << std::left << ids[i] << ":  " << data[i] << std::endl;
     }//end of if/else

    } //end of for

    std::cout << std::endl << "****************************************" << std::endl << std::endl;

    Data temp[number_test_cases];
    //int counter = 0;
    for(int i = 0; i < number_test_cases; i++)
    {
      if(stack.pop(&temp[i]))
      {
        std::cout << std::setw(10) << std::left << "POPTEST " << std::setw(3) << std::right << i + 1  << ":  SUCCEEDED POPPING  "  
              << std::setw(3) << std::left << temp[i].id << ":  " << temp[i].information << std::endl;
      } // end of successfull pop
      else
      {

        std::cout << std::setw(10) << std::left << "POPTEST " << std::setw(3) << std::right << i + 1 << ":  FAILED TO POP " 
                << " STACK MUST BE IN UNDERFLOW STATE." << std::endl;
      }
    }
    return 0;
}
