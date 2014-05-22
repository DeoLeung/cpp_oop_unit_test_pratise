/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#ifndef STR_SHIFT_TEST_H
#define	STR_SHIFT_TEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../src/str_shift.h"

class StrShiftTest: public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(StrShiftTest);

  CPPUNIT_TEST(test_StrShift);
  CPPUNIT_TEST(test_left_shift);
  CPPUNIT_TEST(test_right_shift);
  CPPUNIT_TEST(test_equal);
  CPPUNIT_TEST(test_not_equal);
  CPPUNIT_TEST(test_assignment);

  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

private:
  // test to see whether the constructor works
  void test_StrShift();
  // test the << operator
  void test_left_shift();
  // test the >> operator
  void test_right_shift();
  // test the == operator
  void test_equal();
  // test the != operator
  void test_not_equal();
  // test the = operator
  void test_assignment();

  // covert various string type into std::string for easy comparison
  void _assert_strings(const string &first, const string &second);

  StrShift *_str;
};

#endif /* STR_SHIFT_TEST_H */

