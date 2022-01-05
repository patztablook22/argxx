#pragma once

#include <initializer_list>
#include <vector>

#include "argxx_bits/wrap.h"

namespace argxx {

template <class T>
using Args  = std::initializer_list<Wrap<T>>;

template <class T>
using Wraps = std::vector<Wrap<T>>;

}