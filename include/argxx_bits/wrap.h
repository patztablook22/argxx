#pragma once

#include <memory>

namespace argxx {

template <class T>
class Wrap {
  public:
    Wrap(const T& arg); // copy and delete copy upon destruction
    Wrap(T* arg);       // refer and don't delete
    Wrap(const Wrap<T>& other);
    Wrap();
    ~Wrap();

    inline T& operator*() const;
    inline T* operator->() const;

    const Wrap<T>& operator=(const Wrap<T>& other);
  
  private:
    T* ptr_;
    mutable bool free_;
};

}

#include "argxx_bits/wrap.tpp"