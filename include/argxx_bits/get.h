#pragma once

namespace argxx {

template <class Type, class Args>
constexpr Type& get(Args& args);

}

#include "argxx_bits/get.tpp"