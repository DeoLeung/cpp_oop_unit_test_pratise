/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#ifndef CHANGE_ALGORITHM_H
#define	CHANGE_ALGORITHM_H

#include <vector>

using namespace std;

class ChangeAlgorithm {
public:
  // a naive implementation of giving changes.
  // it finds maximum bills of the larger value, if it fails to provide bills
  // fully cover the change, returns nullptr, else return a vector of bills of
  // each bill value.
  // This requires the values are sorted in decending order.
  static vector<int> *minimum_bills_naive(const vector<int> &values,
                                          unsigned int change);
};

#endif /* CHANGE_ALGORITHM_H */

