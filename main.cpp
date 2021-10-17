/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main(int, char *argv[]) 
{

  cout << endl << endl;
  cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << "------------------------------------------------------------ADVANCE RECONCILIATION--------------------------------------------------------" << endl;
  cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << endl <<  endl;

    //Stack stack;
    ifstream inputFile; 
    ofstream outputFile;

    //splashScreen();  //not working for some reason so I can't call it.

    PmtReq pmtReq[MAXPAYMENTS];

    inputFile.open(argv[1]);  //This is the existing spreadsheet, basically, but passed in as the second-to-last cli parameter.
    outputFile.open(argv[2]); //This is the output

    // Get the data from the inputFile  and count the pmtReqs
    int counter = 0; //Counter for the while loop
    double originalAdvance[9] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00}; //To hold the original amounts (initialized though)
    double throwaway[9] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};// Just becuase there are 2 columns in input file when I only need 1 and I don't want to get confused 
    cout << endl;
    cout << "==========================================================================================================================================" << endl;
      cout << setw(2) << left << "+";

        /*------------------------------------------------------------------------------*/
        cout << setw(15) << std::right << "Advance_1" << setw(15) << "Advance_2"  //Columm headers before I start looping
             << setw(15) << std::right << "Advance_3" << setw(15) << "Advance_4"  
             << setw(15) << std::right << "Advance_5" << setw(15) << "Advance_6"  
             << setw(15) << std::right << "Advance_7" << setw(15) << "Advance_8"  
             << setw(15) << std::right << "Advance_9" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        // A setup while loop to grab all those original advance amounts
        int cc =0; //counter for setup while loop
      while(!inputFile.eof())
      {
        inputFile >> throwaway[cc] >> originalAdvance[cc];
        cc++; //increment the counter
      }
      cout << left << setw(2) << "+";
        cout.imbue(std::locale("en_US.UTF-8"));  //allows me to format these numbers as USD
        cout << setw(15) << std::right << setprecision(2) << showpoint << fixed << originalAdvance[0] << setw(15) << originalAdvance[1]  //Columm headers before I start looping
             << setw(15) << std::right << originalAdvance[2] << setw(15) << originalAdvance[3]  
             << setw(15) << std::right << originalAdvance[4] << setw(15) << originalAdvance[5]  
             << setw(15) << std::right << originalAdvance[6] << setw(15) << originalAdvance[7]  
             << setw(15) << std::right << originalAdvance[8] << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        /*------------------------------------------------------------------------------*/
        outputFile << setw(15) << std::right << "Advance_1" << setw(15) << "Advance_2"
                  << setw(15) << std::right <<  "Advance_3" << setw(15) << "Advance_4"
                  << setw(15) << std::right <<  "Advance_5" << setw(15) << "Advance_6"
                  << setw(15) << std::right <<  "Advance_7" << setw(15) << "Advance_8"
                  << setw(15) << std::right <<  "Advance_9" << setw(15) << endl;
        outputFile << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        /*------------------------------------------------------------------------------*/
        outputFile.imbue(std::locale("en_US.UTF-8"));  //format as usd in the output file too
        outputFile << setw(15) << std::right << setprecision(2) << showpoint << fixed << originalAdvance[0] << setw(15) << originalAdvance[1]  //Columm headers before I start looping
             << setw(15) << std::right << originalAdvance[2] << setw(15) << originalAdvance[3]  
             << setw(15) << std::right << originalAdvance[4] << setw(15) << originalAdvance[5]  
             << setw(15) << std::right << originalAdvance[6] << setw(15) << originalAdvance[7]  
             << setw(15) << std::right << originalAdvance[8] << endl;
        outputFile << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        /*------------------------------------------------------------------------------*/
        inputFile.close();
        inputFile.open(argv[1]);  //This is the existing spreadsheet, basically, but passed in as the second-to-last cli parameter.
       // inputFile.open("inputFile");

    while(!inputFile.eof())
    {
      inputFile >> pmtReq[counter].expenses.amount >> pmtReq[counter].advance.amount;
      originalAdvance[counter] = pmtReq[counter].advance.amount;
      pmtReq[counter].advance.balance = pmtReq[counter].advance.amount; //starting balance is the advance itself

      cout << setw(2) << left << counter + 1;


      //inner loop through all the balances from previous advances
      for(int i = 0; i <= counter; i++)
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
          pmtReq[i].advance.balance = pmtReq[i].advance.balance - pmtReq[i].advance.appliedAgainst;  // There will still be a balance
          pmtReq[counter].expenses.amount = 0.0;  //The outer loop expenses are exhaused and applied to inner loop balance.
        }
        else
        {
          pmtReq[i].advance.appliedAgainst = 0.00;
        }
        cout.imbue(std::locale("en_US.UTF-8"));  //allows me to format these numbers as USD
                cout << setw(15) << fixed << showpoint << setprecision(2) << std::right << pmtReq[i].advance.appliedAgainst;  //show in terminal what you're applying
          
          outputFile << setw(15) << fixed << showpoint << setprecision(2) << std::right << pmtReq[i].advance.appliedAgainst;  // output it to file too

      } //end of the inner loop
      cout << endl;  //Go to the next line for the next payment request
      outputFile << endl;  //same in the output file
      counter++;  //increment the while loop counter
    } //end of while

    cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    outputFile << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(2) << "#";
    //outputFile << left << setw(2) << "#";
    //outputFile << left <<   "#";
    /*
     * Print remaining balances for each advance (Let's hope most of them are zero)
     * because we're not supposed to make a new advance unless the most recent is
     * 70% satisfied and all the prevs are zero
     *
     */
    for(int j = 0; j < counter; j++)
    {
      cout << setw(15) << fixed << showpoint << setprecision(2) << std::right << pmtReq[j].advance.balance;
      outputFile << setw(15) << fixed << showpoint << setprecision(2) << std::right << pmtReq[j].advance.balance;

    }

    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    outputFile << endl;
    outputFile << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << left << setw(2) << "TD";
    //outputFile << left << setw(2) << "TD";
    //outputFile << left << "TD";
    for (int k = 0; k < 9; k++)
    {
      if(originalAdvance[k] > 0)
      {
        cout << setw(15) << fixed << showpoint << setprecision(1) << std::right << std::to_string(((originalAdvance[k] - pmtReq[k].advance.balance) / originalAdvance[k] * 100)) + "%";
        outputFile << setw(15) << fixed << showpoint << setprecision(1) << std::right << std::to_string(((originalAdvance[k] - pmtReq[k].advance.balance) / originalAdvance[k] * 100)) + "%";
      }
      else
      {
        cout << setw(15) << std::right << " - ";
        outputFile << setw(15) << std::right << " - ";
      } 
    }
    outputFile.close();
    inputFile.close();
    cout << endl;
    cout << "==========================================================================================================================================" << endl;
    cout << endl << endl << endl;

    return 0;
}
