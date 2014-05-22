/*
 * File:   change_alrogithm_test.cpp
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Created on 22-May-2014, 10:18:24
 */

#include "change_alrogithm_test.h"
#include "../src/change_algorithm.h"

#include <string>
#include <utility>


CPPUNIT_TEST_SUITE_REGISTRATION(change_alrogithm_test);

change_alrogithm_test::change_alrogithm_test() {
}

change_alrogithm_test::~change_alrogithm_test() {
}

void change_alrogithm_test::setUp() {
}

void change_alrogithm_test::tearDown() {
}

void change_alrogithm_test::_assert_bills(unsigned int change,
                                          const vector<int> *golden,
                                          const vector<int> &values) const {
  const vector<int> *result = ChangeAlgorithm::minimum_bills_naive(
      values, change);
  string change_str = std::to_string(change);
  if (!golden) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE(
        change_str + " expected no change, but change is given",
        golden, result);
  } else if (!result) {
    CPPUNIT_ASSERT_EQUAL_MESSAGE(
        change_str + " expected change, but no change is given",
        golden, result);
  } else {
    CPPUNIT_ASSERT_EQUAL_MESSAGE(
        change_str + " change given has different value set",
        golden->size(), result->size());
    for (unsigned int i = 0; i < golden->size(); ++i) {
      CPPUNIT_ASSERT_EQUAL_MESSAGE(
          change_str + " change given for bill " + std::to_string(i) + " is different",
          (*golden)[i], (*result)[i]);
    }
  }
  if (result) {
    delete result;
    result = 0;
  }
}

void change_alrogithm_test::test_minimum_bills_naive() {
  const vector<int> values = {100, 50, 20, 10, 5, 1};
  _assert_bills(0, 0, values);

  vector<int> golden;

  golden = {0, 0, 0, 0, 0, 1};
  _assert_bills(1, &golden, values);

  golden = {0, 0, 0, 0, 0, 2};
  _assert_bills(2, &golden, values);

  golden = {0, 0, 0, 0, 1, 0};
  _assert_bills(5, &golden, values);

  golden = {0, 0, 0, 1, 0, 0};
  _assert_bills(10, &golden, values);

  golden = {0, 0, 1, 0, 0, 0};
  _assert_bills(20, &golden, values);

  golden = {0, 1, 0, 0, 0, 0};
  _assert_bills(50, &golden, values);

  golden = {1, 0, 0, 0, 0, 0};
  _assert_bills(100, &golden, values);

  golden = {1, 0, 0, 0, 0, 1};
  _assert_bills(101, &golden, values);

  golden = {655, 0, 1, 1, 1, 0};
  _assert_bills(65535, &golden, values);
}

