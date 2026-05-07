#include "Array.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

// The "Empty Array" means size zero array.
template <typename T> Array<T>::Array() : size_(0) {
  std::cout << "Array Default Constructor Called" << std::endl;
  value_ = new T[0]();
}

template <typename T>
Array<T>::Array(unsigned int n):size_(n){
  std::cout << "Array Parameterized Constructor Called" << std::endl;
  value_ = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T> &other): size_(other.size())
{
  value_ = new T[size_]();
  for (unsigned int i = 0; i < size_; i++) {
    value_[i] = other.value_[i];
  }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other){
  if (this == &other)
    return *this;
  delete[] value_;
  unsigned int arrSize = other.size();
  value_ = new T[arrSize];
  for (unsigned int i = 0; i < arrSize; i++) {
    value_[i] = other.value_[i];
  }
    size_=other.size();
    return (*this);
}

template <typename T>
Array<T>::~Array(){
  std::cout << "Array Default Destructor Called" << std::endl;
  delete[] value_;
}

template <typename T>
T &Array<T>::operator[](const unsigned int index) const
{
    if (size_<=index)
      throw(std::exception());
    return (value_[index]);
}

template <typename T>
unsigned int Array<T>::size() const{
    return (size_);
}
