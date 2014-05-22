/*
 * File:   change_machine.h
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Created on 22 May 2014, 08:44
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
  int MakeChange(int total_change) const;
  bool set_denominations(vector<int> &denominations);
  bool get_denominations();
private:
  vector<int> *_denominations;
};



#endif	/* CHANGE_MACHINE_H */

