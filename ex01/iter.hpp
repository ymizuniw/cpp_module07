#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void    iter(T array, const size_t size, F f){
    for (size_t i=0;i<size;i++){
        f(array[i]);
    }
}

#endif
