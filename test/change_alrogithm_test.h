/*
 * File:   change_alrogithm_test.h
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Created on 22-May-2014, 10:18:24
 */

#ifndef CHANGE_ALROGITHM_TEST_H
#define	CHANGE_ALROGITHM_TEST_H

#include <vector>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class change_alrogithm_test : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(change_alrogithm_test);

  CPPUNIT_TEST(test_minimum_bills_naive);

  CPPUNIT_TEST_SUITE_END();

public:
  change_alrogithm_test();
  virtual ~change_alrogithm_test();
  void setUp();
  void tearDown();
  void test_minimum_bills_naive();

private:
  void _assert_bills(unsigned int change,
                     const vector<int> *golden,
                     const vector<int> &values) const;

};

#endif	/* CHANGE_ALROGITHM_TEST_H */

