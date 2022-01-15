#pragma once

#define ARGXX_DEBUG false

#include <cstdio>

#define PP(format, ...)             \
  if (ARGXX_DEBUG) {                \
    printf(format "\n", ##__VA_ARGS__);  \
  }                                 \

