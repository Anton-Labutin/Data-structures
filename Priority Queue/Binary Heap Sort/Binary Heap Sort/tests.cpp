//
//  tests.cpp
//  Binary Heap Sort
//
//  Created by Лабутин Антон Александрович on 28.08.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include "tests.hpp"
#include "binary_heap_sort.hpp"
#include "test_runner.hpp"

#include <limits>

template <typename T>
class Greater {
public:
    bool
    operator () (const T& x, const T& y) const
    {
        return x > y;
    }

    T
    Limit() const
    {
        return std::numeric_limits<T>::max();
    }
};

template <typename T>
class Less {
public:
    bool
    operator () (const T& x, const T& y) const
    {
        return x < y;
    }

    T
    Limit() const
    {
        return std::numeric_limits<T>::min();
    }
};

void
TestBinaryHeapSort()
{
    {
        Array<int> empty;
        InPlaceBinaryHeapSort<int, Greater<int>>(empty);
        AssertEqual(empty.Size(), 0, "empty array");
    }
    {
        Array<int> arr1;
        arr1.Add(5);
        arr1.Add(4);
        arr1.Add(3);
        arr1.Add(2);
        arr1.Add(1);

        InPlaceBinaryHeapSort<int, Greater<int>>(arr1);
        AssertEqual(arr1.Size(), 5, "arr1 has size 5");
        AssertEqual(arr1.Get(0), 5, "arr1[0] = 5 with first Greater");
        AssertEqual(arr1.Get(1), 4, "arr1[1] = 4");
        AssertEqual(arr1.Get(2), 3, "arr1[2] = 3 with first Greater");
        AssertEqual(arr1.Get(3), 2, "arr1[3] = 2");
        AssertEqual(arr1.Get(4), 1, "arr1[4] = 1");

        InPlaceBinaryHeapSort<int, Less<int>>(arr1);
        AssertEqual(arr1.Size(), 5, "arr1 has size 5");
        AssertEqual(arr1.Get(0), 1, "arr1[0] = 1");
        AssertEqual(arr1.Get(1), 2, "arr1[1] = 2");
        AssertEqual(arr1.Get(2), 3, "arr1[2] = 3");
        AssertEqual(arr1.Get(3), 4, "arr1[3] = 4 ");
        AssertEqual(arr1.Get(4), 5, "arr1[4] = 5");

        InPlaceBinaryHeapSort<int, Less<int>>(arr1);
        AssertEqual(arr1.Size(), 5, "arr1 has size 5");
        AssertEqual(arr1.Get(0), 1, "arr1[0] = 1");
        AssertEqual(arr1.Get(1), 2, "arr1[1] = 2");
        AssertEqual(arr1.Get(2), 3, "arr1[2] = 3");
        AssertEqual(arr1.Get(3), 4, "arr1[3] = 4");
        AssertEqual(arr1.Get(4), 5, "arr1[4] = 5");

        InPlaceBinaryHeapSort<int, Greater<int>>(arr1);
        AssertEqual(arr1.Size(), 5, "arr1 has size 5");
        AssertEqual(arr1.Get(0), 5, "arr1[0] = 5 with second Greater");
        AssertEqual(arr1.Get(1), 4, "arr1[1] = 4");
        AssertEqual(arr1.Get(2), 3, "arr1[2] = 3");
        AssertEqual(arr1.Get(3), 2, "arr1[3] = 2");
        AssertEqual(arr1.Get(4), 1, "arr1[4] = 1");
    }
    {
        Array<int> arr2;
        arr2.Add(3);
        arr2.Add(2);
        arr2.Add(5);
        arr2.Add(1);
        arr2.Add(4);

        InPlaceBinaryHeapSort<int, Less<int>>(arr2);
        AssertEqual(arr2.Size(), 5, "arr2 has size 5");
        AssertEqual(arr2.Get(0), 1, "arr2[0] = 1");
        AssertEqual(arr2.Get(1), 2, "arr2[1] = 2");
        AssertEqual(arr2.Get(2), 3, "arr2[2] = 3");
        AssertEqual(arr2.Get(3), 4, "arr2[3] = 4");
        AssertEqual(arr2.Get(4), 5, "arr2[4] = 5");

        InPlaceBinaryHeapSort<int, Greater<int>>(arr2);
        AssertEqual(arr2.Size(), 5, "arr2 has size 5");
        AssertEqual(arr2.Get(0), 5, "arr2[0] = 5");
        AssertEqual(arr2.Get(1), 4, "arr2[1] = 4");
        AssertEqual(arr2.Get(2), 3, "arr2[2] = 3");
        AssertEqual(arr2.Get(3), 2, "arr2[3] = 2");
        AssertEqual(arr2.Get(4), 1, "arr2[4] = 1");
    }
}

void
TestAll()
{
    TestRunner tr;

    tr.RunTest(TestBinaryHeapSort, "TestBinaryHeapSort");
}
