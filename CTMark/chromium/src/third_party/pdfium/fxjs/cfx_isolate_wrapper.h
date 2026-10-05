// Copyright 2017 The PDFium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FXJS_CFX_ISOLATE_WRAPPER_H_
#define FXJS_CFX_ISOLATE_WRAPPER_H_

#include <stddef.h>

#include <vector>

#include "core/fxcrt/fx_string.h"
#include "core/fxcrt/unowned_ptr.h"
#include "v8/include/v8-forward.h"

class CFX_IsolateWrapper {
 public:
  explicit CFX_IsolateWrapper(v8::Isolate* pIsolate);
  virtual ~CFX_IsolateWrapper();

  v8::Isolate* GetIsolate() const { return isolate_; }

  v8::Local<v8::Value> NewNull();
  v8::Local<v8::Value> NewUndefined();
  v8::Local<v8::Array> NewArray();
  v8::Local<v8::Object> NewObject();
  v8::Local<v8::Number> NewNumber(int number);
  v8::Local<v8::Number> NewNumber(double number);
  v8::Local<v8::Number> NewNumber(float number);
  v8::Local<v8::Boolean> NewBoolean(bool b);
  v8::Local<v8::String> NewString(ByteStringView str);
  v8::Local<v8::String> NewString(WideStringView str);
  v8::Local<v8::Date> NewDate(double d);

  int ToInt32Reentrant(v8::Local<v8::Value> pValue);
  bool ToBooleanReentrant(v8::Local<v8::Value> pValue);
  double ToDoubleReentrant(v8::Local<v8::Value> pValue);
  WideString ToWideStringReentrant(v8::Local<v8::Value> pValue);
  ByteString ToByteStringReentrant(v8::Local<v8::Value> pValue);
  v8::Local<v8::Object> ToObjectReentrant(v8::Local<v8::Value> pValue);
  v8::Local<v8::Array> ToArrayReentrant(v8::Local<v8::Value> pValue);

  // Arrays.
  size_t GetArrayLength(v8::Local<v8::Array> pArray);
  v8::Local<v8::Value> GetArrayElementReentrant(v8::Local<v8::Array> pArray,
                                                size_t index);
  void PutArrayElementReentrant(v8::Local<v8::Array> pArray,
                                size_t index,
                                v8::Local<v8::Value> pValue);

  // Objects.
  std::vector<WideString> GetObjectPropertyNamesReentrant(
      v8::Local<v8::Object> pObj);
  v8::Local<v8::Value> GetObjectPropertyReentrant(
      v8::Local<v8::Object> pObj,
      ByteStringView bsUTF8PropertyName);
  void PutObjectPropertyReentrant(v8::Local<v8::Object> pObj,
                                  ByteStringView bsUTF8PropertyName,
                                  v8::Local<v8::Value> pValue);

 protected:
  void SetIsolate(v8::Isolate* isolate) { isolate_ = isolate; }
  void DisposeIsolate();

 private:
  UnownedPtr<v8::Isolate> isolate_;
};

// Use with std::unique_ptr<v8::Isolate> to dispose of isolates correctly.
struct CFX_V8IsolateDeleter {
  void operator()(v8::Isolate* ptr);
};

#endif  // FXJS_CFX_ISOLATE_WRAPPER_H_
