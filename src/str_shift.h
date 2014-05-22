/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 *
 * Implement a class that does string manipulation by overloading the following
 * operators: <<, >>, = and ==. For example consider the following code:
 *    StrShift example;
 *    example = "abcdefghi";
 *    printf(“\”example << 2\” results in %s\n“, example << 2);
 * In the above code the output would be “hiabcdefg” which shows the last two
 * characters of the string “abcdefghi” rotated to the left of the string.
 * Please note that state is maintained so two calls of example << 1 would give
 * the same end result as calling example << 2 once. Consideration will be given
 * to correctness, design, code readability as well as any unit testing. As part
 * of a final solution please submit test cases you used to verify correctness
 * in addition to any unit tests done.
 */

#ifndef STR_SHIFT_H
#define	STR_SHIFT_H

#include <string>

using namespace std;

class StrShift {
public:
  // constructor
  StrShift(): _str(), _head(0) {};
  StrShift(const string &str): _str(str), _head(0) {};
  StrShift(const char* str): _str(str), _head(0) {};

  // copy constructor
  StrShift(const StrShift &other): _str(other._str), _head(other._head) {};

  // move constructor
  StrShift(StrShift &&other) {
    swap(*this, other);
  };

  // move the last 'shift' char to the front of represented string.
  // e.g 'deoleung' << 2, the representing string will be 'ngdeoleu'.
  const char *operator<< (const unsigned int shift);
  // move the first 'shift' char to the end of represented string.
  // e.g 'deoleung' >> 2, the representing string will be 'oleungde'.
  const char *operator>> (const unsigned int shift);

  // copy assignment operator
  StrShift &operator= (StrShift other);
  // TODO: solve the "ambiguous overload for ‘operator=’"
  // move assignment operator
  // StrShift &operator= (StrShift &&other);

  // return a c string format of the represented string.
  const char *c_str() const;

private:
  friend void swap(StrShift &first, StrShift &second);
  friend bool operator== (const StrShift &first, const StrShift &second);
  friend bool operator!= (const StrShift &first, const StrShift &second);

  // holder of the original string.
  string _str;
  // the head of the represented string.
  int _head;
};

#endif /* STR_SHIFT_H */

