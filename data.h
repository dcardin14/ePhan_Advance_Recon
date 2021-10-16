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
  double amount;
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
