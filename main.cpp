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
    PmtReq pmtReq[MAXPAYMENTS];
    
    inputFile.open("inputFile");  //This is the existing spreadsheet, basically

    // Get the data from the inputFile 
    int counter = 0;
    while(!inputFile.eof())
    {
      inputFile >> pmtReq[counter].expenses.amount >> pmtReq[counter].advance.amount;
      counter++;
    } //end of while

    // Create an output file
    ofstream outputFile;
    outputFile.open("outputFile.csv");

    // Output the data to the screen and to an outputFile
    for(int j = 0; j < counter; j++)
    {
      cout << setw(10) << pmtReq[j].expenses.amount << setw(10) << pmtReq[j].advance.amount << endl;
      outputFile << setw(10) << showpoint << fixed << setprecision(2) << pmtReq[j].expenses.amount << setw(10) << pmtReq[j].advance.amount;
    }


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
