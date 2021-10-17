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

        /*------------------------------------------------------------------------------*/
        cout << setw(15) << std::right << "Advance_1" << setw(15) << "Advance_2"  //Columm headers before I start looping
             << setw(15) << std::right << "Advance_3" << setw(15) << "Advance_4"  
             << setw(15) << std::right << "Advance_5" << setw(15) << "Advance_6"  
             << setw(15) << std::right << "Advance_7" << setw(15) << "Advance_8"  
             << setw(15) << std::right << "Advance_9" << endl;
        /*------------------------------------------------------------------------------*/
        outputFile << setw(12) << std::right << "Advance_1" << setw(12) << "Advance_2"
                  << setw(12) << std::right <<  "Advance_3" << setw(12) << "Advance_4"
                  << setw(12) << std::right <<  "Advance_5" << setw(12) << "Advance_6"
                  << setw(12) << std::right <<  "Advance_7" << setw(12) << "Advance_8"
                  << setw(12) << std::right <<  "Advance_9" << setw(12) << endl;
        /*------------------------------------------------------------------------------*/

    while(!inputFile.eof())
    {
      inputFile >> pmtReq[counter].expenses.amount >> pmtReq[counter].advance.amount;
      pmtReq[counter].advance.balance = pmtReq[counter].advance.amount; //starting balance is the advance itself

      cout << setw(2) << left << counter + 1;


      //inner loop through all the balances from previous advances
      for(int i = 0; i < counter; i++)
      {

        if (pmtReq[counter].expenses.amount > pmtReq[i].advance.balance)
        {
          pmtReq[counter].expenses.amount = pmtReq[counter].expenses.amount - pmtReq[i].advance.balance;
          pmtReq[i].advance.appliedAgainst = pmtReq[i].advance.balance; //say how much was applied 
          pmtReq[i].advance.balance = 0.0;  //zero out the advance balance
        }
        else if(pmtReq[counter].expenses.amount != 0)  //if the current Expense balance is NOT enough to satisfy this particular one of the prevs
        {
          pmtReq[i].advance.appliedAgainst = pmtReq[counter].expenses.amount;  
          pmtReq[i].advance.balance = pmtReq[i].advance.balance - pmtReq[counter].expenses.amount;  // There will still be a balance
          pmtReq[counter].expenses.amount = 0.0;  //The outer loop expenses are exhaused and applied to inner loop balance.
        }
        else
        {
          pmtReq[i].advance.appliedAgainst = 0.00;
        }
        cout.imbue(std::locale("en_US.UTF-8"));  //allows me to format these numbers as USD
                cout << setw(15) << fixed << showpoint << setprecision(2) << std::right << pmtReq[i].advance.appliedAgainst;  //show in terminal what you're applying
          
          outputFile << setw(12) << fixed << showpoint << setprecision(2) << std::right << pmtReq[i].advance.appliedAgainst;  // output it to file too

      } //end of the inner loop
      cout << endl;  //Go to the next line for the next payment request
      outputFile << endl;  //same in the output file
      counter++;  //increment the while loop counter
    } //end of while
    outputFile.close();
    inputFile.close();

    return 0;
}
