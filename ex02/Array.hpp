#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *value_;
        unsigned int size_;
    public:
        Array(void);
        Array(const unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        T &operator[](unsigned int index) const;
        ~Array(void);
        unsigned int size(void) const;
};

#include "Array.tpp"

#endif
