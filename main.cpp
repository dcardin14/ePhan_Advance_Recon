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
    ifstream inputFile; 
    ofstream outputFile;

    PmtReq pmtReq[MAXPAYMENTS];
    
    inputFile.open("inputFile");  //This is the existing spreadsheet, basically
    outputFile.open("outputFile.csv"); //This is the output

    // Get the data from the inputFile  and count the pmtReqs
    int counter = 0;
    while(!inputFile.eof())
    {
      inputFile >> pmtReq[counter].expenses.amount >> pmtReq[counter].advance.amount;
      pmtReq[counter].advance.balance = pmtReq[counter].advance.amount; //starting balance is the advance itself

      //inner loop through all the balances from previous advances
      for(int i = 0; i < counter; i++)
      {
        if (pmtReq[counter].expenses.amount > pmtReq[i].advance.balance)
        {
          pmtReq[counter].expenses.amount = pmtReq[counter].expenses.amount - pmtReq[i].advance.balance;
          pmtReq[i].advance.appliedAgainst = pmtReq[i].advance.balance; //say houw much how applied 
          pmtReq[i].advance.balance = 0.0;  //zero out the advance balance
        }
        else  //if the current Expense balance is NOT enough to satisfy this particular one of the prevs
        {
          pmtReq[i].advance.appliedAgainst = pmtReq[counter].expenses.amount;  
          pmtReq[i].advance.balance = pmtReq[i].advance.balance - pmtReq[counter].expenses.amount;  // There will still be a balance
          pmtReq[counter].expenses.amount = 0.0;  //The outer loop expenses are exhaused and applied to inner loop balance.
        }
        cout.imbue(std::locale("en_US.UTF-8"));
                cout << setw(15) << std::showbase << put_money(pmtReq[i].advance.appliedAgainst);  //show in terminal what you're applying
          outputFile << setw(15) << fixed << showpoint << setprecision(2) << std::showbase << put_money(pmtReq[i].advance.appliedAgainst);  // output it to file too

      } //end of the inner loop
      cout << endl;  //Go to the next line for the next payment request
      outputFile << endl;


      // cout << setw(10) << pmtReq[counter].expenses.amount << setw(10) << pmtReq[counter].advance.amount << endl;
      // outputFile << setw(10) << showpoint << fixed << setprecision(2) << pmtReq[counter].expenses.amount << setw(10) << pmtReq[counter].advance.amount;
      counter++;
    } //end of while

    // Create an output file


   /* 
  int earliest;
  int offset;
   for(int k = 0; k < MAXPAYMENTS; k++){
    earliest = findEarliestNonzeroAdvanceBalance(*pmtReq);
    offset = k - earliest;
    for(int l = 0; l < offset; l++)
    {
     pmtReq[l].advance.amount = pmtReq[l].advance.amount -1; 
    }
   }
*/
    return 0;
}
