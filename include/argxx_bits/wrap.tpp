#include "argxx_bits/wrap.h"
#include "argxx_bits/debug.h"

#include <iostream>
using namespace std;

namespace argxx {

template <class T>
Wrap<T>::Wrap(const T& arg) 
  : ptr_(arg.relocate()),
    free_(true)
{
  PP("relocated");
}

template <class T>
Wrap<T>::Wrap(T* arg) 
  : ptr_(arg),
    free_(false)
{
  // std::cout << "linking arg " << arg << std::endl;
}

template <class T>
Wrap<T>::Wrap()
  : ptr_(nullptr)
  , free_(false)
{}

template <class T>
Wrap<T>::~Wrap() {
  if (free_) delete ptr_;
  // if (free_) relocated--;
  // if (free_) std::cout << "relocated: " << --relocated << std::endl;
}

template <class T>
Wrap<T>::Wrap(const Wrap<T>& other) {
  this->ptr_  = other.ptr_;
  this->free_ = other.free_;
  other.free_ = false;
}

template <class T>
T& Wrap<T>::operator*() const {
  return *ptr_;
}

template <class T>
T* Wrap<T>::operator->() const {
  return ptr_;
}

template <class T>
const Wrap<T>& Wrap<T>::operator=(const Wrap<T>& other) {
  PP("assignment");
  if (free_) delete ptr_;
  ptr_  = other.ptr_;
  free_ = other.free_;
  other.free_ = false;
  return *this;
}

}