//
//  stack.hpp
//  Stack Implementation With List
//
//  Created by Лабутин Антон Александрович on 17.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include "dynamic_array.hpp"

template <typename T>
class Stack {
    Array<T> stack;

    Array<T>&
    GetStack();

    const Array<T>&
    GetStack() const;

public:
    Stack() {}
    Stack(const T& newEl, size_t newElCnt = 1);

    void
    Push(const T&);

    T&
    Top() throw(std::runtime_error);

    const T&
    Top() const throw(std::runtime_error);

    T
    Pop() throw(std::runtime_error);

    bool
    Empty() const;

    size_t
    GetSize() const;
};

template <typename T>
Stack<T>::Stack(const T& newEl, size_t newElCnt)
{
    for (size_t i = 0; i < newElCnt; ++i) {
        stack.Add(newEl);
    }
}

template <typename T>
Array<T>&
Stack<T>::GetStack()
{
    return stack;
}

template <typename T>
const Array<T>&
Stack<T>::GetStack() const
{
    return stack;
}

template <typename T>
void
Stack<T>::Push(const T& key)
{
    GetStack().Add(key);
}

template <typename T>
T&
Stack<T>::Top() throw(std::runtime_error)
{
    try {
        return GetStack().Get(GetStack().ElemCount() - 1);
    } catch (std::runtime_error& rte) {
        throw std::runtime_error("Top : stack is empty");
    }
}

template <typename T>
const T&
Stack<T>::Top() const throw(std::runtime_error)
{
    try {
        return GetStack().Get(GetStack().ElemCount() - 1);
    } catch (std::runtime_error& rte) {
        throw std::runtime_error("Top : stack is empty");
    }
}

template <typename T>
T
Stack<T>::Pop() throw(std::runtime_error)
{
    try {
        T deleted = Top();
        GetStack().Remove(GetStack().ElemCount() - 1);

        return deleted;
    } catch (std::runtime_error& rte) {
        throw std::runtime_error("Pop : stack is empty");
    }
}

template <typename T>
bool
Stack<T>::Empty() const
{
    return GetStack().ElemCount() == 0;
}

template <typename T>
size_t
Stack<T>::GetSize() const
{
    return GetStack().ElemCount();
}


#endif /* stack_hpp */
