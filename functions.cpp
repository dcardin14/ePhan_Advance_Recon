/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * DO NOT MODIFY THIS FILE
 */

#include "functions.h"

int findEarliestNonzeroAdvanceBalance(PmtReq *pmtReq)
{
  int i = 0; //counter
  while(pmtReq[i].advance.amount == 0){
    i++;
  }
  return i;
}

void splashScreen()
{
  cout << "=====================================================================================================================" << endl;
  cout << "===============================ADVANCE RECONCILIATION================================================================" << endl;
  cout << "=====================================================================================================================" << endl;
  cout << endl <<  endl;
}

