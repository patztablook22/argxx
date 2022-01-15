#pragma once

#include "argxx_bits/wrap.h"
#include "argxx_bits/args.h"
#include "argxx_bits/debug.h"

#include <vector>

#include <iostream>

#define ARGXX_MAKE(obj)                                     \
  virtual obj* relocate() const = 0;                        \

#define ARGXX_INHERIT(obj, base)                            \
  base* relocate() const override {                         \
    obj* relocated = new (obj)(                             \
      std::move(*this)                                      \
    );                                                      \
    PP("relocation from %zx to %zx", this, relocated);      \
    return relocated;                                       \
  }                                                         \

