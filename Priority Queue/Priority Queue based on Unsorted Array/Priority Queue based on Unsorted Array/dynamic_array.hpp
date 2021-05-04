//
//  array.hpp
//  Array
//
//  Created by Лабутин Антон Александрович on 14.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <new>

template <typename T>
class Array {
    T *array = nullptr;
    size_t maxSize = 0;
    size_t size = 0;

    void
    Resize(size_t) throw(std::invalid_argument, std::bad_alloc);

    T*
    GetArray();

public:
    Array(size_t size = 0) throw(std::bad_alloc);
    Array(size_t, T) throw(std::bad_alloc, std::invalid_argument);

    Array(const Array<T>&);

    Array<T>&
    operator = (const Array<T>&);

    void
    Add(const T&)  throw(std::invalid_argument, std::bad_alloc);

    T
    Remove(size_t) throw(std::out_of_range, std::runtime_error);

    T&
    Get(size_t) throw(std::out_of_range, std::runtime_error);

    const T&
    Get(size_t) const throw(std::out_of_range, std::runtime_error);

    void
    Set(size_t idx, const T& value) throw(std::out_of_range);

    size_t
    Size() const;

    size_t
    MaxSize() const;

    bool
    Empty() const;

    T&
    operator [] (size_t) throw(std::out_of_range, std::runtime_error);

    ~Array();
};

template <typename T>
T*
Array<T>::GetArray()
{
    return array;
}

template <typename T>
Array<T>::Array(size_t size) throw(std::bad_alloc)
{
    if (size) {
        maxSize = size;
        array = new T[size];
    }
}

template <typename T>
Array<T>::Array(size_t size, T initValue) throw(std::bad_alloc, std::invalid_argument)
{
    if (size) {
        maxSize = size;
        array = new T[size];

        size = size;
        for (size_t i = 0; i < size; ++i) {
            array[i] = initValue;
        }
    } else {
        throw std::invalid_argument("Array(size, initValue) : size = 0");
    }
}

template <typename T>
Array<T>::Array(const Array<T>& copy)
{
    for (size_t i = 0; i < copy.Size(); ++i) {
        Add(copy.Get(i));
    }
}

template <typename T>
Array<T>&
Array<T>::operator = (const Array<T>& copy)
{
    Resize(copy.Size());

    for (size_t i = 0; i < copy.Size(); ++i) {
        GetArray()[i] = copy[i];
    }
}

template <typename T>
void
Array<T>::Resize(size_t newSize) throw(std::invalid_argument, std::bad_alloc)
{
    if (newSize) {
        T *new_array = new T [newSize];

        for (size_t i = 0; i < maxSize; ++i) {
            new_array[i] = array[i];
        }

        maxSize = newSize;
        if (array) {
            delete[] array;
        }
        array = new_array;
    } else {
        throw std::invalid_argument("Resize : newSize = 0");
    }
}

template <typename T>
void
Array<T>::Add(const T& new_el) throw(std::invalid_argument, std::bad_alloc)
{
    if (size + 1 > maxSize) {
        Resize(maxSize ? 2 * maxSize : 2);
    }

    array[size++] = new_el;
}

template <typename T>
T
Array<T>::Remove(size_t idx) throw(std::out_of_range, std::runtime_error)
{
    if (maxSize == 0) {
        throw std::runtime_error("Remove: array is empty");
    }

    if (idx < size) {
        T deleted = array[idx];

        for (size_t i = idx; i + 1 < size; ++i) {
            array[i] = array[i + 1];
        }
        --size;

        return deleted;
    } else {
        throw std::out_of_range("Invalid idx: idx > size");
    }
}



template <typename T>
T&
Array<T>::Get(size_t idx) throw(std::out_of_range, std::runtime_error)
{
    if (maxSize == 0) {
        throw std::runtime_error("Get: array is empty");
    }

    if (idx < size) {
        return array[idx];
    } else {
        throw std::out_of_range("Get: invalid idx");
    }
}

template <typename T>
const T&
Array<T>::Get(size_t idx) const throw(std::out_of_range, std::runtime_error)
{
    if (maxSize == 0) {
        throw std::runtime_error("Get: array is empty");
    }

    if (idx < size) {
        return array[idx];
    } else {
        throw std::out_of_range("Get: invalid idx");
    }
}

template <typename T>
void
Array<T>::Set(size_t idx, const T& value) throw(std::out_of_range)
{
    if (idx < Size()) {
        array[idx] = value;
    } else {
        throw std::out_of_range("Set(idx, value) : idx is out of range");
    }
}

template <typename T>
T&
Array<T>::operator [](size_t idx) throw(std::out_of_range, std::runtime_error)
{
    if (maxSize == 0) {
        throw std::runtime_error("Get: array is empty");
    }

    if (idx < size) {
        return array[idx];
    } else {
        throw std::out_of_range("Operator [] : invalid idx");
    }
}

template <typename T>
size_t
Array<T>::MaxSize() const
{
    return maxSize;
}

template <typename T>
size_t
Array<T>::Size() const
{
    return size;
}

template <typename T>
bool
Array<T>::Empty() const
{
    return Size() == 0;
}

template <typename T>
Array<T>::~Array()
{
    if (array) {
        delete [] array;
    }
}

template <typename T>
std::ostream&
operator << (std::ostream& output, const Array<T>& array)
{
    bool isFirst = true;
    for (size_t i = 0; i < array.Size(); ++i) {
        if (! isFirst) {
            output << " ";
        }

        output << array.Get(i);
        isFirst = false;
    }
    output << std::endl;

    return output;
}

#endif /* array_hpp */
