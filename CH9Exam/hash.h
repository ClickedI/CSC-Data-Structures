//copyright 2025

#ifndef HASH_H_
#define HASH_H_
#include <string>

/** Hash Function Objects Template */
template<typename Key_Type>
  struct hash {
  size_t operator()(const Key_Type&) const;
};

// Specialization for string
template<>
struct hash<std::string> {
  size_t operator()(const std::string& s) const {
    size_t result = 0;
    for (size_t i=0; i<s.length(); i++) {
      result = result * 31 + s[i];
    }
    return result;
  }
};

// Specialization for int
template<>
struct hash<int> {
  size_t operator()(int i) const {
    return size_t(4262999287U * i);
  }
};


#endif
