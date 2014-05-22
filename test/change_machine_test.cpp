/*
 * File:   change_alrogithm_test.cpp
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Created on 22-May-2014, 10:18:24
 */

#include "change_machine_test.h"

#include <string>
#include <utility>


CPPUNIT_TEST_SUITE_REGISTRATION(ChangeMachineTest);

void ChangeMachineTest::setUp() {
  _change_machine = new ChangeMachine();
}

void ChangeMachineTest::tearDown() {
  if (_change_machine) {
    delete _change_machine;
    _change_machine = 0;
  }
}

void ChangeMachineTest::_assert_vectors(const vector<int> &expected,
                                        const vector<int> &actual) const {
  CPPUNIT_ASSERT_EQUAL_MESSAGE(
      "Different vector size",
      expected.size(), actual.size());
  for (unsigned int i = 0; i < expected.size(); ++i) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE(
        "Vector index " + to_string(i) + " is different",
        expected[i], actual[i]);
  }
}

void ChangeMachineTest::test_ChangeMachine() {
  const vector<int> golden = {100, 50, 20, 10, 5, 1};
  _assert_vectors(golden, _change_machine->get_denominations());
}

void ChangeMachineTest::test_set_denominations() {
  const vector<int> golden = {100, 50, 20, 10, 5, 1};
  _assert_vectors(golden, _change_machine->get_denominations());

  vector<int> empty_input;
  CPPUNIT_ASSERT_EQUAL_MESSAGE(
      "Setting denominations to empty should fail",
      false, _change_machine->set_denominations(empty_input));
  // Failure in setting denominations should not affect the original state.
  _assert_vectors(golden, _change_machine->get_denominations());

  // With valid set denominations the state should be desending order
  // TODO: remove duplicates.
  const vector<int> golden_sorted = {4, 3, 2, 2, 1};
  const vector<int> unsorted_input = {1, 3, 2, 4, 2};
  _change_machine->set_denominations(unsorted_input);
  _assert_vectors(golden_sorted, _change_machine->get_denominations());
}

void ChangeMachineTest::_assert_bills(const int bills, const int change) const {
  int actual = _change_machine->MakeChange(change);
  CPPUNIT_ASSERT_EQUAL_MESSAGE(
      "Bills given is wrong for change " + to_string(change),
      bills, actual);
}

void ChangeMachineTest::test_MakeChange() {
  _assert_bills(-1, 0);
  _assert_bills(1, 1);
  _assert_bills(2, 2);
  _assert_bills(1, 5);
  _assert_bills(1, 10);
  _assert_bills(1, 20);
  _assert_bills(1, 50);
  _assert_bills(1, 100);
  _assert_bills(2, 101);
  _assert_bills(658, 65535);
}

