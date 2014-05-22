/* 
 * File:   change_algorithm.h
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Created on 22 May 2014, 09:59
 */

#ifndef CHANGE_ALGORITHM_H
#define	CHANGE_ALGORITHM_H

#include <vector>

using namespace std;

class ChangeAlgorithm {
public:
  static vector<int> *minimum_bills_naive(const vector<int> &values, 
                                          unsigned int change);
};

#endif	/* CHANGE_ALGORITHM_H */

