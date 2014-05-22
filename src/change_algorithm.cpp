#include "change_algorithm.h"

// A naive implementation, which finds the maximum bills of the largest value
// first. This requires the values are sorted in decending order.
vector<int> *ChangeAlgorithm::minimum_bills_naive(
    const vector<int> &values, unsigned int change) {
  if (!change) {
    // We can't change 0 value.
    return 0;
  }
  // Counts the number of bills of each bill value.
  vector<int> *bills = new vector<int>(values.size(), 0);
  for (int i = 0; i < values.size(); ++i) {
    if (values[i] > change) {
      // unable to give change on a bill with bigger value.
      continue;
    }
    // Gets the maximum bills we can for the bill value.
    (*bills)[i] = change / values[i];
    // Calculate the remain change value.
    change %= values[i];
    if (!change) {
      // We are done if the remain change value is 0.
      return bills;
    }
  }
  // If there's still changes left, it means it can't be fully changed, return a
  // null ptr.
  delete bills;
  return 0;
}

