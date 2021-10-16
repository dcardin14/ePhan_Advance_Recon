/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    //Stack stack;
    PmtReq pmtReq[20];
    
    /*I'll ask the user to enter the payment request number
     * Maybe later I'll put this in a loop
     */
    cout << "Enter the amount of advance no 1:  ";
    cin >> pmtReq[0].advance.amount;

    cout << "You said it's " << pmtReq[0].advance.amount;

    return 0;
}
