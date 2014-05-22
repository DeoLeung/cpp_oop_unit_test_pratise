/*
 * Author: Deo Zhanzhao Liang <liangzhanzhao1985@gmail.com>
 */
#include <utility>

#include "str_shift.h"

void swap(StrShift &first, StrShift &second) {
  using std::swap;
  swap(first._str, second._str);
  swap(first._head, second._head);
};

bool operator== (const StrShift &first, const StrShift &second) {
  string str_first(first.c_str());
  string str_second(second.c_str());
  return str_first == str_second;
}

bool operator!= (const StrShift &first, const StrShift &second) {
  string str_first(first.c_str());
  string str_second(second.c_str());
  return str_first != str_second;
}

const char *StrShift::c_str() const{
  string new_str;
  for (unsigned int i = _head; i < _str.size(); ++i) {
    new_str += _str[i];
  }
  for (int i = 0; i < _head; ++i) {
    new_str += _str[i];
  }
  return new_str.c_str();
}
const char *StrShift::operator<< (const unsigned int shift) {
  if (shift != 0 && !_str.empty()) {
    _head -= shift;
    // TODO: when comes to minus this seems to work but may be compiler depends.
    _head %= _str.size();
  }
  return c_str();
}

const char *StrShift::operator>> (const unsigned int shift) {
  if (shift != 0 && !_str.empty()) {
    _head += shift;
    _head %= _str.size();
  }
  return c_str();
}

StrShift &StrShift::operator= (StrShift other) {
  swap(*this, other);
  return *this;
}

/*
StrShift &StrShift::operator= (StrShift &&other) {
  swap(*this, other);
  return *this;
}*/
