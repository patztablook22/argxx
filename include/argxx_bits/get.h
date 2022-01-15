#pragma once

namespace argxx {

template <class Type, class Args>
constexpr Type& get(Args& args);

template <class Type, class Args>
constexpr Type& getOrDefault(Args& args);

}

#include "argxx_bits/get.tpp"
