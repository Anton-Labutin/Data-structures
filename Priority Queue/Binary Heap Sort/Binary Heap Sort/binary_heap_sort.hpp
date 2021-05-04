//
//  binary_heap_sort.hpp
//  Binary Heap Sort
//
//  Created by Лабутин Антон Александрович on 28.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#ifndef binary_heap_sort_hpp
#define binary_heap_sort_hpp

#include <algorithm>

#include "binary_heap.hpp"

template <typename ValueType, typename CompareType>
void
BinaryHeapSort(Array<ValueType>& array)
{
    BinaryHeap<ValueType, CompareType> bheap;

    for (size_t idx = 0; idx < array.Size(); ++idx) {
        bheap.Insert(array.Get(idx));
    }

    for (size_t idx = 0; idx < array.Size(); ++idx) {
        array.Set(idx, bheap.Get());
        bheap.Extract();
    }
}

template <typename ValueType, typename CompareType>
void
SiftDown(Array<ValueType>& array, size_t idx, size_t maxSize)
{
    size_t nextIdx = idx;

    if (2 * idx + 1 < maxSize) {
        if (! CompareType()(array.Get(2 * idx + 1), array.Get(idx))) {
            nextIdx = 2 * idx + 1;
        }
        if (2 * (idx + 1) < maxSize) {
            if (! CompareType()(array.Get(2 * idx + 2), array.Get(nextIdx))) {
                nextIdx = 2 * (idx + 1);
            }
        }
    }

    if (idx != nextIdx) {
        std::swap(array.Get(idx), array.Get(nextIdx));
        SiftDown<ValueType, CompareType>(array, nextIdx, maxSize);
    }
}

template <typename ValueType, typename CompareType>
void
BuildHeap(Array<ValueType>& array)
{
    if (array.Size() > 2) {
        for (size_t i = (array.Size() / 2) - 1; i > 0; --i) {
            SiftDown<ValueType, CompareType>(array, i, array.Size());
        }
    }

    if (array.Size()) {
        SiftDown<ValueType, CompareType>(array, 0, array.Size());
    }
}

template <typename ValueType, typename CompareType>
void
InPlaceBinaryHeapSort(Array<ValueType>& array)
{
    BuildHeap<ValueType, CompareType>(array);

    for (size_t i = array.Size(); i > 1; --i) {
        std::swap(array.Get(0), array.Get(i - 1));
        SiftDown<ValueType, CompareType>(array, 0, i - 1);
    }

    if (array.Size()) {
        SiftDown<ValueType, CompareType>(array, 0, 1);
    }
}

#endif /* binary_heap_sort_hpp */
