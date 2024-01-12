#pragma once
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//

template <typename T> class Vector {
public:
  // Constructor
  __host__ __device__ Vector() : data_(nullptr), size_(0), capacity_(0) {}

  // Destructor
  __host__ __device__ ~Vector() { delete[] data_; }

  // Add an element to the end of the vector
  __host__ __device__ void push_back(const T &value) {
    if (size_ >= capacity_) {
      resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_++] = value;
  }

  // Access specified element with bounds checking
  __host__ __device__ T &at(size_t index) {
    if (index >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[index];
  }

  // Access specified element
  __host__ __device__ T &operator[](size_t index) { return data_[index]; }

  // Access specified element (const version)
  __host__ __device__ const T &operator[](size_t index) const {
    return data_[index];
  }

  // Return the number of elements
  __host__ __device__ size_t size() const { return size_; }

  // Clear the contents
  __host__ __device__ void clear() { size_ = 0; }

  // Resize the vector
  __host__ __device__ void resize(size_t newSize) {
    if (newSize > capacity_) {
      size_t newCapacity = newSize;
      T *newData = new T[newCapacity];

      for (size_t i = 0; i < size_; ++i) {
        newData[i] = data_[i];
      }

      delete[] data_;
      data_ = newData;
      capacity_ = newCapacity;
    }
    if (size_ > newSize)
      size_ = newSize;
  }

private:
  T *data_;         // Pointer to the data
  size_t size_;     // Number of elements
  size_t capacity_; // Capacity of the vector
};
