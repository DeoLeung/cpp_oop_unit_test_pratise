/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Given a currency with denominations of 100, 50, 20, 10, 5 and 1 write a
 * method MakeChange that takes an integer amount representing the total change
 * to make and return an integer representing the smallest possible number of
 * bills to return. For example a call of MakeChange(135) would result in a
 * return value of 4 (1 one hundred bill, 1 twenty bill, 1 ten bill and 1 five
 * bill). As part of a final solution please provide unit tests done as well as
 * any test cases ran.
 */

#ifndef CHANGE_MACHINE_H
#define	CHANGE_MACHINE_H

#include <vector>

using namespace std;

class ChangeMachine {
public:
  ChangeMachine();
  ~ChangeMachine();
  // return the number of bills for a given change.
  int MakeChange(int total_change) const;
  // set the bill values, and sort them in descending order
  bool set_denominations(const vector<int> &denominations);
  // get the bill values.
  const vector<int> &get_denominations();
private:
  // holder of bill values
  vector<int> *_denominations;
};



#endif	/* CHANGE_MACHINE_H */

