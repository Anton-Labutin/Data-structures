//
//  queue.hpp
//  Queue Implementation With List
//
//  Created by Лабутин Антон Александрович on 17.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include "../list/list/list.hpp"

template <typename T>
class Queue {
    List<T> queue;

    const List<T>&
    GetQueue() const;

    List<T>&
    GetQueue();

public:
    Queue() {}
    Queue(const T& newEl, size_t newSize = 1) throw(std::runtime_error);

    void
    Enqueue(const T&);

    T
    Dequeue() throw(std::runtime_error);

    bool
    Empty() const;

    size_t
    GetSize() const;
};

template <typename T>
Queue<T>::Queue(const T& newEl, size_t newSize) throw(std::runtime_error)
{
    if (newSize) {
        for (size_t i = 0; i < newSize; ++i) {
            GetQueue().PushBack(newEl);
        }
    } else {
        throw std::runtime_error("Queue(newEl, newSize) : newSize = 0");
    }
}

template <typename T>
const List<T>&
Queue<T>::GetQueue() const
{
    return queue;
}

template <typename T>
List<T>&
Queue<T>::GetQueue()
{
    return queue;
}

template <typename T>
void
Queue<T>::Enqueue(const T& key)
{
    GetQueue().PushBack(key);
}

template <typename T>
T
Queue<T>::Dequeue() throw(std::runtime_error)
{
    if (GetQueue().GetLen()) {
        T deleted = GetQueue().TopFront();
        GetQueue().PopFront();

        return deleted;
    } else {
        throw std::runtime_error("Dequeue : queue is empty");
    }
}

template <typename T>
size_t
Queue<T>::GetSize() const
{
    return GetQueue().GetLen();
}

template <typename T>
bool
Queue<T>::Empty() const
{
    return GetSize() == 0;
}

#endif /* queue_hpp */
