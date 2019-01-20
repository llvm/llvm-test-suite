//===--- template2.cpp --- Test Cases for Bit Accurate Types --------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is a test for template classes.
//
//===----------------------------------------------------------------------===//


#include <stdio.h>

typedef int __attribute__ ((bitwidth(26))) int26;

template <typename T>
  class MyQueue
  {
    T data[128];
    unsigned int idx;
    public:
    MyQueue(): idx(0){}
    void Add(T const &);
    void Remove();
    void Print();
  };

template <typename T> void MyQueue<T> ::Add(T const &d)
{
  if(idx < 128 ){
    data[idx] = d;
    idx += 1;
  }
}

template <typename T> void MyQueue<T>::Remove()
{
  if(idx != 0)
    idx -= 1;
    
}

template <typename T> void MyQueue<T>::Print()
{
  for(unsigned int i = 0; i< idx; i++){
    int m = data[i];
    printf("%d, ", m);
  }
  printf("\n");
}

int main()
{
  MyQueue<int26> q;

  q.Add(-1);
  q.Add(2);
  q.Print();

  q.Remove();
  q.Print();

  return 0;
}
