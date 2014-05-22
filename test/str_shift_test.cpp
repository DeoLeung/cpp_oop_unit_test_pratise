/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#include "str_shift_test.h"

#include <string>


CPPUNIT_TEST_SUITE_REGISTRATION(StrShiftTest);

void StrShiftTest::setUp() {
  _str = new StrShift("deoleung");
}

void StrShiftTest::tearDown() {
  if (_str) {
    delete _str;
    _str = 0;
  }
}

void StrShiftTest::_assert_strings(const string &first, const string &second) {
  CPPUNIT_ASSERT_EQUAL(first, second);
}

void StrShiftTest::test_StrShift() {
  _assert_strings("deoleung", _str->c_str());
}

void StrShiftTest::test_left_shift() {
  (*_str) << 1;
  _assert_strings("gdeoleun", _str->c_str());
}

void StrShiftTest::test_right_shift() {
  (*_str) >> 1;
  _assert_strings("eoleungd", _str->c_str());
}

void StrShiftTest::test_equal() {
  StrShift str("deoleung");
  CPPUNIT_ASSERT(str == *_str);

  StrShift str2("eoleungd");
  str2 << 1;
  CPPUNIT_ASSERT(str2 == *_str);
}

void StrShiftTest::test_not_equal() {
  StrShift str2("eoleungd");
  CPPUNIT_ASSERT(str2 != *_str);
}
