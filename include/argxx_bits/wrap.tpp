#include "argxx_bits/wrap.h"
#include <iostream>

using namespace std;

int counter = 0;

namespace argxx {

template <class T>
Wrap<T>::Wrap(const T& arg) 
  : ptr_(arg.relocate()),
    free_(true)
{}

template <class T>
Wrap<T>::Wrap(T* arg) 
  : ptr_(arg),
    free_(false)
{}

template <class T>
Wrap<T>::~Wrap() {
  if (free_) delete ptr_;
}

template <class T>
Wrap<T>::Wrap(const Wrap<T>& other) {
  // cout << "copy " << counter++ << endl;
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

}