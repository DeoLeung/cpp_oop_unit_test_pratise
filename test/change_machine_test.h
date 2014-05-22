/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#ifndef CHANGE_MACHINE_TEST_H
#define	CHANGE_MACHINE_TEST_H

#include <cppunit/extensions/HelperMacros.h>

#include "../src/change_machine.h"

class ChangeMachineTest: public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(ChangeMachineTest);

  CPPUNIT_TEST(test_ChangeMachine);
  CPPUNIT_TEST(test_MakeChange);
  CPPUNIT_TEST(test_set_denominations);

  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

private:
  void test_ChangeMachine();
  void test_MakeChange();
  void test_set_denominations();
  void _assert_vectors(const vector<int> &expected,
                       const vector<int> &actual) const;
  void _assert_bills(const int bills, const int change) const;

  ChangeMachine *_change_machine;

};

#endif	/* CHANGE_MACHINE_TEST_H */

