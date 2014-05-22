#include "str_shift.h"

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
    if (_head < 0) {
      _head = _str.size() - (_head % _str.size());
    }
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

StrShift &StrShift::operator= (StrShift &&other) {
  swap(*this, other);
  return *this;
}
