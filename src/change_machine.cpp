#include "change_algorithm.h"
#include "change_machine.h"

ChangeMachine::ChangeMachine() {
  // Default bill values we have.
  _denominations = new vector<int>({100, 50, 20, 10, 5, 1});
}

int ChangeMachine::MakeChange(int total_change) const {
  vector<int> *bills = ChangeAlgorithm::minimum_bills_naive(
      *_denominations, total_change);
  if (!bills) {
    // If it can't be fully changed, return -1 indicating failure.
    return -1;
  }
  // Counts the total bills for the change.
  int total = 0;
  for (auto &count: (*bills)) {
    total += count;
  }
  if (bills) {
    delete bills;
    bills = 0;
  }
  return total;
}

bool ChangeMachine::set_denominations(vector<int>& denominations) {
  (*_denominations) = denominations;
}

ChangeMachine::~ChangeMachine() {
  if (_denominations) {
    delete _denominations;
    _denominations = 0;
  }
}

