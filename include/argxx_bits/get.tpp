#include "argxx_bits/get.h"

#include <algorithm>
#include <stdexcept>

namespace argxx {

template <class Type, class Args>
constexpr Type& get(Args& args) {
  auto& id = typeid(Type);

  auto result = std::find_if(
    args.begin(), args.end(),
    [&id](auto& arg) { return typeid(*arg) == id; }
  );

  if (result == args.end()) throw std::invalid_argument("no argument of requested type found");
  return reinterpret_cast<Type&>(**result);
}

template <class Type, class Args>
constexpr Type& getOrDefault(Args& args) {
  try {
    return get<Type>(args);
  }  catch (std::invalid_argument& e) {
    args.push_back(new Type());
    return *reinterpret_cast<Type*>(&*args.back());
  }
}

}
