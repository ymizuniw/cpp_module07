#ifndef ITER_HPP
#define ITER_HPP

/*The meaning of "The function ... may take its argument by const reference or
   non-const reference" is that T &array may be both const/non-const qualifiers.
*/
#include <cstddef>

template <typename T, typename F> void iter(T &array, const size_t size, F f) {
  for (size_t i = 0; i < size; i++) {
    f(array[i]);
  }
}

#endif
