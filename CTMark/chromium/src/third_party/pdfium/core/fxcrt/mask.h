// Copyright 2021 The PDFium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CORE_FXCRT_MASK_H_
#define CORE_FXCRT_MASK_H_

#include <concepts>
#include <type_traits>

namespace fxcrt {

// Provides extremely strict type-checking on masks of enum class bitflags,
// for code where flags may not be passed consistently.
template <typename E>
class Mask {
 public:
  using UnderlyingType = typename std::underlying_type<E>::type;

  // Escape hatch for when value comes aross an API, say.
  static Mask FromUnderlyingUnchecked(UnderlyingType val) { return Mask(val); }

  constexpr Mask() = default;
  constexpr Mask(const Mask& that) = default;

  // NOLINTNEXTLINE(runtime/explicit)
  constexpr Mask(E val) : val_(static_cast<UnderlyingType>(val)) {}

  template <std::same_as<E>... Args>
  constexpr Mask(E first, Args... rest)
      : val_((static_cast<UnderlyingType>(first) | ... |
              static_cast<UnderlyingType>(rest))) {}

  explicit operator bool() const { return !!val_; }
  Mask operator~() const { return Mask(~val_); }
  constexpr Mask operator|(const Mask& that) const {
    return Mask(val_ | that.val_);
  }
  constexpr Mask operator&(const Mask& that) const {
    return Mask(val_ & that.val_);
  }
  constexpr Mask operator^(const Mask& that) const {
    return Mask(val_ ^ that.val_);
  }
  Mask& operator=(const Mask& that) {
    val_ = that.val_;
    return *this;
  }
  Mask& operator|=(const Mask& that) {
    val_ |= that.val_;
    return *this;
  }
  Mask& operator&=(const Mask& that) {
    val_ &= that.val_;
    return *this;
  }
  Mask& operator^=(const Mask& that) {
    val_ ^= that.val_;
    return *this;
  }
  friend constexpr bool operator==(const Mask&, const Mask&) = default;
  bool TestAll(const Mask& that) const {
    return (val_ & that.val_) == that.val_;
  }

  void Clear() { val_ = 0; }

  // Because ~ can't be applied to enum class without casting.
  void Clear(const Mask& that) { val_ &= ~that.val_; }

  // Escape hatch, usage should be minimized.
  UnderlyingType UncheckedValue() const { return val_; }

 private:
  explicit constexpr Mask(UnderlyingType val) : val_(val) {}

  UnderlyingType val_ = 0;
};

}  // namespace fxcrt

using fxcrt::Mask;

#endif  // CORE_FXCRT_MASK_H_
