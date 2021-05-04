//
//  binary_heap.hpp
//  Binary Heap
//
//  Created by Лабутин Антон Александрович on 27.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef binary_heap_hpp
#define binary_heap_hpp

#include <limits>
#include <algorithm>

#include "dynamic_array.hpp"

template <typename Type, typename CopmareType>
class BinaryHeap {
    Array<Type> bheap;

    void
    SiftUp(size_t nodeidx) throw(std::out_of_range);

    void
    SiftDown(size_t nodeIdx) throw(std::out_of_range);

    void
    Set(size_t nodeIdx, const Type& value) throw(std::out_of_range);

public:
    BinaryHeap() {}
    BinaryHeap(const Type& value);

    size_t
    ParentNodeIdx(size_t nodeIdx) const throw(std::out_of_range);

    size_t
    LessNodeIdx(size_t nodeIdx) const throw(std::out_of_range);

    size_t
    GreaterNodeIdx(size_t nodeIdx) const throw(std::out_of_range);

    void
    Insert(const Type& value);

    void
    Extract();

    void
    Delete(size_t idx) throw(std::out_of_range);

    Type&
    Get(size_t nodeIdx = 0) throw(std::out_of_range);

    const Type&
    Get(size_t nodeIdx = 0) const throw(std::out_of_range);

    size_t
    Size() const;
};

template <typename Type, typename CompareType>
size_t
BinaryHeap<Type, CompareType>::ParentNodeIdx(size_t nodeIdx) const throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        return (nodeIdx % 2 ? nodeIdx / 2 : ( nodeIdx ? nodeIdx / 2 - 1 : nodeIdx / 2));
    } else {
        throw std::out_of_range("ParentNodeIdx(nodeIdx) : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
size_t
BinaryHeap<Type, CompareType>::GreaterNodeIdx(size_t nodeIdx) const throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        return 2 * nodeIdx + 2;
    } else {
        throw std::out_of_range("GreaterNodeIdx(nodeIdx) : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
size_t
BinaryHeap<Type, CompareType>::LessNodeIdx(size_t nodeIdx) const throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        return 2 * nodeIdx + 1;
    } else {
        throw std::out_of_range("LessNodeIdx(nodeIdx) : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
void
BinaryHeap<Type, CompareType>::Insert(const Type& value)
{
    bheap.Add(value);
    SiftUp(Size() - 1);
}

template <typename Type, typename CompareType>
void
BinaryHeap<Type, CompareType>::Set(size_t nodeIdx, const Type& value) throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        bheap.Set(nodeIdx, value);
    } else {
        throw std::out_of_range("Set(nodeIdx, value) : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
BinaryHeap<Type, CompareType>::BinaryHeap(const Type& value)
{
    Insert(value);
}

template <typename Type, typename CompareType>
void
BinaryHeap<Type, CompareType>::Extract()
{
    Set(0, Get(Size() - 1));
    bheap.Remove(Size() - 1);

    if (Size()) {
        SiftDown(0);
    }
}

template <typename Type, typename CompareType>
Type&
BinaryHeap<Type, CompareType>::Get(size_t nodeIdx) throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        return bheap.Get(nodeIdx);
    } else {
        throw std::out_of_range("Get(nodeIdx) : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
const Type&
BinaryHeap<Type, CompareType>::Get(size_t nodeIdx) const throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        return bheap.Get(nodeIdx);
    } else {
        throw std::out_of_range("Get(nodeIdx) const : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
void
BinaryHeap<Type, CompareType>::Delete(size_t nodeIdx) throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        Set(nodeIdx, CompareType().Limit());
        SiftUp(nodeIdx);
        Extract();
    } else {
        throw std::out_of_range("Delete(nodeIdx) : nodeIdx is out of range");
    }
}

template <typename Type, typename CompareType>
void
BinaryHeap<Type, CompareType>::SiftUp(size_t nodeIdx) throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        while (nodeIdx &&
               ! CompareType()(Get(ParentNodeIdx(nodeIdx)),
                               Get(nodeIdx))
               ) {
            std::swap(Get(ParentNodeIdx(nodeIdx)), Get(nodeIdx));
            nodeIdx = ParentNodeIdx(nodeIdx);
        }
    } else {
        throw std::out_of_range("SiftUp(nodeIdx) : nodeIdx is out of range");

    }
}

template <typename Type, typename CompareType>
size_t
BinaryHeap<Type, CompareType>::Size() const
{
    return bheap.Size();
}

template <typename Type, typename CompareType>
void
BinaryHeap<Type, CompareType>::SiftDown(size_t nodeIdx) throw(std::out_of_range)
{
    if (nodeIdx < Size()) {
        size_t comparedIdx = nodeIdx;

        size_t lessNodeIdx = LessNodeIdx(nodeIdx);
        if (lessNodeIdx < Size()
            && CompareType()(Get(lessNodeIdx), Get(comparedIdx))
            ) {
            comparedIdx = lessNodeIdx;
        }

        size_t greaterNodeIdx = GreaterNodeIdx(nodeIdx);
        if (greaterNodeIdx < Size()
            && CompareType()(Get(greaterNodeIdx), Get(comparedIdx))
            ) {
            comparedIdx = greaterNodeIdx;
        }

        if (nodeIdx != comparedIdx) {
            std::swap(Get(nodeIdx), Get(comparedIdx));
            SiftDown(comparedIdx);
        }
    } else {
        throw std::out_of_range("SiftDown(nodeIdx) : nodeIdx is out of range");
    }
}

#endif /* binary_heap_hpp */
