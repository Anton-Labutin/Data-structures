//
//  priority_queue.hpp
//  Priority Queue based on Unsorted Array
//
//  Created by Лабутин Антон Александрович on 27.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef priority_queue_hpp
#define priority_queue_hpp

#include "dynamic_array.hpp"
#include <utility>
#include <stdexcept>
#include <cstddef>

template <typename KeyType, typename ValueType, typename CompareType>
class PriorityQueue {
    Array<std::pair<KeyType, ValueType>> pqueue;

public:
    PriorityQueue() {}
    PriorityQueue(const KeyType& key, const ValueType& value);

    void
    Insert(const KeyType& key, const ValueType& value);

    void
    Extract() throw(std::runtime_error);

    ValueType&
    Get() throw(std::runtime_error);

    const ValueType&
    Get() const throw(std::runtime_error);

    size_t
    Size() const;

    bool
    Empty() const;
};

template <typename KeyType, typename ValueType, typename CompareType>
PriorityQueue<KeyType, ValueType, CompareType>::PriorityQueue(const KeyType& key, const ValueType& value)
{
    Insert(key, value);
}

template <typename KeyType, typename ValueType, typename CompareType>
void
PriorityQueue<KeyType, ValueType, CompareType>::Insert(const KeyType& key, const ValueType& value)
{
    pqueue.Add(std::make_pair(key, value));
}

template <typename KeyType, typename ValueType, typename CompareType>
void
PriorityQueue<KeyType, ValueType, CompareType>::Extract() throw(std::runtime_error)
{
    if (Size()) {
        if (Size() > 1) {
            size_t deletedIdx = 0;
            for (size_t idx = 1; idx < Size(); ++idx) {
                if (! CompareType()((pqueue.Get(deletedIdx)).first, (pqueue.Get(idx)).first)) {
                    deletedIdx = idx;
                }
            }

            pqueue.Remove(deletedIdx);
        } else {
            pqueue.Remove(Size() - 1);
        }
    } else {
        throw std::runtime_error("Extract(): priority queue is empty");
    }
}

template <typename KeyType, typename ValueType, typename CompareType>
ValueType&
PriorityQueue<KeyType, ValueType, CompareType>::Get() throw(std::runtime_error)
{
    if (Size()) {
        if (Size() > 1) {
            size_t deletedIdx = 0;
            for (size_t idx = 1; idx < Size(); ++idx) {
                if (! CompareType(pqueue.Get(deletedIdx).first, pqueue.Get(idx).first)) {
                    deletedIdx = idx;
                }
            }

            return pqueue.Get(deletedIdx).second;
        } else {
            return pqueue.Get(pqueue.Size() - 1).second;
        }
    } else {
        throw std::runtime_error("Get(): priority queue is empty");
    }
}

template <typename KeyType, typename ValueType, typename CompareType>
const ValueType&
PriorityQueue<KeyType, ValueType, CompareType>::Get() const throw(std::runtime_error)
{
    if (Size()) {
        if (Size() > 1) {
            size_t deletedIdx = 0;
            for (size_t idx = 1; idx < Size(); ++idx) {
                if (! CompareType(pqueue.Get(deletedIdx).first, pqueue.Get(idx).first)) {
                    deletedIdx = idx;
                }
            }

            return pqueue.Get(deletedIdx).second;
        } else {
            return pqueue.Get(pqueue.Size() - 1).second;
        }
    } else {
        throw std::runtime_error("Get(): priority queue is empty");
    }
}

template <typename KeyType, typename ValueType, typename CompareType>
size_t
PriorityQueue<KeyType, ValueType, CompareType>::Size() const
{
    return pqueue.Size();
}

template <typename KeyType, typename ValueType, typename CompareType>
bool
PriorityQueue<KeyType, ValueType, CompareType>::Empty() const
{
    return pqueue.Empty();
}

#endif /* priority_queue_hpp */
