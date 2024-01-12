#pragma once
//==============================================================================================
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//==============================================================================================

template <typename T> class Vector {
public:
  // Constructor
  __host__ __device__ Vector() : data_(nullptr), size_(0), capacity_(0) {}

  // Constructor with size parameter
  __host__ __device__ Vector(size_t initialSize)
      : data_(new T[initialSize]), size_(initialSize), capacity_(initialSize) {
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = T(); // Default-construct each element
    }
  }

  // Destructor
  __host__ __device__ ~Vector() { delete[] data_; }

  // Copy constructor
  __host__ __device__ Vector(const Vector &other)
      : size_(other.size_), capacity_(other.capacity_) {
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  // Copy assignment operator
  __host__ __device__ Vector &operator=(const Vector &other) {
    if (this != &other) {
      delete[] data_;

      size_ = other.size_;
      capacity_ = other.capacity_;
      data_ = new T[capacity_];
      for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
      }
    }
    return *this;
  }

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
  class iterator {
  public:
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;
    // Default constructor
    __host__ __device__ iterator() : ptr_(nullptr) {}

    // Constructor with pointer
    __host__ __device__ iterator(T *ptr) : ptr_(ptr) {}

    // Dereference operator
    __host__ __device__ T &operator*() const { return *ptr_; }

    // Arrow operator
    __host__ __device__ T *operator->() const { return ptr_; }

    // Pre-increment operator
    __host__ __device__ iterator &operator++() {
      ptr_++;
      return *this;
    }

    // Post-increment operator
    __host__ __device__ iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    __host__ __device__ iterator operator+(int n) const {
      return iterator(ptr_ + n);
    }

    __host__ __device__ iterator operator-(int n) const {
      return iterator(ptr_ - n);
    }

    __host__ __device__ ptrdiff_t operator-(const iterator &other) const {
      return ptr_ - other.ptr_;
    }

    // Equality comparison
    __host__ __device__ bool operator==(const iterator &other) const {
      return ptr_ == other.ptr_;
    }

    // Inequality comparison
    __host__ __device__ bool operator!=(const iterator &other) const {
      return ptr_ != other.ptr_;
    }
    __host__ __device__ bool operator<(const iterator &other) const {
      return ptr_ < other.ptr_;
    }

    // Pre-decrement operator
    __host__ __device__ iterator &operator--() {
      --ptr_;
      return *this;
    }

    // Post-decrement operator
    __host__ __device__ iterator operator--(int) {
      iterator tmp = *this;
      --(*this);
      return tmp;
    }

  private:
    T *ptr_;
  };

  // Iterator support using the new iterator class
  __host__ __device__ iterator begin() { return iterator(data_); }
  __host__ __device__ iterator end() { return iterator(data_ + size_); }

private:
  T *data_;         // Pointer to the data
  size_t size_;     // Number of elements
  size_t capacity_; // Capacity of the vector
};
