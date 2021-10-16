/*
 * Daniel Cardin
 * 10/15/2021
 * 
 */

#ifndef STACKS_DATA_H
#define STACKS_DATA_H

#include <string>
using std::string;

struct Advance{
  double amount; //How much was the advance?
  double balance; //How much of this advance is still outstanding?
  double appliedAgainst;  //How much is being applied against it  NOTE:  This will only be one value per struct, not a running total.
};

struct Expenses{
  double amount;
};

struct PmtReq {
  int paymentRequestNo;
  string dateReceived;

  /*
   * Whatever fraction of the most recent advance has to be paid to qualify for the next advance
   *
   * */
  float payPercentOnMostRecent;  

  Advance advance;  //an instance of the struct
  Expenses expenses; //an instance of the struct

};

#endif /* STACKS_DATA_H */
