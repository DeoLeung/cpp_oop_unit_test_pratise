/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#include <string>

#include "str_shift_test.h"

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
  // char*
  _assert_strings("deoleung", _str->c_str());

  // default
  StrShift str;
  _assert_strings("", str.c_str());

  // std::string
  StrShift str2(string("deo"));
  _assert_strings("deo", str2.c_str());
}

void StrShiftTest::test_left_shift() {
  (*_str) << 0;
  _assert_strings("deoleung", _str->c_str());
  (*_str) << 1;
  _assert_strings("gdeoleun", _str->c_str());
  (*_str) << 1;
  _assert_strings("ngdeoleu", _str->c_str());
  (*_str) << 1;
  _assert_strings("ungdeole", _str->c_str());
  (*_str) << 1;
  _assert_strings("eungdeol", _str->c_str());
  (*_str) << 1;
  _assert_strings("leungdeo", _str->c_str());
  (*_str) << 1;
  _assert_strings("oleungde", _str->c_str());
  (*_str) << 1;
  _assert_strings("eoleungd", _str->c_str());
  (*_str) << 1;
  _assert_strings("deoleung", _str->c_str());
  // cyclic
  (*_str) << 1;
  _assert_strings("gdeoleun", _str->c_str());
  (*_str) << 8;
  _assert_strings("gdeoleun", _str->c_str());
  (*_str) << 88;
  _assert_strings("gdeoleun", _str->c_str());
}

void StrShiftTest::test_right_shift() {
  (*_str) >> 0;
  _assert_strings("deoleung", _str->c_str());
  (*_str) >> 1;
  _assert_strings("eoleungd", _str->c_str());
  (*_str) >> 1;
  _assert_strings("oleungde", _str->c_str());
  (*_str) >> 1;
  _assert_strings("leungdeo", _str->c_str());
  (*_str) >> 1;
  _assert_strings("eungdeol", _str->c_str());
  (*_str) >> 1;
  _assert_strings("ungdeole", _str->c_str());
  (*_str) >> 1;
  _assert_strings("ngdeoleu", _str->c_str());
  (*_str) >> 1;
  _assert_strings("gdeoleun", _str->c_str());
  (*_str) >> 1;
  _assert_strings("deoleung", _str->c_str());
  // cyclic
  (*_str) >> 1;
  _assert_strings("eoleungd", _str->c_str());
  (*_str) >> 8;
  _assert_strings("eoleungd", _str->c_str());
  (*_str) >> 24;
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

void StrShiftTest::test_assignment() {
  StrShift str;
  CPPUNIT_ASSERT(str != *_str);
  str = "deoleung";
  CPPUNIT_ASSERT(str == *_str);
}
