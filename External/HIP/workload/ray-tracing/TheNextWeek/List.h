#pragma once
//==============================================================================================
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//==============================================================================================

#include <iostream>
#include <utility> // For std::forward

template <typename T> class List {
private:
  struct Node {
    T data;
    Node *next;

    // Constructor for the data member
    template <typename... Args>
    __host__ __device__ Node(Args &&...args)
        : data(std::forward<Args>(args)...), next(nullptr) {}

    // Default constructor
    __host__ __device__ Node() : data(T()), next(nullptr) {}
  };

  Node *head;

  __host__ __device__ void copyList(const List &other) {
    Node *currentOther = other.head;
    Node **currentThis = &head;

    while (currentOther != nullptr) {
      *currentThis = new Node(currentOther->data);
      currentThis = &((*currentThis)->next);
      currentOther = currentOther->next;
    }
  }

public:
  // Forward iterator
  class iterator {
  private:
    Node *node;

  public:
    __host__ __device__ iterator() : node(nullptr) {} // Default constructor

    __host__ __device__ iterator(Node *n) : node(n) {}

    __host__ __device__ iterator &operator++() {
      node = node->next;
      return *this;
    }

    __host__ __device__ bool operator==(const iterator &other) const {
      return node == other.node;
    }

    __host__ __device__ bool operator!=(const iterator &other) const {
      return node != other.node;
    }

    __host__ __device__ T &operator*() const { return node->data; }

    __host__ __device__ T *operator->() const { return &(node->data); }
  };

  __host__ __device__ List() : head(nullptr) {}

  __host__ __device__ List(const List &other) : head(nullptr) {
    copyList(other);
  }

  __host__ __device__ ~List() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }

  __host__ __device__ List &operator=(const List &other) {
    if (this != &other) {
      Node *current = head;
      while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
      }

      head = nullptr;
      copyList(other);
    }
    return *this;
  }

  __host__ __device__ iterator begin() const { return iterator(head); }
  __host__ __device__ iterator end() const { return iterator(nullptr); }

  __host__ __device__ T &back() {
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    return current->data;
  }

  template <typename... Args>
  __host__ __device__ void emplace_back(Args &&...args) {
    Node **current = &head;
    while (*current != nullptr) {
      current = &((*current)->next);
    }
    *current = new Node(std::forward<Args>(args)...);
  }

  __host__ __device__ void append(T value) { emplace_back(std::move(value)); }

  __host__ __device__ bool remove(T value) {
    if (head == nullptr)
      return false;

    if (head->data == value) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return true;
    }

    Node *current = head;
    while (current->next != nullptr) {
      if (current->next->data == value) {
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
      }
      current = current->next;
    }

    return false;
  }

  __host__ __device__ void print() const {
    for (T &value : *this) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
};
