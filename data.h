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
  Advance advance;
  Expenses expenses;

};

#endif /* STACKS_DATA_H */
