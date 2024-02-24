#pragma once
//==============================================================================================
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//==============================================================================================

__host__ __device__ size_t simple_strlen(const char *str) {
  size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

class String {
private:
  char *data;
  size_t _length;

public:
  // Constructor
  __host__ __device__ String(const char *str) {
    _length = str ? simple_strlen(str) : 0;
    data = new char[_length + 1]; // +1 for the null terminator
    if (str) {
      __builtin_memcpy(data, str, _length + 1);
    } else {
      data[0] = '\0';
    }
  }

  // Destructor
  __host__ __device__ ~String() { delete[] data; }

  // Copy constructor
  __host__ __device__ String(const String &other) {
    _length = other._length;
    data = new char[_length + 1];
    memcpy(data, other.data, _length + 1);
  }

  // Copy assignment operator
  __host__ __device__ String &operator=(const String &other) {
    if (this != &other) {
      char *newData = new char[other._length + 1];
      memcpy(newData, other.data, other._length + 1);
      delete[] data;
      data = newData;
      _length = other._length;
    }
    return *this;
  }

  // Equality operator
  __host__ __device__ bool operator==(const String &other) const {
    if (_length != other._length) {
      return false;
    }

    for (size_t i = 0; i < _length; ++i) {
      if (data[i] != other.data[i]) {
        return false;
      }
    }

    return true;
  }

  // Inequality operator
  __host__ __device__ bool operator!=(const String &other) const {
    return !(*this == other);
  }

  // Function to get C-style string
  __host__ __device__ const char *c_string() const { return data; }

  __host__ __device__ size_t length() const { return _length; }
};

namespace std {
template <> struct hash<String> {
  __host__ __device__ std::size_t operator()(const String &s) const {
    std::size_t hash_value = 0;
    const size_t prime =
        31; // A small prime number used as a multiplier in the hash function

    for (size_t i = 0; i < s.length(); ++i) {
      hash_value = s.c_string()[i] + (hash_value * prime);
    }

    return hash_value;
  }
};
} // namespace std
