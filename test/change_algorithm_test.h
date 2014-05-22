/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#ifndef CHANGE_ALROGITHM_TEST_H
#define	CHANGE_ALROGITHM_TEST_H

#include <vector>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class ChangeAlgorithmTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(ChangeAlgorithmTest);

  CPPUNIT_TEST(test_minimum_bills_naive);

  CPPUNIT_TEST_SUITE_END();

public:
  void test_minimum_bills_naive();

private:
  void _assert_bills(unsigned int change,
                     const vector<int> *golden,
                     const vector<int> &values) const;

};

#endif	/* CHANGE_ALROGITHM_TEST_H */

