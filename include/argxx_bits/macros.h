#pragma once

#include "argxx_bits/wrap.h"
#include "argxx_bits/args.h"

#include <vector>

#define ARGXX_MAKE(obj)                                     \
  virtual obj* relocate() const = 0;                        \

#define ARGXX_INHERIT(obj, base)                            \
  base* relocate() const override {                         \
    return (obj *) new (obj)(                               \
      std::move(*this)                                      \
    );                                                      \
  }                                                         \

