#pragma once
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include <iostream>

template <typename T> class SharedPtr {
public:
  // Constructor
  __host__ __device__ explicit SharedPtr(T *ptr = nullptr)
      : ptr_(ptr), ref_count_(ptr ? new size_t(1) : nullptr) {}

  // Destructor
  __host__ __device__ ~SharedPtr() { release(); }

  // Copy constructor
  __host__ __device__ SharedPtr(const SharedPtr &other)
      : ptr_(other.ptr_), ref_count_(other.ref_count_) {
    if (ref_count_) {
      (*ref_count_)++;
    }
  }
  // Templated constructor for conversion from SharedPtr<U> to SharedPtr<T>
  template <typename U>
  __host__ __device__ SharedPtr(const SharedPtr<U> &other)
      : ptr_(other.ptr_), ref_count_(other.ref_count_) {
    static_assert(std::is_convertible<U *, T *>::value,
                  "SharedPtr<U> cannot be converted to SharedPtr<T>");
    if (ref_count_) {
      (*ref_count_)++;
    }
  }

  // Copy assignment operator
  __host__ __device__ SharedPtr &operator=(const SharedPtr &other) {
    if (this != &other) {
      release();
      ptr_ = other.ptr_;
      ref_count_ = other.ref_count_;
      if (ref_count_) {
        (*ref_count_)++;
      }
    }
    return *this;
  }

  // Accessors
  __host__ __device__ T *get() const { return ptr_; }
  __host__ __device__ size_t use_count() const {
    return ref_count_ ? *ref_count_ : 0;
  }
  __host__ __device__ T &operator*() const { return *ptr_; }
  __host__ __device__ T *operator->() const { return ptr_; }

public:
  T *ptr_;            // Pointer to the managed object
  size_t *ref_count_; // Reference count

  __host__ __device__ void release() {
    if (ref_count_ && --(*ref_count_) == 0) {
      delete ptr_;
      delete ref_count_;
    }
  }
};

template <typename T, typename... Args>
__host__ __device__ SharedPtr<T> makeShared(Args &&...args) {
  return SharedPtr<T>(new T(std::forward<Args>(args)...));
}
